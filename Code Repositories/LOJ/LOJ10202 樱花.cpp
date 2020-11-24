#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+5,mod=1e9+7;
int cnt,p[maxn],tot[maxn],vis[maxn];
int main()
{
	int n;
	ll ans=1;
	cin>>n;
	for(ll i=2;i<=n;i++)
	{
		if(!vis[i]) 
		{
			p[++cnt]=i;
			ll k=0,tmp=i;
			while(n>=tmp) k+=n/tmp,tmp*=i;
			(ans*=(k<<1)+1)%=mod;
		}
		for(int j=1;j<=cnt&&i*p[j]<=n;j++)
		{
			vis[i*p[j]]=1;
			if(i%p[j]==0) break;
		}
	}
	cout<<ans;
}