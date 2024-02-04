#include "INCLUDE.h"

using namespace std;
struct node
{
    node* prev;
    int item;
    node* next;
};
class CDLL
{
    private:
       node* start;
    public:
        CDLL();
        void insertAtstart(int);
        void insertAtlast(int);
        node* search(int);
        void insertAtAfter(node*,int);

        void deleteFirst();
        void deleteLast();
};
void CDLL :: deleteLast()
{
    node* t;
    if(start)
    {
        t=start->prev;
        if(start==start->next)
            start=NULL;
        else
        {
            t->prev->next=t->next;
            start->prev=t->prev;
        }
    }
}
void CDLL :: deleteFirst()
{
    node* t;
    if(start)
    {
        t=start;
        if(start->next==start)
            start=NULL;
        else
        {
            start=t->next;
            t->prev->next=start;
            start->prev=t->prev;
        }
        delete t;
    }
}
void CDLL :: insertAtAfter(node* temp,int data)
{
    if(temp)
    {
        node*n=new node;
        n->item=data;

        n->next=temp->next;
        n->prev=temp;
        n->next->prev=n;
        temp->next=n;
    }
    else
        cout<<"node not exist!";
}
node* CDLL :: search(int data)
{
    if(start)
    {
        node*t=start;
        do
        {
            if(t->item==data)
                return t;
            t=t->next;
        } while (t!=start); 
    }
    return NULL;
}
void CDLL :: insertAtlast(int data)
{
    node* n= new node;
    n->item=data;
    if(start==NULL)
    {
        n->next=n->prev=n;
        start=n;
    }
    else
    {
        start->prev->next=n;
        n->prev=start->prev;
        n->next=start;
        start->prev=n;
    }
}
void CDLL :: insertAtstart(int data)
{
    node* n= new node;
    n->item=data;
    if(start==NULL)
        n->next=n->prev=n;
    else
    {
        n->next=start;
        n->prev=start->prev;
        n->prev->next=n;
        start->prev=n;
    }
    start=n;
}
CDLL :: CDLL()
{
    start=NULL;
}