#include <stdio.h>
#include <stdlib.h>
#include "objsect.h"
#include "objsym.h"
#include "bfd.h"
#include <string.h>


int main(int argc, char* argv[]) {

	bfd *obj, *objout;
	bfd_init();



	if (argc != 2) {

		printf("not enough arguments!\n");
	}


	else {

		printf(argv[1]);
		printf("\n");


		obj = bfd_openr(argv[1], "elf64-x86-64");

		if (!obj) {

			bfd_perror("open failure\n");
		}

		if (!bfd_check_format(obj, bfd_object)) {

			printf("format error!\n");

		}

		else {


			findSymbols(obj);
			

		}


	}


	
	return 0;

}