#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
int l[maxn],r[maxn],del[maxn][2];
int main()
{
	int x,y,id,h,n;
	scanf("%d%d%d",&x,&y,&n);
	memset(l,0x3f,sizeof(l));
	memset(r,-1,sizeof(r));
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&id,&h);
		l[id]=min(l[id],h);
		r[id]=max(r[id],h);
	}
	for(int i=0;i<x;i++) if(r[i]!=-1) 
		del[l[i]][0]++,del[r[i]][1]++;
	ll cur=x-1,u=0,d=0;
	for(int i=0;i<x;i++)
		if(r[i]>0) cur+=r[i]*2,u++;
	ll ans=cur;
	for(int i=1;i<y;i++)
	{
		cur-=u*2;
		u-=del[i][1];
		d+=del[i-1][0];
		cur+=d*2;
		ans=min(ans,cur);	
	}
	printf("%lld",ans);
}