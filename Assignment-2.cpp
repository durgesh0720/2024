#include<iostream>

using namespace std;
class dynArray
{
    private:
        int capacity;
        int lastIndex;
        int* ptr;
    protected:
        bool isFull();
    public:
        dynArray();
        dynArray(int);
        void doubleArray();
        void halfArray();
        int capArray();
        bool isEmpty();
        void append(int);
        void insert(int,int);
        void edit(int,int);
        void deleteElement(int);
        void showData();
};
void dynArray :: deleteElement(int index)
{
    
}
void dynArray :: edit(int data,int index)
{
    if(!isEmpty() && index>=0 && index<=lastIndex)
    {
        ptr[index]=data;
    }
    else
        cout<<"Array underflow or wrong index";
}
void dynArray :: showData()
{
    if(!isEmpty())
    {
        for(int i=0;i<=lastIndex;i++)
            cout<<ptr[i]<<" ";
    }
    else
        cout<<"Array underflow!";
}
void dynArray :: insert(int data,int index)
{
    if(index>=0 && index<=lastIndex)
    {
        if(!isFull())
        {
            for(int i=lastIndex;i>=index;i--)
                ptr[i+1]=ptr[i];
            ptr[index]=data;
            lastIndex++;
        }
        else
        {
            doubleArray();
            for(int i=lastIndex;i>=index;i--)
                ptr[i+1]=ptr[i];
            ptr[index]=data;
            lastIndex++;
        }
    }
    else
        cout<<"Wrong Index";
}
void dynArray :: append(int data)
{
    if(!isFull())
    {
        lastIndex++;
        ptr[lastIndex]=data;
    }
    else
    {
        doubleArray();
        lastIndex++;
        ptr[lastIndex]=data;
    }
}
bool dynArray :: isFull()
{
    return lastIndex==capacity-1;
}
bool dynArray :: isEmpty()
{
    return lastIndex<0;
}
int dynArray :: capArray()
{
    return capacity;
}
void dynArray :: halfArray()
{
    int* arr;
    capacity=capacity/2;
    arr = new int[capacity];
    for(int i=0;i<capacity;i++)
        arr[i]=ptr[i];
    delete ptr;
    ptr=arr;
}
void dynArray :: doubleArray()
{
    int* arr;
    capacity=capacity*2;
    arr = new int[capacity];
    for(int i=0;i<capacity;i++)
        arr[i]=ptr[i];
    delete ptr;
    ptr=arr;
}
dynArray :: dynArray(int size)
{
    capacity=size;
    lastIndex = -1;
    ptr = new int[capacity];
}
dynArray :: dynArray()
{
    capacity = 1;
    lastIndex = -1;
    ptr = new int[capacity];
}
int main()
{
    dynArray A;
    A.append(10);
    A.append(20);
    A.showData();
    cout<<A.capArray();
    return 0;
}