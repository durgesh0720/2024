#include<iostream>
#include<stdio.h>
using namespace std;

class array
{
    private:
        int capacity;
        int lastIndex;
        int *ptr;
    public:
        array(int); 
        bool isEmpty();
        void append(int);
        void insert(int,int);
        void edit(int,int);
        void del(int);
        bool isFull();
        int get(int);
        int countElement();
        int findElement(int);
        int* arrayAddress();
        int sizeOfArray();
        void showData();
        array(array&);
        void operator=(array&);
        ~array();
};
void array :: operator=(array &a)
{
    capacity=a.capacity;
    lastIndex=a.lastIndex;
    ptr = new int[capacity];
    if(!a.isEmpty())
    {
        for(int i=0;i<=lastIndex;i++)
            ptr[i]=a.ptr[i];
    }
    else
        cout<<"Array underflow!";
}
array :: array(array &a)
{
    capacity=a.capacity;
    lastIndex=a.lastIndex;
    ptr = new int[capacity];
    if(!a.isEmpty())
    {
        for(int i=0;i<=lastIndex;i++)
            ptr[i]=a.ptr[i];
    }
    else
        cout<<"Array underflow!";
}
array :: ~array()
{
    delete ptr;
}
void array :: showData()
{
    if(!isEmpty())
    {
        for(int i=0;i<capacity;i++)
            cout<<ptr[i]<<" ";
    }
}
int array :: sizeOfArray()
{
    return capacity;
}
int* array :: arrayAddress()
{
    return ptr;
}
int array :: findElement(int data)
{
    if(!isEmpty())
    {
        for(int i=0;i<=lastIndex;i++)
            if(ptr[i]==data)
                return ptr[i];
    }
    return -1;
}
int array :: countElement()
{
    return lastIndex+1;
}
int array :: get(int index)
{
    if(0<=index && index<=lastIndex)
        return ptr[index];
    cout<<"Wrong index ";
    return -1;
}
bool array :: isFull()
{
    return lastIndex==capacity-1;
}
void array :: del(int index)
{
    if(0<=index<=lastIndex && lastIndex>=0)
    {
        for(int i=index;i<lastIndex;i++)
            ptr[i]=ptr[i+1];
        lastIndex--;
    }
    else
        cout<<"Wrong index or underflow";
}
void array :: edit(int data,int index)
{
    if(0<=index && index<lastIndex+1)
        ptr[index]=data;
    else
        cout<<"Wrong Index";
}
void array :: insert(int data,int index)
{
    if(0<=index && index<lastIndex+1)
    {
        for(int i=lastIndex;i>=index;i--)
            ptr[i+1]=ptr[i];
        ptr[index]=data;
        lastIndex++;
    }
    else
        cout<<"Wrong index";
}
void array :: append(int data)
{
    if(lastIndex<capacity-1)
    {
        lastIndex++;
        ptr[lastIndex]=data;
    }
    else
        cout<<"Overflow!";
}
bool array :: isEmpty()
{
    return lastIndex <0;   
}
array :: array(int size)
{
    capacity = size;
    lastIndex = -1;
    ptr = new int[capacity];
}
void sort(array &a)             // sort array
{
    int *arr,lastFull,temp;
    arr=a.arrayAddress();
    lastFull=a.countElement();

    for(int i=0;i<=lastFull;i++)
    {
        for(int j=i+1;j<lastFull;j++)
        {
            if(arr[i]>arr[j])
            {
                temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
int greatestElement(array &a)       // find greatest element
{
    int *arr,lastFull,temp;
    arr=a.arrayAddress();
    lastFull=a.countElement(); 
    if(!a.isEmpty())
    {
        temp=arr[0];
        for(int i=0;i<lastFull;i++)
            if(arr[i]>temp)
                temp=arr[i];
        return temp;
    }
    return -1;
}
int smallestElement(array &a)       // array of smallest element
{
    int *arr,lastFull,temp;
    arr=a.arrayAddress();
    lastFull=a.countElement(); 
    if(!a.isEmpty())
    {
        temp=arr[0];
        for(int i=0;i<lastFull;i++)
            if(arr[i]<temp)
                temp=arr[i];
        return temp;
    }
    return -1;
}
void searchElement(array &a,int item)           // searching element
{
    int *arr,lastFull;
    arr=a.arrayAddress();
    lastFull=a.countElement(); 
    if(!a.isEmpty())
    {
        for(int i=0;i<lastFull;i++)
            if(item==arr[i])
            {
                cout<<endl<<"Element founded!";
                return ;
            }
            cout<<"Element not founded!";
    }
    else
        cout<<"Array is empty!";
}
int sumAllElement(array &a)     // sum of all element
{
   int *arr,lastFull,sum=0;
    arr=a.arrayAddress();
    lastFull=a.countElement(); 
    if(!a.isEmpty())
    {
        for(int i=0;i<lastFull;i++)
            sum+=arr[i];
        return sum;
    } 
    else
        return -1;
}
int avgAllElement(array &a)     // avg of all element
{
    return (float)sumAllElement(a)/a.countElement();
}
void rotateArray(array &a)      // rotate array
{
    int *arr,lastFull,temp;
    arr=a.arrayAddress();
    lastFull=a.countElement(); 
    if(!a.isEmpty())
    {
        temp=arr[lastFull-1];
        for(int i=lastFull-1;i>0;i--)
            arr[i]=arr[i-1];
        arr[0]=temp;
    }
    else
        cout<<"Underflow!";
}
void removeDublicate(array &a)
{
    int *arr,lastFull,temp;
    arr = a.arrayAddress();
    lastFull=a.countElement();
    if(!a.isEmpty())
    {
        for(int i=0;i<lastFull;i++)
        {
            temp=arr[i];
            for(int j=0;j<lastFull;j++)
            {
                if(temp==arr[j])
                {
                    for(int k=j;k<lastFull;k++)
                        arr[k]=arr[k+1];
                }
            }
        }
    }
}
int main()
{
    array A(5),a(5);
    A.append(20);
    A.append(30);
    A.append(40);
    A.append(50);
    A.append(60);
    a=A;
    a.showData();
    cout<<endl;
    return 0;
}