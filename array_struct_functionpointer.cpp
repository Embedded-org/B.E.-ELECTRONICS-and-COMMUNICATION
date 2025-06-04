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

struct st 
{
int(*intadd)(int,int);
int(*intmultiply)(int,int);

};
st ptr1={add,multiply};


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