#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5,mod=998244353;
int a[maxn],b[maxn],idx[maxn],pos[maxn];
int main()
{
	int t,n,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),idx[a[i]]=i,pos[a[i]]=0;
		for(int i=1;i<=k;i++)
			scanf("%d",&b[i]),pos[b[i]]=i;
		int ans=1;
		for(int i=1;i<=k;i++)
		{
			int id=idx[b[i]],cnt=0;
			if(id>1&&pos[a[id-1]]<i) cnt++;
			if(id<n&&pos[a[id+1]]<i) cnt++;
			if(!cnt) ans=0;
			else if(cnt==2) ans=ans*2%mod;
		}
		printf("%d\n",ans);
	}
}