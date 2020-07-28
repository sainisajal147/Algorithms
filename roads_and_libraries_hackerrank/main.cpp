#include <iostream>
#include<queue>
#include<vector>
using namespace std;
typedef long long int ll;
void dfs(ll n,vector<ll> g[],ll i,ll *visited,ll &x)
{
    if(visited[i]==0)
    {
        x++;
        visited[i]=1;
        for(int v=0;v<g[i].size();v++)
        {
            dfs(n,g,g[i][v],visited,x);
        }
    }
}
int main()
{
            ll n,p;
            cin>>n>>p;
            ll * visited=new ll[n];
            for(ll i=0;i<n;i++)
            {
                visited[i]=0;
            }
            vector<ll> g[n];
            for(ll i=0;i<p;i++)
            {
                ll x,y;
                cin>>x>>y;
                g[x].push_back(y);
                g[y].push_back(x);
            }
            ll r=n*(n-1)/2;
            for(ll i=0;i<n;i++)
            {
                ll x=0;
                if(visited[i]==0)
                {
                    dfs(n,g,i,visited,x);
                    if(x>1)
                        r-=x*(x-1)/2;
                }
            }
            cout<<r<<endl;
    return 0;
}
