#include <iostream>
#include<vector>
using namespace std;

void disp(int **a ,int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool nextvertex(int i,int k,int **a,int n,vector<int> &x)
{
    for(int j=1;j<k;j++)
    {
        if(x[j]==i)
            return false;
    }
    if(a[x[k-1]][i]==0)
        return false;
    return true;
}
void hamiltonian(int k,int **a,int n,vector<int > &x,int start,bool &flag)
{
    if(k==n)
    {
        if(a[x[k]][start]==0)
            return;
        for(int i=1;i<=n;i++)
        {
            cout<<x[i]<<" ";
        }
        cout<<start<<" \n";
        flag=true;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        /*if(nextvertex(i,k+1,a,n,x))
            cout<<i<<" ";*/
        if(nextvertex(i,k+1,a,n,x))
        {
            x[k+1]=i;
            hamiltonian(k+1,a,n,x,start,flag);
        }
    }
}
int main()
{
   // int t;
    //cin>>t;
    //while(t--)
    //{
        int n=5;//,m;
        //cin>>n>>m;
        int **a{new int*[n+1]};
        /*for(int i=0;i<=n;i++)
        {
            a[i]=new int[n+1];
        }
        disp(a,n);
        for(int i=0;i<m;i++)
        {
            int z,y;
            cin>>z>>y;
            a[z][y]=1;
            a[y][z]=1;
        }*/
        bool flag=false;
        vector<int> x(n+1,0);
        int start=1;
        x[1]=start;
        a[0]=new int [n+1]{0,0,0,0,0,0};
        a[1]=new int [n+1]{0,0,1,1,0,1};
        a[2]=new int [n+1]{0,1,0,1,1,1};
        a[3]=new int [n+1]{0,1,1,0,1,0};
        a[4]=new int [n+1]{0,0,1,1,0,1};
        a[5]=new int [n+1]{0,1,1,0,1,0};
        disp(a,n);
        hamiltonian(1,a,n,x,start,flag);
        cout<<flag<<endl;
    //}
    return 0;
}
