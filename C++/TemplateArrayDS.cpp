#include<iostream>
#include<stdio.h>
using namespace std;

template <typename A>
class array
{
    private:
        int capacity;
        int lastIndex;
        A *ptr;
    public:
        array(int size);
        void append(A);
        void display();
};
template<typename A>
void array<A>::display()
{
	for(int i=0;i<=lastIndex;i++)
		cout<<" "<<ptr[i];
}
template<typename A>
void array<A>::append(A data)
{
    if(lastIndex!=capacity-1)
    {
        lastIndex++;
        ptr[lastIndex]=data;
    }
    else
        cout<<"Array full!";
}
template<typename A>
array <A> ::array(int size)
{
    lastIndex=-1;
    capacity=size;
    ptr=new A[size];
}
int main()
{
	array <int> a(5);
	a.append(10);
	a.append(50);
	a.append(60);
	a.display();
	cout<<endl;
	array <char> b(10);
	b.append('H');
	b.append('E');
	b.append('L');
	b.append('L');
	b.append('O');
	b.display();
	return 0;
}