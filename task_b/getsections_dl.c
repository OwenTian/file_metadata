#include <stdio.h>
#include <stdlib.h>
#include "objsect.h"
#include "objsym.h"
#include "bfd.h"
#include <string.h>
#include <dlfcn.h>


#define rdtsc(x) __asm__ __volatile__("rdtsc \n\t" : "=A" (*(x)))




int main(int argc, char* argv[]) {

	bfd *obj, *objout;
	bfd_init();
	unsigned int h;


	unsigned long long start, finish, difference;

	rdtsc(&start);

	void * lib_handle;
	lib_handle = dlopen("/home/ugrad/spheal/cs410/task_b/libobjdata.so", RTLD_LAZY);
	if (!lib_handle) {
	    fprintf(stderr, "Error during dlopen(): %s\n", dlerror());
	    exit(1);
	}

	rdtsc(&finish);
	dlclose(lib_handle); // ?


	difference = finish - start;


	printf("%llu\n", start);
	printf("%llu\n", finish);
	printf("%llu\n", difference);

	int x = 'a' + 15;
	printf("%d\n", x);




	if (argc != 2) {

		printf("not enough arguments!\n");
	}


	else {

		// printf(argv[1]);
		// printf("\n");


		obj = bfd_openr(argv[1], "elf64-x86-64");

		if (!obj) {

			bfd_perror("open failure\n");
		}

		if (!bfd_check_format(obj, bfd_object)) {

			printf("format error!\n");

		}

		else {


			findSections(obj, findSectionData);

			// h = number_of_sections(obj);
			// printf("number of sections is %d\n", h);

		}



	}

	
	return 0;


}

