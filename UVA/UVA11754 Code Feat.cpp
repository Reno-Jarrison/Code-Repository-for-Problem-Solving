#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=15,limit=1e4;
ll x[maxn],k[maxn],y[maxn][105],z[maxn];
vector<ll>ans,sol;
void exgcd(ll a,ll b,ll& d,ll& x,ll& y)
{
	if(!b)	d=a,x=1,y=0;
	else exgcd(b,a%b,d,y,x),y-=a/b*x; 
} 
ll crt(int n,ll M)
{
	ll ans=0,m,d,x0,y0;
	for(int i=1;i<=n;i++)
	{
		m=M/x[i];
		exgcd(m,x[i],d,x0,y0);
		(ans+=m*x0*z[i])%=M;
	}
	return (ans+M)%M; 
}
void dfs(int step,int c,ll M)
{
	if(step>c)
		{ sol.push_back(crt(c,M)); return; }
	for(int i=1;i<=k[step];i++)
		z[step]=y[step][i],dfs(step+1,c,M);
}
void using_crt(int c,int s)
{
	ll M=1,tmp=0,cnt=0;
	for(int i=1;i<=c;i++) M*=x[i];
	sol.clear();
	dfs(1,c,M);
	sort(sol.begin(),sol.end());
	int len=sol.size();
	while(cnt<s)
	{
		for(int i=0;i<len&&cnt<s;i++)
		{
			ll w=tmp+sol[i];
			if(w>0) ans.push_back(w),cnt++;
		}
		tmp+=M;
	}
}
void using_enum(int c,int s,int pt)
{
	set<ll>val[maxn];
	for(int i=1;i<=c;i++)
	{
		if(i==pt) continue;
		for(int j=1;j<=k[i];j++) val[i].insert(y[i][j]); 
	}
	int cnt=0,t=0;
	while(cnt<s)
	{
		for(int i=1;i<=k[pt]&&cnt<s;i++)
		{
			ll w=x[pt]*t+y[pt][i];
			if(w==0) continue;
			bool flag=true;
			for(int j=1;j<=c;j++)
			{
				if(j==pt) continue;
				if(!val[j].count(w%x[j])) { flag=false; break; }
			}
			if(flag) ans.push_back(w),cnt++;
		}
		t++;
	} 
}
int main()
{
	int c,s;
	while(scanf("%d%d",&c,&s)!=EOF&&c&&s)
	{
		ll tot=1;
		int pt=1;
		ans.clear();
		for(int i=1;i<=c;i++)
		{
			scanf("%lld%lld",&x[i],&k[i]);
			tot*=k[i];
			for(int j=1;j<=k[i];j++) scanf("%lld",&y[i][j]);
			sort(y[i]+1,y[i]+k[i]+1);
			if(k[i]*x[pt]<k[pt]*x[i]) pt=i;
		}
		if(tot>limit) using_enum(c,s,pt);
		else using_crt(c,s);
		for(int i=0;i<s;i++) printf("%lld\n",ans[i]);
		puts("");
	}
}
