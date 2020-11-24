#include<bits/stdc++.h>
using namespace std;
const int maxn=5e4+5;
struct node
{	int p,a; }c[maxn];
bool operator ==(const node& x,const node& y)
{	return x.p==y.p&&x.a==y.a; }
bool operator <(const node& x,const node& y)
{	return x.p>y.p||(x.p==y.p&&x.a>y.a); }
int stk[maxn],tag[maxn];
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d",&c[i].p,&c[i].a),tag[i]=0;
		sort(c+1,c+n+1);
		for(int i=1;i<=n;i++)
			if(c[i]==c[i-1]) tag[i]=tag[i-1]=1;
		int pt=0,ans=0;
		for(int i=1;i<=n;i++)
		{
			if(pt&&c[i].a<=c[stk[pt]].a) continue;
			while(pt>=2)
			{
				int j=stk[pt],k=stk[pt-1];
				int p1=c[j].p-c[i].p,p2=c[k].p-c[j].p;
				int a1=c[i].a-c[j].a,a2=c[j].a-c[k].a;
				if(1LL*p1*a2>1LL*p2*a1) break;
				pt--;
			}
			stk[++pt]=i;
		}
		for(int i=1;i<=pt;i++)
			ans+=!tag[stk[i]];
		printf("%d\n",ans);
	}
}