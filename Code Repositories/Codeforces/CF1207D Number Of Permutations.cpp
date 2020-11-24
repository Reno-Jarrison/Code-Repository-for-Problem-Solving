#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=3e5+5;
ll fac[maxn],visa[maxn],visb[maxn],ans,mod=998244353;
struct node { int a,b; }p[maxn];
bool cmp(node x,node y)
{	return x.a<y.a||(x.a==y.a&&x.b<y.b); } 
int main()
{
	int n;
	fac[0]=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&p[i].a,&p[i].b);
		fac[i]=fac[i-1]*i%mod;
		visa[p[i].a]++,visb[p[i].b]++;
	}
	ans=fac[n];
	ll dela=1,delb=1;
	for(int i=1;i<=n;i++)
		dela=dela*fac[visa[i]]%mod,delb=delb*fac[visb[i]]%mod;
	ans=((ans-dela-delb)%mod+mod)%mod;
	sort(p+1,p+n+1,cmp);
	ll cnt=1,lasta=0,lastb=0,tmp=1;
	bool flag=true;
	for(int i=1;i<=n;i++)
	{
		if(p[i].b<lastb) { flag=false; break; }
		else if(p[i].a==lasta&&p[i].b==lastb) cnt++;
		else cnt=1;
		tmp=tmp*cnt%mod;
		lasta=p[i].a,lastb=p[i].b;
	}
	if(flag) ans=((ans+tmp)%mod+mod)%mod;
	cout<<ans;
}

