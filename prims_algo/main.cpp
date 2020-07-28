#include <iostream>

using namespace std;
#define e 32767
void disp(int n,int **g)
{
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
}
void prim(int n,int **g)
{
    int t[2][n-2];
    int near[n];
    for(int i=0;i<n;i++)
        near[i]=e;
    int mini=e;
    for(int i=1;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(mini>g[i][j])
               {
                 mini=g[i][j];
                 t[0][0]=i;
                 t[1][0]=j;
               }
        }
    }
    near[t[0][0]]=0,near[t[1][0]]=0;
    for(int i=1;i<n;i++)
    {
        if(near[i] && g[i][t[0][0]]<g[i][t[1][0]] )
            near[i]=t[0][0];
        else if(near[i])
            near[i]=t[1][0];
    }
    int k;
    for(int i=1;i<n-2;i++)
    {
        mini=e;
        for(int j=1;j<n;j++)
        {
            if(near[j] && g[j][near[j]]<mini)
            {
              mini=g[j][near[j]];
              k=j;
            }
        }
        t[0][i]=k,t[1][i]=near[k];
        near[k]=0;
        for(int j=1;j<n;j++)
        {
            if(near[j] && g[j][k]<g[j][near[j]])
                near[j]=k;
        }
    }
    int sum=0;
    /*for(int i=0;i<2;i++)
    {
        for(int j=0;j<n-2;j++)
        {
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=1;i<n;i++)
    {
        cout<<near[i]<<" ";
    }
    cout<<endl;*/
    for(int i=0;i<n-2;i++)
    {
        sum+=g[t[0][i]][t[1][i]];
    }
    cout<<sum<<endl;
}
int main()
{
    int n,m;
    cin>>n>>m;
    //int g[8][8]={{e,e,e,e,e,e,e,e},{e,e,25,e,e,e,5,e},{e,25,e,12,e,e,e,10},{e,e,12,e,8,e,e,e},{e,e,e,8,e,16,e,14},{e,e,e,e,16,e,20,18},{e,5,e,e,e,20,e,e,},{e,e,10,e,14,18,e,e}};
    int **g;
    g=new int * [n+1];
    for(int i=0;i<n+1;i++)
    {
        g[i]=new int[n+1];
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            g[i][j]=e;
        }
    }
    for(int i=0;i<m;i++)
    {
        int x,y,r;
        cin>>x>>y>>r;
        g[x][y]=r;
        g[y][x]=r;
    }
    int start;
    cin>>start;
    prim(n+1,g);
    return 0;
}
