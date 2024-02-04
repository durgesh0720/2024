#include<iostream>
using namespace std;
class heap
{
    private:
        int*ptr;
        int capacity;
        int lastIndex;
    public:
        heap(int);
        void insert(int);
        void showdata();
};
void heap :: showdata()
{
    for(int i=0;i<=lastIndex;i++)
        cout<<" "<<ptr[i];
}
void heap :: insert(int data)
{
    int t1=1,t2,r=lastIndex;
    if(lastIndex < capacity-1)
    {
        if(lastIndex==0)
        {
            ptr[lastIndex]=data;
        }
        else
        {
            ptr[r]=data;
            while(r<0)
            {
                t1=(r-1)/2;
                if(ptr[t1]<data)
                {
                    t2=ptr[t1];
                    ptr[t1]=ptr[r];;
                    ptr[r]=t2;
                    r=t1;
                }
                else
                    break;                
            }
        }
        lastIndex++;
    }
}
heap :: heap(int size)
{
    capacity=size;
    lastIndex=0;
    ptr= new int[capacity];
}
int main()
{
    heap h(5);
    h.insert(60);
    h.insert(50);
    h.showdata();
    return 0;
}