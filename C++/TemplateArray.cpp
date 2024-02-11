#include<iostream>
#include<stdio.h>
using namespace std;
template <typename Y>

void printArray(Y ptr[],int size)
{
    for(int i=0;i<size;i++)
        cout<<" "<<ptr[i];
}
int main()
{
   char ptr[]="Hello";
   int size = sizeof(ptr)/sizeof(ptr[0]);
   printArray(ptr,5);
    return 0;
}