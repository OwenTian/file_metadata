all: getsections_dl getsyms_dl


getsections_dl: objsect.o libobjdata.so
	gcc -fPIC -o getsections_dl.o getsections_dl.c -L. -lobjdata -lbfd -lm

getsyms_dl: objsym.o libobjdata.so
	gcc -fPIC -o getsyms_dl.o getsyms_dl.c -L. -lobjdata -lbfd -lm

objsect.o: objsect.c
	gcc -c -fPIC -o objsect.o objsect.c -lbfd -lm

objsym.o: objsym.c
	gcc -c -fPIC -o objsym.o objsym.c -lbfd -lm

libobjdata.so: objsect.o objsym.o
	gcc -shared -o libobjdata.so objsect.o objsym.o -lbfd
	export LD_LIBRARY_PATH=/home/ugrad/spheal/cs410:$LD_LIBRARY_PATH

clean:
	rm *o
	