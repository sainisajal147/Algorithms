#include <iostream>

using namespace std;
struct node{
    int data;
    node * next;
};
node* getnew(int data)
{
    node * newn=new node();
    newn->data=data;
    newn->next=NULL;
}
node * Insert(node * head, int data)
{
    if(head==NULL)
        return getnew(data);
    node * p=head;
    while(p->next)
        p=p->next;
    p->next=getnew(data);
    return head;
}
void disp(node * p)
{
    if(p)
    {
        cout<<p->data<<" ";
        disp(p->next);
    }
}
node * Insert_sorted(node *head, node * x)
{
    if(head==NULL)
        return x;
    node *q=getnew(0);
    node * p=head;
    while(p)
    {
        if(p->data>x->data && p==head)
        {
            x->next=p;
            head=x;
        }
        else if(q->data<x->data && p->data>x->data)
        {
            q->next=x;
            x->next=p;
        }
        else if(p->data<x->data && p->next==NULL)
        {
            p->next=x;
        }
        q=p;
        p=p->next;
    }
    return head;
}
node * insertion(node * head)
{
node *h=NULL;
node * y=head;
head=head->next;
y->next=NULL;
h=Insert_sorted(h,y);
while(head)
{
    node * x=head;
    head=head->next;
    x->next=NULL;
    h=Insert_sorted(h,x);
}
return h;
}
int main()
{
    node * head=NULL;
    head=Insert(head,43);
    head=Insert(head,65);
    head=Insert(head,23);
    head=Insert(head,12);
    head=Insert(head,1);
    head=Insert(head,20);
    disp(head);
    cout<<endl;
    cout<<"Sorted list is:\n";
    head=insertion(head);
    disp(head);
    return 0;
}
