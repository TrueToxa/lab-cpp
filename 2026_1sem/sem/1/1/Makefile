# all: 1.cpp func.cc
# 	g++ 1.cpp func.cc
all: main

main: 1.o func.o
	g++ 1.o func.o

1.o:
	g++ 1.cpp -c -o 1.o

func.o:
	g++ func.cc -c -o func.o

clean:
	rm *.o