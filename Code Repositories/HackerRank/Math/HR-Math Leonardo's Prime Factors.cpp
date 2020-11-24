#include<iostream>
#define ll long long
using namespace std;
int pcnt,p[20],vis[100];
ll mul[20]={1};
int main()
{
    for(int i=2;i<100;i++)
    {
        if(!vis[i]) p[++pcnt]=i;
        for(int j=1;i*p[j]<100;j++)
        {
            vis[i*p[j]]=true;
            if(i%p[j]==0) break;
        }
    }
    for(int i=1;i<=15;i++) mul[i]=mul[i-1]*p[i];
    int t; ll n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int ans=0;
        for(int i=1;i<=15;i++)
            if(n>=mul[i]) ans=i;
        cout<<ans<<endl;
    }
}