#include<iostream>

using namespace std;
class dynArray
{
    private:
        int capacity;
        int lastIndex;
        int* ptr;
    public:
        dynArray();
        dynArray(int);
        dynArray(dynArray&);
        void operator=(dynArray&);
        void doubleArray();
        void halfArray();
        int capArray();
        bool isEmpty();
        bool isFull();
        void append(int);
        void insert(int,int);
        void edit(int,int);
        void deleteElement(int);
        void showData();
        int getElement(int);
        int countElement();
        int findElement(int);
        ~dynArray();
};
void dynArray :: operator=(dynArray &a)
{
    capacity=a.capacity;
    lastIndex=a.lastIndex;
    ptr=new int[capacity];
    if(!a.isEmpty())
        for(int i=0;i<=lastIndex;i++)
            ptr[i]=a.ptr[i];
}
dynArray :: dynArray(dynArray &a)
{
    capacity=a.capacity;
    lastIndex=a.lastIndex;
    ptr=new int[capacity];
    if(!a.isEmpty())
        for(int i=0;i<=lastIndex;i++)
            ptr[i]=a.ptr[i];
}
dynArray :: ~dynArray()
{
    delete ptr;
}
int dynArray :: findElement(int data)
{
    if(!isEmpty())
    {
        for(int i=0;i<=lastIndex;i++)
            if(ptr[i]==data)
                return i;
    }
    return -1;
}
int dynArray :: countElement()
{
    return lastIndex+1;
}
int dynArray :: getElement(int index)
{
    if(!isEmpty() && index>=0 && index<=lastIndex)
    {
        return ptr[index];
    }
    return -1;
}
void dynArray :: deleteElement(int index)
{
    if(!isEmpty() && index>=0 && index<=lastIndex)
    {
        for(int i=index;i<lastIndex;i++)
            ptr[i]=ptr[i+1];
        lastIndex--;
        if(lastIndex<capacity/2)
            halfArray();
    }
    else
        cout<<"Array underflow or Wrong index!";
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
    A.append(30);
    A.append(40);
    A.append(50);
    A.showData();
    cout<<A.capArray();
    return 0;
}