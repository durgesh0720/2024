#include "INCLUDE.h"
using namespace std;

struct node
{
    int item;
    node* next;
};
class CLL
{
    private:
        node* last;
    public:
        CLL();
        void insertAtStart(int);
        void insertAtEnd(int);
        node* search(int);
        void insertAtAfter(node*,int);
        void showdata();
        void deleteFirst();
        void deleteLast();
        void deleteNode(node*);
        ~CLL();
};
void CLL :: showdata()
{
    node* t=last->next;
    do
    { 
        cout<<" "<<t->item;
        t=t->next;
    }while(t!=last->next);
}
CLL :: ~CLL()
{
    while(last)
        deleteLast();
}
void CLL :: deleteNode(node* temp)
{
    if(last)
    {
        node* t=last->next;
        if(temp==temp->next)
            last=NULL;
        else
        {
            while(t->next!=temp)
                t=t->next;
            t->next=temp->next;
            if(last==temp)
                last=t;
        }
        delete temp;
    }
}
void CLL :: deleteLast()
{
    node* t;
    if(last)
    {
        t=last;
        if(last==last->next)
            last=NULL;
        else
        {   
            while(t->next!=last)
                t=t->next;
            t->next=last->next;
            delete last;
            last=t;
        }
    }
}
void CLL :: deleteFirst()
{
    node* t;
    if(last)
    {
        t=last->next;
        if(last==last->next)
            last=NULL;
        else
            last->next=t->next;
        delete t;
    }
}
void CLL :: insertAtAfter(node* temp,int data)
{
    if(temp)
    {
        node* n= new node;
        n->item=data;
        if(temp==last)
        {
            n->next=last->next;
            last->next=n;
            last=n;
        }
        else
        {  
            n->next=temp->next;
            temp->next=n;
        }
    }
}
node* CLL :: search(int data)
{
    node*t=last->next;
    if(last)
    {
        if(last->item==data)
            return last;
        else
            while(t!=last)
            {
                if(t->item==data)
                    return t;
                t=t->next;
            }
    }
    return NULL;
}
void CLL :: insertAtEnd(int data)
{
    node* n= new node;
    n->item=data;
    if(last==NULL)
        n->next=n;
    else
    {
        n->next=last->next;
        last->next=n;
        
    }
    last=n;
}
void CLL :: insertAtStart(int data)
{
    node* n= new node;
    n->item=data;
    if(last==NULL)
    {
        n->next=n;
        last=n;
    }
    else
    {
        n->next=last->next;
        last->next=n;
    }
}
CLL :: CLL()
{
   last=NULL;
}
int main()
{
    node*t;
    CLL c;
    c.insertAtStart(20);
    c.insertAtEnd(60);
    c.insertAtAfter(c.search(20),50);
    c.showdata();
    cout<<endl;
    c.showdata();
    return 0;
}