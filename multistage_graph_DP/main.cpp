#include <iostream>
#include<bits/stdc++.h>
#include<vector>
#define m 32678
using namespace std;
void disp(int n, int a[8][8])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
void DP(int n,int a[8][8],int stages)
{
    int d[n],cost[n];
    cost[n-1]=0;
    d[n-1]=n-1;
    for(int i=n-2;i>=0;i--)
    {
        int mi=m;
        for(int j=i+1;j<n;j++)
        {
            if(a[i][j]!=0 && a[i][j]+cost[j]<mi)
            {
                mi=a[i][j]+cost[j];
                d[i]=j;
            }
        }
        cost[i]=mi;
    }
    for(int i=0;i<n;i++)
    {
        cout<<i<<" "<<d[i]<<" "<<cost[i]<<endl;
    }
    int path[n];
    path[0]=0,path[stages-1]=n-1;
    for(int i=1;i<stages-1;i++)
    {
        path[i]=d[path[i-1]];
    }
    cout<<"The Optimum path is:\n";
    for(int i=0;i<stages;i++)
    {
        cout<<path[i]<<" ";
    }
}
int main()
{
    int n=8;
    int a[][8]={{0,2,1,3,0,0,0,0},{0,0,0,0,2,3,0,0},{0,0,0,0,6,7,0,0},{0,0,0,0,6,8,9,0},{0,0,0,0,0,0,0,6},{0,0,0,0,0,0,0,4},{0,0,0,0,0,0,0,5},{0,0,0,0,0,0,0,0}};
    disp(n,a);
    DP(n,a,4);
    return 0;
}
