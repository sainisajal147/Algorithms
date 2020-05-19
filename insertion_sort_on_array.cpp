#include <iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

void insertion(vector<int> &a)
{
    for(int i=1;i<a.size();i++)
    {
        int temp=a[i];
        int j=i-1;
        while(j>-1 && a[j]>temp)
        {
            a[j+1]=a[j];
                j--;
        }
        a[j+1]=temp;
    }
}
int main()
{
    vector<int> a={4,8,5,1,2};
    cout<<"the sorted list is:\n";
    insertion(a);
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
