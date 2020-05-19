#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void shell_sort(vector<int > &a)
{
    int gap=floor(a.size()/2);
    while(gap>0)
    {
        for(int i=gap;i<a.size();i++)
        {
            int temp=a[i];
             int j=i-gap;
             while(j>=0 && a[j]>temp)
             {
                 swap(a[j],a[j+gap]);
                 j=j-gap;
             }
           }
           gap=floor(gap/2);
    }
}
int main()
{
    vector<int> a={12, 15, 1, 5, 6, 14, 11};
    shell_sort(a);
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
