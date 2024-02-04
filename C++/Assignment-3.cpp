#include<iostream>
#include<stdio.h>
#include<conio.h>

using namespace std;
struct node
{
    int item;
    node* next;
};
class SLL
{
    private:
        node* start;
    public:
        SLL();
        void insertAtStart(int);
        void insertAtEnd(int);
        node* search(int);
        void insertAtAfter(node*,int);
        void deleteFirst();
        void deleteLast();
        void deleteAfter(node*);
        ~SLL();   
        void showdata();
        SLL(SLL&); 
        void operator=(SLL &);  

        int count(); 
        void reverseNode(); 
};
void SLL :: reverseNode()
{
    node* t1,*t2,*t3;
    if(start)
    {
        t1=start;
        while(t1)
        {
            t2=t1;
            if(t2->next)
            {
                
            }
            t1=t1->next;
        }
    }
}
int SLL :: count()
{
    node* t;
    int i=0;
    if(start)
    {
        t=start;
        while(t)
        {
            i++;
            t=t->next;
        }
    }
    return i;
}
void SLL :: showdata()
{
    node* t=start;
    while(t)
    {
        cout<<" "<<t->item;
        t=t->next;
    };
}
void SLL :: operator=(SLL &S)
{
    node* t;
    if(S.start!=NULL)
    {
        t=S.start;
        while(t)
        {
            node*n = new node;
            n->item=t->item;
            if(start==NULL)
                n->next=NULL;
            else
                n->next=start;
            start=n;
            t=t->next;
        }
    }
}
SLL :: SLL(SLL &S)
{
    node* t;
    if(S.start!=NULL)
    {
        t=S.start;
        while(t)
        {
            node*n = new node;
            n->item=t->item;
            if(start==NULL)
                n->next=NULL;
            else
                n->next=start;
            start=n;
            t=t->next;
        }
    }
}
SLL :: ~SLL()
{
    while(start)
        deleteFirst();
}
void SLL :: deleteAfter(node* temp)
{
    node* t;
    if(temp!=NULL)
    {
        t=temp->next;
        if(t)
            temp->next=t->next;
        delete t;
    }
}
void SLL :: deleteLast()
{
    node* t,*r;
    if(start)
    {
        t = start;
        if(start->next==nullptr)
            start=nullptr;
        else
        {
            while(t->next->next)
                t=t->next;
            r=t->next;
            t->next=NULL;
        }
        delete t;
    }
}
void SLL :: deleteFirst()
{
    node* t;
    if(start)
    {
        t=start;
        start=t->next;
        delete t;
    }
    else
        cout<<"List is empty";
}
void SLL :: insertAtAfter(node* temp,int data)
{
    node* n=new node;
    n->item=data;

    if(temp!=nullptr)
    {
        n->next=temp->next;
        temp->next=n;
    }
}
node* SLL :: search(int data)
{
    node* t=start;
    if(start)
    {
        while(t)
            if(t->item==data)
                return t;
            else
                t=t->next;
    }
    return nullptr;
}
void SLL :: insertAtEnd(int data)
{
    node* n,*t;
    n= new node;
    n->item=data;
    n->next=nullptr;
    if(start==nullptr)
        start=n;
    else
    {
        t=start;
        while(t->next!=nullptr)
            t=t->next;
        t->next=n;
    }
}
void SLL :: insertAtStart(int data)
{
    node* n;
    n= new node;
    n->item=data;
    n->next=nullptr;
    if(start==nullptr)
        start=n;
    else
    {
        n->next=start;
        start=n;
    }
}
SLL :: SLL()
{
    start=nullptr; 
}

int main()
{
    SLL s,s1;
    node* t;
    s.insertAtStart(10);
    SLL S=s;
    s.showdata();
    s1=s;
    s1.showdata();
    getch();
    return 0;
}