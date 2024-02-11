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
    for(int i=0;i<lastIndex;++i)
        cout<<" "<<ptr[i];
}
void heap :: insert(int data)
{
    int parant,node=lastIndex;
    if(lastIndex < capacity-1)
    {
        if(lastIndex==0)
        {
            ptr[lastIndex]=data;
            lastIndex++;
        }
        else
        {
            ptr[node]=data;
            while(node)
            {
                parant=(node-1)/2;
                if(ptr[parant]<ptr[node])
                {
                    ptr[node]=ptr[parant];
                    ptr[parant]=data;
                    node=parant;
                }
                else
                    break;                
            }
            lastIndex++;
        }
        
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
    heap h(8);
    h.insert(50);
    h.insert(20);
    h.insert(80);
    h.insert(70);
	h.insert(60);
	h.insert(30);
	h.insert(90);
	h.insert(40);
    h.showdata();
    return 0;
}
