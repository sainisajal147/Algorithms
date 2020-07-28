#include <iostream>

using namespace std;
#define I 32768
void disp(int n ,int **a)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]==I)
                cout<<"_ ";
            else
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
void bellman(int n, int start, int **a)
{
    int dis[n];
    dis[start]=0;
    for(int i=0;i<n;i++)
    {
        if(i!=start)
        dis[i]=I;
    }
    for(int k=0;k<n-1;k++)
    {
        int flag=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dis[i]+a[i][j]<dis[j])
                {
                    dis[j]=dis[i]+a[i][j];
                    flag=1;
                }
            }
        }
        if(flag==0)
            break;
    }
    cout<<start<<" is the source, and the corresponding distances are:\n";
    for(int i=0;i<n;i++)
    {
        if(i!=start)
        {
            cout<<i<<" - "<<dis[i]<<endl;
        }
    }
}
int main()
{
    int n=7;
    //int a[][n]={{0,6,5,5,0,0,0},{0,0,0,0,-1,0,0},{0,-2,0,0,1,0,0},{0,0,-2,0,0,-1,0},{0,0,0,0,0,0,3},{0,0,0,0,0,0,3},{0,0,0,0,0,0,0}};
    int **a;
    a=new int * [n];
    for(int i=0;i<n;i++)
    {
        a[i]=new int[n];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            a[i][j]=I;
        }
    }
    a[0][1]=6,a[0][2]=5,a[0][3]=5;
    a[1][4]=-1;
    a[2][1]=-2,a[2][4]=1;
    a[3][2]=-2,a[3][5]=-1;
    a[4][6]=3;
    a[5][6]=3;
    disp(n,a);
    cout<<endl;
    bellman(n,0,a);
    return 0;
}
