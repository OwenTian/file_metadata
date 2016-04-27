#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include "bfd.h"
#include "string.h"
#include "objsect.h"




void findSymbols (bfd *abfd) {

	long storage_needed;
	asymbol **symbol_table;
	long number_of_symbols;
	long i;

	storage_needed = bfd_get_symtab_upper_bound (abfd);

	if (storage_needed < 0) {
		printf("Storage is less than 0. \n");
	}

	if (storage_needed == 0) {

		printf("Storage needed is 0. \n");
		return;
	}

	symbol_table = malloc (storage_needed);

	number_of_symbols = bfd_canonicalize_symtab (abfd, symbol_table);

	if (number_of_symbols < 0) {

		printf("number of symbols is less than 0! \n");
	}


	for (i = 0; i < number_of_symbols; i++) {

		my_print_string("symbol: ", 0);
		my_print_string(symbol_table[i]->name, 1);

		my_print_string("address: ", 0);
		my_print_int(symbol_table[i]->value);

		// printf("address is %d\n", symbol_table[i]->value); //use %p for hex
	}

}