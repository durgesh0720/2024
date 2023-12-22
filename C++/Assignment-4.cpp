#include "INCLUDE.h"
using namespace std;
struct node
{
    node* prev;
    int item;
    node* next;
};
class DLL
{
    private:
        node* start;
    public:
        DLL();
        void insertAtstart(int);
        void insertAtLast(int);
        node* search(int);
        void insertAtAfter(node*,int);

        void deleteAtFirst();
        void deleteAtLast();
        void deleteNode(node*);
        ~DLL();

        DLL(DLL&);
        void operator=(DLL &);

        void showdata();
};
void DLL :: showdata()
{
    node*t=start;
    while(t)
    {
        cout<<t->item<<" ";
        t=t->next;
    }
}
void DLL :: operator=(DLL &D)
{
    node*t1,*t=D.start;
    if(t!=NULL)
    {
        while(t)
        {
            node*n=new node;
            n->item=t->item;
            if(start==NULL)
            {
                start=n;
                n->prev=NULL;
                n->next=NULL;
                t1=start;
            }
            else
            {
                t1->next=n;
                n->prev=t1;
                n->next=NULL;
                t1=n;
            }
            t=t->next;
        }
    }
}
DLL :: DLL(DLL &D)
{
    if(D.start)
    {
        node*t1=NULL;
        node*t=D.start;
        while(t!=NULL)
        {
            node*n=new node;
            n->item=t->item;
            if(this->start==NULL)
            {
                this->start=n;
                n->prev=NULL;
            }
            else
            {
                t1->next=n;
                n->prev=t1;
            }
            n->next=NULL;
            t1=n;
            t=t->next;
        }
    }
}
DLL :: ~DLL()
{
    while(start)
        deleteAtFirst();
}
void DLL :: deleteNode(node* temp)
{
    node*t;
    if(temp)
    {
        if(start==temp)     
        {
            start=temp->next;
            start->prev=NULL;
        }
        else
        {
            t=start;
            while(t)
            {
                if(t->next==temp)
                {
                    t->next=temp->next;
                    if(temp->next!=NULL)
                        temp->next->prev=t;
                    break;
                }
                t=t->next;
            }
        }
        delete temp;
    }
}
void DLL :: deleteAtLast()
{
    node* t,*r;
    if(start)
    {
        t=start;
        if(start->next==NULL)
            start=NULL;
        else
        {
            while(t->next->next)
                t=t->next;
            r=t->next;
            t->next=NULL;
        }
        delete r;
    }
}
void DLL :: deleteAtFirst()
{
    if(start)
    {
        node* t;
        t=start;
        if(start->next==NULL)
            start=NULL;
        else
        {
            start=t->next;
            start->prev=NULL;
        }
        delete t;
    }
}
void DLL :: insertAtAfter(node* temp, int data)
{
    if(temp)
    {
        node*n = new node;
        n->item=data;
        n->next=temp->next;
        n->prev=temp;      
        temp->next=n;
        if(temp->next!=NULL)
            temp->next->prev=n;             
    }
    else
        cout<<"Error occured!"; 
}
node* DLL :: search(int data)
{
    node* t;
    if(start)
    {
        t=start;
        while(t)
        {
            if(t->item==data)
                return t;
            t=t->next;
        }
    }
    return NULL;
}
void DLL :: insertAtLast(int data)
{
    node* n = new node;
    n->item=data;
    n->next=NULL;
    if(start==NULL)
    {
        n->prev=NULL;
        start=n;
    }
    else
    {
        node* t=start;
        while(t->next!=NULL)
            t=t->next;
        t->next=n;
        n->prev=t;
    }
}
void DLL :: insertAtstart(int data)
{
    node* n= new node;
    n->item=data;
    n->prev=NULL;
    if(start==NULL)
        n->next=NULL;
    else
    {
        start->prev=n;
        n->next=start;
    }
    start=n;
}
DLL :: DLL()
{
    start=NULL;
}

int main()
{
    DLL d;
    d.insertAtstart(50);
    d.showdata();
    DLL D=d;
    D.showdata();   
    return 0;
}