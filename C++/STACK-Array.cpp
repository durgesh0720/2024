#include "INCLUDE.h"
using namespace std;
class STACK
{
    private:
        int capacity;
        int top;
        int* ptr;
    protected:
        bool Underflow();
        bool Overflow();
    public:
        STACK(int);
        void PUSH(int);
        int PEEK();
        void POP();
        ~STACK();
        void reverseStack();
};
void STACK :: reverseStack()
{
    int* arr = new int[capacity];
    int i=0;
    while(top!=-1)
    {
        arr[i]=ptr[top];
        top--;
        i++;
    }
    delete []ptr;
    ptr=arr; 
    top=i-1;       
}
STACK :: ~STACK()
{
    delete []ptr;
}
void STACK :: POP()
{
    if(!Underflow())
    {
        top--;
    }
    else
        cout<<"\nSTACK underflow!";
}
int STACK :: PEEK()
{
    return ptr[top];
}
void STACK :: PUSH(int data)
{
    if(!Overflow())
    {
        top++;
        ptr[top]=data;
    }
    else
        cout<<"\nStack is full!";
}
bool STACK :: Underflow()
{
    return top==-1;
}
bool STACK :: Overflow()
{
    return top==capacity-1;
}
STACK :: STACK(int size)
{
    capacity = size;
    top = -1;
    ptr= new int[capacity];
}
int main()
{
    STACK S(5);
    S.PUSH(10);
    S.PUSH(50);
    S.PUSH(60);
    cout<<S.PEEK();
    return 0;
}