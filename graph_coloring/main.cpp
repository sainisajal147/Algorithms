#include <iostream>
#include<vector>
#include<string>
using namespace std;

void disp(vector<vector<int>> v,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool B(vector<vector<int>> v,int n,string s, string ans,int i,int j)
{
    for(int row=0;row<i;row++)
    {
        if(v[i][row]==1 and row<ans.size())
            {
                if(s[j]==ans[row])
                return false;
            }
    }
    return true;
}
void graph_coloring(vector<vector<int>> v,int n,string s, string ans,int i)
{
    if(i==n)
    {
        cout<<ans<<endl;
        ans.clear();
        return;
    }
    for(int j=0;j<s.size();j++)
    {
        if(B(v,n,s,ans,i,j))
        {
            ans.push_back(s[j]);
            graph_coloring(v,n,s,ans,i+1);
            ans.pop_back();
        }
    }
}
int main()
{
    int n=5;
    vector<vector<int>> v(n,vector<int> (n,0));
    v[0][1]=1,v[0][4]=1;
    v[1][0]=1,v[1][2]=1,v[1][4]=1;
    v[2][1]=1,v[2][3]=1,v[2][4]=1;
    v[3][2]=1,v[3][4]=1;
    v[4][0]=1,v[4][1]=1,v[4][2]=1,v[4][3]=1;
    disp(v,n);
    string s="RGB",ans;
    graph_coloring(v,n,s,ans,0);
    return 0;
}
