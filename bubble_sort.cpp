#include <iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

vector<int> bubble(vector<int > a)
{
    for(int i=0;i<a.size()-1;i++)
    {
        int flag=0;
        for(int j=0;j<a.size()-1;j++)
        {
            if(a[j]>a[j+1])
                {
                    swap(a[j],a[j+1]);
                    flag++;
                }
        }
        if(flag==0)
            break;
    }
    return a;
}
int main()
{
    vector<int> a={15,23,432,521,612,743,854};
    a=bubble(a);
    cout<<"the sorted list is:\n";
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
