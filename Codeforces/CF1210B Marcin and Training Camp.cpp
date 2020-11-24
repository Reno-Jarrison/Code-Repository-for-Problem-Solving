#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=7e3+5;
map<ll,ll>mp;
ll a[maxn],b[maxn],sum[maxn],ans;
bool vis[maxn];
int main()
{
	int n; 
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i],mp[a[i]]++;
	for(int i=1;i<=n;i++) 
		if(mp[a[i]]>1) ans+=b[i],vis[i]=true;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		for(int j=1;j<=n;j++)
			if(vis[j]&&(a[i]|a[j])==a[j]) 
			{ 	ans+=b[i]; break; }
	}
	cout<<ans;
}

