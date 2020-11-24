#include<iostream>
#include<cstring>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;
int g[55][55],vis[55],dist[55],n;
const int mod=1e9+7;
int main()
{
	char s[55];
	while(scanf("%d",&n)!=EOF)
	{
		memset(vis,0,sizeof(vis));
		memset(dist,inf,sizeof(dist));
		for(int i=0;i<n;i++)
		{
			scanf("%s",s);
			for(int j=0;j<n;j++)
				if(s[j]=='0') g[i][j]=inf;
				else g[i][j]=s[j]-'0';
		}
		dist[0]=0;
		while(1)
		{
			int next=-1,minm=inf;
			for(int i=0;i<n;i++)
				if(!vis[i]&&dist[i]<minm)
					next=i,minm=dist[i];
			if(next==-1) break;
			vis[next]=1;
			for(int i=0;i<n;i++)
				if(!vis[i]&&dist[i]>dist[next]+g[next][i])
					dist[i]=dist[next]+g[next][i];
		}
		ll ans=1;
		for(int i=1;i<n;i++)
		{
			ll cnt=0;
			for(int j=0;j<n;j++)
				if(dist[i]==dist[j]+g[j][i]) cnt++;
			ans*=cnt,ans%=mod;
		} 
		printf("%lld\n",ans);
	}
}