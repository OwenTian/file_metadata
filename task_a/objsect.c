#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include "bfd.h"
#include "string.h"


char * toArray(int number)
{

	// printf("number given to toArray is %d\n", number);

	if (number == 0) {

		// printf("inside number is 0! \n");
		char* numberArray = calloc(1, sizeof(char));
		numberArray[0] = 48;
		// printf("numberArray[0] is %d\n", numberArray[0]);
		return numberArray;
	}

    int n = log10(number) + 1;
    
    // printf("n is %d\n", n);


    int i;
  	char* numberArray = calloc(n, sizeof(char));


    for ( i = n-1; i >= 0; --i, number /= 10 )
    {	
    	//printf("number is %d\n", number);

    	numberArray[i] = number % 10;
        // printf("original value: %d\n", numberArray[i]);
        numberArray[i] = numberArray[i] + 48;
		// printf("inside loop of toArray: %d\n", numberArray[i]);

    }

    // printf("%d\n", numberArray[1]);
    return numberArray;
}



// prints an integer, then a newline
void my_print_int(int input) {

	const char newline[] = "\n";
	char * pointer = toArray(input);

	// printf("input to my_print_int is %d\n", input);
	// printf("strlen of pointer is %d\n", strlen(pointer));

	write(1, pointer, strlen(pointer));
	write(1, newline, sizeof(newline) - 1);
}


// prints text, then a newline if 1 is passed in
void my_print_string(const char *text, int line) {

	const char newline[] = "\n";
	write(1, text, strlen(text));


	if (line == 1) {

		write(1, newline, sizeof(newline) - 1);

	}
	

}



void findSectionData (abfd, sect, obj) 

bfd *abfd;
asection *sect;
void *obj;

{

	int address = sect->vma;
	int raw_size = sect->rawsize;
	int cooked_size = sect->size;
	int offset = sect->filepos;
	const char *name = sect->name;

	my_print_string("section name: ", 0);
	my_print_string(name, 1);
	my_print_string("address: ", 0);
	my_print_int(address);
	my_print_string("raw size: ", 0);
	my_print_int(raw_size);
	my_print_string("cooked size: ", 0);
	my_print_int(cooked_size);
	my_print_string("offset: ", 0);
	my_print_int(offset);

/*
	printf("address is %d\n", address);
	printf("raw size is %04x\n", raw_size);
	printf("cooked size is %04x\n", cooked_size);
	printf("offset is  %d\n", offset);
*/


}




void findSections (abfd, func) 

bfd *abfd;
void (*func) (bfd *abfd, asection *sect, void *obj);

{
	// printf("inside findsections\n");

	bfd_map_over_sections(abfd, func, NULL);

	// printf("findsections is over\n");
}




