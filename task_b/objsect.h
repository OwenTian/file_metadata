#include "bfd.h"


void findSectionData (bfd *abfd, asection *sect, void *obj);

char * toArray(int number);

void my_print_int(int input);

void my_print_string(const char *text, int line);

void findSections (bfd *abfd, void (*func) (bfd *abfd, asection *sect, void *obj));