#include <iostream>
#include<math.h>
using namespace std;
struct node
{
    int data;
    node * next;
};
void Insert(node * &h, int data)
{
    node * newn=new node();
    newn->data=data;
    newn->next=NULL;
    if(h==NULL)
     {
         h=newn;
         return;
     }
    node * head=h;
    while(head->next)
        head=head->next;
    head->next=newn;
}
int Delete(node * &head)
{
    if(head->next==NULL)
    {
            int data=head->data;
            delete head->next;
            head=NULL;
            return data;
    }
    node * temp=head;
    head=head->next;
    temp->next=NULL;
    int data=temp->data;
    delete temp;
    return data;
}
void bin_sort(int a[],int n, int m)
{
   node **bins;
   bins=new  node *[m+1];
   for(int i=0;i<=m;i++)
   {
       bins[i]=NULL;
   }
   for(int i=0;i<n;i++)
   {
      Insert(bins[a[i]],a[i]);
   }
   int j=0;
   for(int i=0;i<=m;i++)
    {
        while(bins[i]!=NULL)
        {
            a[j++]= Delete(bins[i]);
        }
    }
}
void radix(int a[], int n, int m)
{
   node **bins;
   bins=new  node *[10];
   for(int i=0;i<10;i++)
   {
       bins[i]=NULL;
   }
   for(int k=0;k<m;k++)
   {
           for(int i=0;i<n;i++)
           {
              Insert(bins[(int)(a[i]/pow(10,k))%10],a[i]);
           }
           int j=0;
           for(int i=0;i<10;i++)
            {
                while(bins[i]!=NULL)
                {
                    a[j++]= Delete(bins[i]);
                }
            }
   }
}
void count_sort(int a[],int n, int m)
{
    int h[m+1]={0};
    for(int i=0;i<n;i++)
    {
        h[a[i]]++;
    }
    int j=0;
    for(int i=0;i<=m;i++)
    {
        while(h[i]>0)
        {
            a[j++]=i;
            h[i]--;
        }
    }
}
int main()
{
    int a[]={6,3,9,10,15,6,8,12,3,6};
    int n=10;
    radix(a,10,2);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    int b[]={237,146,259,348,152,163,253,48,36,62};
    radix(b,10,3);
    for(int i=0;i<n;i++)
    {
        cout<<b[i]<<" ";
    }
    return 0;
}
