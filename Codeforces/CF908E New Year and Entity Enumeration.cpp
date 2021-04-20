#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e3+5,mod=1e9+7;
char s[maxn];
ll sti[maxn][maxn],bel[maxn],sta[maxn];
void init(int n)
{
	sti[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
		{
			sti[i][j]=(sti[i-1][j]*j+sti[i-1][j-1])%mod;
			bel[i]=(bel[i]+sti[i][j])%mod;
		}
}
int main()
{
	int n,m;
	scanf("%d%d",&m,&n);
	init(m);
	map<ll,int>mp;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
			if(s[j]=='1')
				sta[j]|=1ll<<(i-1);
	}
	for(int i=1;i<=m;i++) mp[sta[i]]++;
	ll ans=1;
	for(auto x:mp) 
		ans=ans*bel[x.second]%mod;
	printf("%lld\n",ans);
}