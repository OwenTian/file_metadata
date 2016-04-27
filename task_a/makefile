all: getsections getsyms

getsections: objsect.o libobjdata.a 
	gcc -o getsections.o getsections.c -L. -lobjdata -lbfd -lm

getsyms: objsym.o libobjdata.a
	gcc -o getsyms.o getsyms.c -L. -lobjdata -lbfd -lm

objsect.o: objsect.c
	gcc -c -o objsect.o objsect.c -lbfd -lm

objsym.o: objsym.c
	gcc -c -o objsym.o objsym.c -lbfd -lm

libobjdata.a: objsect.o objsym.o
	ar rs libobjdata.a objsect.o objsym.o
	ranlib libobjdata.a

clean:
	rm *o
	