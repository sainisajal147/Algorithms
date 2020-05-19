#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
void Merge(int a[],int l, int h, int mid)
{
    int b[100];
    int i=l,j=mid+1,k=l;
    while(i<=mid && j<=h)
    {
        if(a[i]<a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
    }
    while(i<=mid)
        b[k++]=a[i++];
    while(j<=h)
        b[k++]=a[j++];
    for(int i=l;i<=h;i++)
    {
        a[i]=b[i];
    }
}
void merge_sort( int a[],int n)
{
    int i;
    for( i=2;i<=n;i=i*2)
    {
        for(int j=0;j+i-1<=n;j=j+i)
        {
            int l=j;
            int h=j+i-1;
            int mid=floor((l+h)/2);
           Merge(a,l,h,mid);
        }
    }
    if(i/2<n)
        Merge(a,0,n-1,i/2);
}
void rec_merge_sort(int a[], int l,int h)
{
    if(l<h)
    {
        int mid=floor((l+h)/2);
        rec_merge_sort(a,l,mid);
        rec_merge_sort(a,mid+1,h);
        Merge(a,l,h,mid);
    }
}
int main()
{
    int a[]={8,3,7,4,9,2,6,5};
    rec_merge_sort(a,0,7);
   // Merge(a,6,7,6);
    for(int i=0;i<8;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
