#include<iostream>
#include<stdio.h>
using namespace std;

class queue
{
    private:
        int capacity;
        int rear,front;
        int *ptr;
    public:
        queue(int);
        void ENQUEUE(int);
};
void queue :: ENQUEUE(int data)
{
    if(front<0 && rear<0)
        rear=front=0;
    else if(front>=0 && front<rear && rear<capacity-1)
        rear++;
    else 
}
queue :: queue(int size)
{
    capacity=size;
    rear=front=-1;
    ptr = new int[capacity];
}