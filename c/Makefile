compile: main.o utilities.o add_BigInt.o BigInt_utilities.o initialize_BigInt.o multiply_BigInt.o subtract_BigInt.o tobinary_BigInt.o
	gcc main.o utilities.o add_BigInt.o BigInt_utilities.o initialize_BigInt.o multiply_BigInt.o subtract_BigInt.o tobinary_BigInt.o -o main
	make clean

cnr: main.o utilities.o add_BigInt.o BigInt_utilities.o initialize_BigInt.o multiply_BigInt.o subtract_BigInt.o tobinary_BigInt.o
	gcc main.o utilities.o add_BigInt.o BigInt_utilities.o initialize_BigInt.o multiply_BigInt.o subtract_BigInt.o tobinary_BigInt.o -o main
	make clean
	make run

main.o: main.c
	gcc -c main.c

utilities.o: .\utilities\utilities.c
	gcc -c .\utilities\utilities.c

BigInt_utilities.o: .\BigInt\BigInt_utilities.c
	gcc -c .\BigInt\BigInt_utilities.c

add_BigInt.o: .\BigInt\add_BigInt.c
	gcc -c .\BigInt\add_BigInt.c
	

initialize_BigInt.o: .\BigInt\initialize_BigInt.c
	gcc -c .\BigInt\initialize_BigInt.c

multiply_BigInt.o: .\BigInt\multiply_BigInt.c
	gcc -c .\BigInt\multiply_BigInt.c

subtract_BigInt.o: .\BigInt\subtract_BigInt.c
	gcc -c .\BigInt\subtract_BigInt.c

tobinary_BigInt.o: .\BigInt\tobinary_BigInt.c
	gcc -c .\BigInt\tobinary_BigInt.c

clean:
	rm -r *.o

run:
	.\main.exe