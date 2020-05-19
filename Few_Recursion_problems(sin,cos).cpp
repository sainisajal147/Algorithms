#include <iostream>
#include <vector>
using namespace std;

int sumn(int n)
{
    if(n>0)
        return n+sumn(n-1);
}
int fact(int n)
{
    if(n==0)
        return 1;
    else
        return fact(n-1)*n;
}
float power(float m, int n)
{
    if(n==0)
    return 1.0;
    else
        return 1.0*m*power(m,n-1);
}
int Power(int m, int n)     //less number of activation records
{
    if(n==0)
    return 1;
    else if(n%2==0)
        return Power(m*m,n/2);
    else
        return m*Power(m*m,n/2);
}
float tay(int x, int n) //o(n^2)
{
    if(n==0)
        return 1.0;
    else
    {
        return tay(x,n-1)+(power(x,n)*1.0)/fact(n);
    }
}
float tayh(int x, int n)    //using Horner's rule in o(n)
{
    static float s=1.0;
    if(n==0)
        return s;
    s=1+(x*1.0/n)*s;
    return tayh(x,n-1);
}
float sin(float x,int n)
{
    if(n==0)
        return x;
    else if(n%2==0)
        return sin(x,n-1)+(power(x,(2*n+1))*1.0)/fact(2*n+1);
    else
        return sin(x,n-1)-(power(x,(2*n+1))*1.0)/fact(2*n+1);
}
float cos(float x,int n)
{
    if(n==0)
        return 1.0;
    else if(n%2==0)
        return cos(x,n-1)+(power(x,(2*n))*1.0)/fact(2*n);
    else
        return cos(x,n-1)-(power(x,(2*n))*1.0)/fact(2*n);
}
int fib(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    if(n>1)
        return fib(n-1)+fib(n-2);
}
int ncr(int n,int r)
{
    if(r==0 || n==r)
        return 1;
    else
    {
        return ncr(n-1,r-1)+ncr(n-1,r);
    }
}
void p(vector<int> a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
}
/*void mov(vector<int> *a,vector<int> *b)
{
    (*b).insert((*b).begin()+0,(*a)[0]);
    (*a).erase((*a).begin()+0);
}*/
void mov(vector<int> &a,vector<int> &b)
{
    b.insert(b.begin()+0,a[0]);
    a.erase(a.begin()+0);
}
int number=0;
void TOH(int n,vector<int > &a,vector<int > &b,vector<int> &c)
{
    if(n>0)
    {
        TOH(n-1,a,c,b);
        mov(a,c);
        ::number++;
        TOH(n-1,b,a,c);
    }
}
int f (int &x, int z)

{

        z = z -1;

if (z==0) return 1;

x = x + 1;

return f(x,z) * x;

        }
int main()
{
   /* vector<int > a;
    vector<int> b;
    vector<int> c;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        a.push_back(i);
    }
    TOH(n,a,b,c);
    cout<<::number<<"\n";
    p(c);*/
    /*int p=5;
    cout<<f(p,p);*/
    int k;
    for(k=1;k<5;++k)
        cout<<k;
    return 0;
}
