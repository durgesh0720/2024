#include<iostream>
#include<stdio.h>
using namespace std;
template <typename X>

void Sort(X ptr[],int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
            if(ptr[i]>ptr[j])
            {
                X temp=ptr[i];
                ptr[i]=ptr[j];
                ptr[j]=temp;
            }
    }
    for(int i=0;i<size;i++)
        cout<<" "<<ptr[i];
}
int main()
{
    char ptr[]="oLLop";
    Sort(ptr,5);
    return 0;
}