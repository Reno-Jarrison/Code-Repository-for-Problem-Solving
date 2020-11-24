#include<iostream>
#define ll long long
using namespace std;
const int maxn=1e3+5;
const ll mod=1e9;
ll c[maxn][maxn]={1};
int main()
{
    for(int i=1;i<maxn;i++)
    {
        c[i][0]=1;
        for(int j=1;j<=i;j++)
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
    }
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<=n;i++)
            cout<<c[n][i]<<" ";
        puts("");
    }
}