CC=gcc
FLAGS= -Wall -g -fPIC
AR=ar

all: mains maind

myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c

libmyBank.a: myBank.o
	$(AR) -rcs libmyBank.a myBank.o 
          
	
mybanks:
	$(AR) -rcs libmyBank.a myBank.o 


libmyBank.so: myBank.o
	$(CC) -shared -o libmyBank.so myBank.o
	

mymathd:
	$(CC) -shared -o libmyBank.so myBank.o 	
       	
main.o: main.c myBank.h
	$(CC) $(FLAGS) -c main.c

mains: main.o libmyBank.a
	$(CC) $(FLAGS) -o mains main.o libmyBank.a

maind: main.o libmyBank.so
	$(CC) $(FLAGS) -o maind main.o ./libmyBank.so

.PHONY: clean all

clean:
	rm -f mains maind *.so *.a *.o


