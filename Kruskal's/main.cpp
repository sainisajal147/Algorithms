#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
class disjoint
{
private:
    ll n;
public:
    vector<ll> Set;
    disjoint(ll n)
    {
        this->n=n;
        for(ll i=0;i<=n;i++)
        {
            Set.push_back(-1);
        }
    }
    void Union(ll u, ll v)
    {
        if(Set[u]<Set[v])
        {
            Set[u]=Set[u]+Set[v];
            Set[v]=u;
        }
        else
        {
            Set[v]=Set[u]+Set[v];
            Set[u]=v;
        }
    }
    int Find(ll u)
    {
        ll x=u;
        while(Set[x]>0)
        {
            x=Set[x];
        }
        return x;
    }
};
struct node
{
    ll l1,l2,w;
};
bool comp(node one,node two)
{
    return one.w<two.w;
}
void Kruskal(ll n,ll m,vector<node> &v)
{
    ll t[2][n-1]={0};
    sort(v.begin(),v.end(),comp);
    disjoint s(n);
    for(ll i=0,j=0;i<n-1 && j<m;j++)
    {
            ll x=v[j].l1,y=v[j].l2;
            if(s.Find(x)!=s.Find(y))
            {
                t[0][i]=x;t[1][i]=y;
                s.Union(s.Find(x),s.Find(y));
                i++;
            }
    }
   /* for(int i=1;i<=n;i++)
    {
        cout<<s.Set[i]<<" ";
    }
    cout<<endl;*/
    ll sum=0;
    for(ll i=0,j=0;j<n-1 && i<m;i++)
    {
        ll x=t[0][j],y=t[1][j];
        if(x==v[i].l1 && y==v[i].l2)
        {
            sum+=v[i].w;
            j++;
        }
    }
    cout<<sum<<endl;
}
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<node> v;
    for(ll i=0;i<m;i++)
    {
        node x;
        cin>>x.l1;
        cin>>x.l2;
        cin>>x.w;
        v.push_back(x);
    }
    //vector<node> v={{1,2,25},{1,6,5},{2,3,12},{2,7,10},{3,4,8},{4,5,16},{5,6,20},{5,7,18},{4,7,14}};
    Kruskal(n,m,v);
    /*for(int i=0;i<m;i++)
    {
        cout<<v[i].l1<<" "<<v[i].l2<<" "<<v[i].w<<endl;
    }*/
    return 0;
}
