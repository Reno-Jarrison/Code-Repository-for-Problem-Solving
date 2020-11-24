#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=1e5+5;
char s[maxn];
int id[maxn],l[maxn],r[maxn];
ll sqr(int x) {	return 1LL*x*x; }
ll len(int x) { return sqr(r[x]-l[x]+1); }
int main()
{
	int t,ks=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		int n=strlen(s+1);
		int idx=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]!=s[i-1])
				l[++idx]=i;
			r[idx]=i,id[i]=idx;
		}
		l[0]=1,r[0]=0,l[idx+1]=n+1,r[idx+1]=n;
		ll init=0,ans=0;
		for(int i=1;i<=idx;i++) init+=len(i);
		for(int i=1;i<=n;i++)
		{
			ll tmp=init;
			int x=id[i];
			if(i==l[x]&&i==r[x])
				tmp+=sqr(r[x+1]-l[x-1]+1)-1-len(x-1)-len(x+1);
			else if(i==l[x])
				tmp+=sqr(i-l[x-1]+1)+sqr(r[x]-i)-len(x)-len(x-1);
			else if(i==r[x])
				tmp+=sqr(r[x+1]-i+1)+sqr(i-l[x])-len(x)-len(x+1);
			else tmp+=sqr(i-l[x])+sqr(r[x]-i)+1-len(x);
			ans=max(ans,tmp);
		}
		printf("Case #%d: %lld\n",++ks,max(ans,init));
	}
}