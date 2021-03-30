CC = g++
exe_file = catalog_prog
$(exe_file):catalog.o prog.o
	 $(CC) catalog.o prog.o -o $(exe_file)
mult_div.o: catalog.cpp
	$(CC) -c catalog.cpp
prog.o: prog.cpp
	$(CC) -c prog.cpp
clean:
	rm -f *.out *.o $(exe_file)
