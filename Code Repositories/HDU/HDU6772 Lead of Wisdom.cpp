#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ans;
int a[55],b[55],c[55],d[55],k;
int mxv[55][4];
vector<int>vec[55];
void dfs(int id,int sa,int sb,int sc,int sd)
{
	if(id>k) 
	{ 
		ll sum=1LL*(100+sa)*(100+sb)*(100+sc)*(100+sd);
		ans=max(ans,sum); 
		return; 
	}
	ll sum=1LL*(100+sa+mxv[id][0])*(100+sb+mxv[id][1])*
			   (100+sc+mxv[id][2])*(100+sd+mxv[id][3]);
	if(sum<ans) return;
	for(int x:vec[id])
		dfs(id+1,sa+a[x],sb+b[x],sc+c[x],sd+d[x]);
	if(!vec[id].size())
		dfs(id+1,sa,sb,sc,sd);
}
int main()
{
	int t,n,e;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=k;i++)
			vec[i].clear();
		memset(mxv,0,sizeof(mxv));
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d%d%d",&e,&a[i],&b[i],&c[i],&d[i]);
			vec[e].push_back(i);
			mxv[e][0]=max(mxv[e][0],a[i]),mxv[e][1]=max(mxv[e][1],b[i]);
			mxv[e][2]=max(mxv[e][2],c[i]),mxv[e][3]=max(mxv[e][3],d[i]);
		}
		for(int i=k-1;i;i--)
			for(int j=0;j<4;j++)
				mxv[i][j]+=mxv[i+1][j];
		ans=0,dfs(1,0,0,0,0);
		printf("%lld\n",ans);
	}
}