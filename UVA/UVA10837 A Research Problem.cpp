#include<cstdio>
#include<vector>
#define ll long long
using namespace std;
const int maxn=2e4+5;;
int pcnt,p[maxn],vis[maxn],tag[maxn],ks;
ll ans,n;
vector<int>v;
void getprime()
{
	for(int i=2;i<maxn;i++)
	{
		if(!vis[i]) p[++pcnt]=i;
		for(int j=1;i*p[j]<maxn;j++)
		{
			vis[i*p[j]]=1;
			if(i%p[j]==0) break;
		}
	}
}
bool judge(ll x)
{
	for(ll i=2;i*i<=x;i++)
		if(x%i==0) return false;
	for(int i=0;i<v.size();i++)
		if(x==v[i]&&tag[i]) return false;
	return true;
}
void dfs(int step,ll tmp,ll r)
{
	if(step==v.size())
	{
		if(r==1) ans=min(ans,tmp);
		else if(judge(r+1))
			ans=min(ans,tmp*(r+1));
		return;
	}
	dfs(step+1,tmp,r);
	if(r%(v[step]-1)) return;
	tag[step]=1;
	tmp*=v[step],r/=(v[step]-1);
	dfs(step+1,tmp,r);
	while(r%v[step]==0)
		tmp*=v[step],r/=v[step],dfs(step+1,tmp,r);
	tag[step]=0;
}
int main()
{
	getprime();
	while(scanf("%lld",&n)&&n)
	{
		v.clear(),ans=1e12;
		ll tmp=n;
		for(int i=1;i<=pcnt;i++)
			if(tmp%(p[i]-1)==0)
				v.push_back(p[i]);
		dfs(0,1,n);
		printf("Case %d: %lld %lld\n",++ks,n,ans);
	}
}