for idx in 1 2 3 4 
do
    echo $idx
done 

g++ file.cpp
./a.exe >> 1.txt

for idx in 0 1 2 3 4 5
do 
    g++ file-$idx -DN=idx -o main.exe
    ./main.exe
done