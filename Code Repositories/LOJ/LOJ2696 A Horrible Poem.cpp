#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int maxn=5e5+5,base=233;
ull hval[maxn],powb[maxn]={1};
int tot,p[maxn],mpf[maxn];
char s[maxn];
ull gethash(int l,int r)
{	return hval[r]-hval[l-1]*powb[r-l+1]; }
void init(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(!mpf[i]) p[++tot]=i,mpf[i]=i;
		for(int j=1;i*p[j]<=n;j++)
		{
			mpf[i*p[j]]=p[j];
			if(i%p[j]==0) break;
		}
	}
}
bool check(int l,int r,int len)
{	return gethash(l,r-len)==gethash(l+len,r); }
int main()
{
	int n,q,l,r;
	scanf("%d%s",&n,s+1),init(n);
	for(int i=1;i<=n;i++)
		hval[i]=hval[i-1]*base+s[i],powb[i]=powb[i-1]*base;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&l,&r);
		int len=r-l+1,ans=len;
		if(check(l,r,1)) ans=len=1;
		while(len>1)
		{
			int pf=mpf[len];
			if(check(l,r,ans/pf)) ans/=pf;
			len/=pf;
		}
		printf("%d\n",ans);
	}
}