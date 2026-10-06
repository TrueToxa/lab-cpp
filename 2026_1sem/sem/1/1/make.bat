mkdir -p build/
g++ func.cc -c -o ./build/func.o
g++ 1.cpp -c -o ./build/1.o

g++ ./build/1.o ./build/func.o -o main
