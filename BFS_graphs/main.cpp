#include <iostream>
#include<queue>
using namespace std;
struct node{
int data;
node * next;
};
node * getnode(int data)
{
    node * newn=new node();
    newn->data=data;
    newn->next=NULL;
    return newn;
}
void Insert(node * &head,int data)
{
    if(head==NULL)
        {
            head=getnode(data);
            return ;
        }
    else
        {
            node * temp=head;
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=getnode(data);
        }
}
void BFS(int i , node **G,int n)
{
    int visited[n+1]={0};
    queue<int> q;
    cout<<i<<" ";
    q.push(i);
    visited[i]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        node * temp=G[u];
        while(temp)
        {
            if(visited[temp->data]==0)
            {
                //cout<<temp->data<<" ";
                q.push(temp->data);
                visited[temp->data]=1;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<visited[i]<<" ";
    }
}
void disp(node **G,int n)
{
    for(int i=1;i<=n;i++)
    {
        node * temp=G[i];
        cout<<i<<"->";
        while(temp)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"\n";
    }
}
void bfs(int n ,int **g,int i)
{
    cout<<i<<" ";
    queue<int> q;
    int visited[n+1]={0};
    q.push(i);
    visited[i]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v=1;v<=n;v++)
        {
            if(g[u][v]==1 && visited[v]==0)
            {
                cout<<v<<" ";
                visited[v]=1;
                q.push(v);
            }
        }
    }
}
void dfs(int n,int **g,int i,int *visited)
{
    if(visited[i]==0)
    {
        cout<<i<<" ";
        visited[i]=1;
        for(int v=1;v<=n;v++)
        {
            if(g[i][v]==1)
                dfs(n,g,v,visited);
        }
    }
}
int main()
{
    cout<<"enter maximum number of vertices:\n";
    int n;
    cin>>n;
    int * visited=new int[n+1];
    for(int i=0;i<=n;i++)
    {
        visited[i]=0;
    }
    int **g=new int *[n+1];
    for(int i=0;i<=n;i++)
    {
        g[i]=new int[n+1];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            g[i][j]=0;
        }
    }
    node **G=NULL;
    G=new node *[n+1];
    for(int i=0;i<=n;i++)
    {
        G[i]=NULL;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<"Insert the number of adjacent nodes of vertex "<<i<<endl;
        int x;
        cin>>x;
        for(int j=1;j<=x;j++)
        {
            cout<<"Insert the "<<j<<" vertex of "<<i<<endl;
            int y;
            cin>>y;
            Insert(G[i],y);
            g[i][y]=1;
        }
    }
    disp(G,n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
    //BFS(1,G,n);
    bfs(n,g,4);
    cout<<endl;
    dfs(n,g,1,visited);
    return 0;
}
