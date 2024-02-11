#include<iostream>
#include<stdio.h>
#include<conio.h>

using namespace std;
template<typename X>
struct node
{
    X item;
    node* next;
};
template <typename X>
class SLL
{
    private:
        node<X>* start;
    public:
        SLL();
        void insertAtStart(X);
        void insertAtEnd(X);
        node<X>* search(X);
        void insertAtAfter(node<X>*,X);
        void deleteFirst();
        void deleteLast();
        void deleteAfter(node<X>*);
        ~SLL();   
        void showdata();
        SLL(SLL&); 
        void operator=(SLL &);  

        int count(); 
        void reverseNode(); 
};
template<typename X>
void SLL <X> :: reverseNode()
{
    node<X>* t1,*t2,*t3;
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
template<typename X>
int SLL <X> :: count()
{
    node<X>* t;
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
template<typename X>
void SLL <X> :: showdata()
{
    node<X>* t=start;
    while(t)
    {
        cout<<" "<<t->item;
        t=t->next;
    };
}
template<typename X>
void SLL <X> :: operator=(SLL &S)
{
    node<X>* t;
    if(S.start!=NULL)
    {
        t=S.start;
        while(t)
        {
            node<X>*n = new node<X>;
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
template<typename X>
SLL <X> :: SLL(SLL &S)
{
    node<X>* t;
    if(S.start!=NULL)
    {
        t=S.start;
        while(t)
        {
            node<X>*n = new node<X>;
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
template<typename X>
SLL <X> :: ~SLL()
{
    while(start)
        deleteFirst();
}
template<typename X>
void SLL <X> :: deleteAfter(node<X>* temp)
{
    node<X>* t;
    if(temp!=NULL)
    {
        t=temp->next;
        if(t)
            temp->next=t->next;
        delete t;
    }
}
template<typename X>
void SLL <X> :: deleteLast()
{
    node<X>* t,*r;
    if(start)
    {
        t = start;
        if(start->next==NULL)
            start=NULL;
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
template<typename X>
void SLL <X> :: deleteFirst()
{
    node<X>* t;
    if(start)
    {
        t=start;
        start=t->next;
        delete t;
    }
    else
        cout<<"List is empty";
}
template<typename X>
void SLL <X> :: insertAtAfter(node<X>* temp,X data)
{
    node<X>* n=new node<X>;
    n->item=data;

    if(temp!=NULL)
    {
        n->next=temp->next;
        temp->next=n;
    }
}
template<typename X>
node<X>* SLL <X> :: search(X data)
{
    node<X>* t=start;
    if(start)
    {
        while(t)
            if(t->item==data)
                return t;
            else
                t=t->next;
    }
    return NULL;
}
template<typename X>
void SLL <X> :: insertAtEnd(X data)
{
    node<X>* n,*t;
    n= new node<X>;
    n->item=data;
    n->next=NULL;
    if(start==NULL)
        start=n;
    else
    {
        t=start;
        while(t->next!=NULL)
            t=t->next;
        t->next=n;
    }
}
template<typename X>
void SLL <X> :: insertAtStart(X data)
{
    node<X>* n;
    n= new node<X>;
    n->item=data;
    n->next=NULL;
    if(start==NULL)
        start=n;
    else
    {
        n->next=start;
        start=n;
    }
}
template<typename X>
SLL <X> :: SLL()
{
    start=NULL; 
}

int main()
{
    SLL <int>s;
    s.insertAtStart(50);
    s.insertAtStart(71);
    s.insertAtStart(100);
    s.showdata();
    cout<<endl;
    SLL <string> S1;
    S1.insertAtStart("Ram");
    S1.insertAtStart("Sita");
    S1.showdata();
    return 0;
}