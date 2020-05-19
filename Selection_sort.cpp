#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void selection(vector<int> &a)
{
    for(int i=0;i<a.size();i++)
    {
        int j=i,k=i;
        for(j=i;j<a.size();j++)
        {
            if(a[k]>a[j])
                k=j;
        }
        swap(a[k],a[i]);
    }
}
int  part(int a[], int l , int h)
{
    int pivot=a[l];
    int i=l,j=h;
    do
    {
        do{i++;}while(a[i]<=pivot);
        do{j--;}while(a[j]>pivot);
        if(i<j)
            swap(a[i],a[j]);
    }while(i<j);
    swap(a[l],a[j]);
    return j;
}
void quick_sort(int a[],int l,int h)
{
    int j;
    if(l<h)
    {
    j=part(a,l,h);
    quick_sort(a,l,j);
    quick_sort(a,j+1,h);
    }
}
int main()
{
    int a[]={8,6,3,2,5,4,INT32_MAX};
    for(int i=0;i<6;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\nSorted list is:\n";
    //selection(a);
    quick_sort(a,0,6);
    for(int i=0;i<6;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
