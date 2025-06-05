#include <iostream>
#include<cstring>
using namespace std;

int add(int a,int b)
{
  return(a+b);
}

int multiply(int a, int b)
{

  return(a*b);
}


int(*intadd)(int,int)=add;
int(*intmultiply)(int,int)=multiply;
int (*p[2])(int,int)={add,multiply};

typedef struct
{
int(*intadd)(int,int);
int(*intmultiply)(int,int);
}funcptr;
funcptr ptr1={add,multiply};


int main()
{
char a[]="anand";
char b[]="mohan";
cout<<"add int struct "<<ptr1.intadd(4,5)<<endl;
cout<<"multiply int struct "<<ptr1.intmultiply(6,7)<<endl;

cout<<"add int array "<<p[0](40,50)<<endl;
cout<<"multiply int array"<<p[1](60,70)<<endl;

return(0);
}

/*
creating prog executable Without static linking:
gcc -c ./src/main.c -I./include
gcc -c ./src/mymath1.c -I./include
gcc -c ./src/mymath2.c -I./include
gcc main.o mymath1.o mymath2.o -o prog
./prog


creating prog executable With static linking:

ar rcs mymath.a mymath1.o mymath2.o
gcc main.o mymath.a -o prog
./prog


creating prog executable With Dynamic linking:
gcc -fPIC -shared ./src/mymath1.c ./src/mymath2.c -I./include
mv mymath1.so libmymath1.so
mv mymath1.so lib mymath2.so
gcc ./src/main.c -o prog -I./include -lmymath1 -lmymath2 -L ./ LD_LIBRARY_PATH="./"
./prog



final execultable saving intermediate files and then Place the output into <main>.
gcc -save-temps -c main.cpp -o main

Preprocess only; do not compile, assemble or link.
gcc  -E main.cpp >main.ii
Compile only; do not assemble or link.
gcc  -S main.cpp >main.ss
Compile and assemble, but do not link.
gcc  -c  main.cpp 

*/