#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int e[20][20],n;
bool flag[20],tag;
void dfs(int u,int k,int f,bool isrt)
{
	int cnt=0;
	flag[u]=true;
	for(int i=1;i<=n;i++) if(i!=u&&i!=f)
	{
		if(!e[u][i]||(k&(1<<(i-1)))) continue;
		cnt++;
		if(flag[i]||cnt-isrt>1) { tag=false; return; }
		else dfs(i,k,u,false);
	}
}
int getnum(int x)
{
	int ans=0;
	while(x) ans+=x&1,x>>=1;
	return ans;
}
int main()
{
	int u,v,ks=0;
	while(scanf("%d",&n)&&n)
	{
		int ans=n;
		memset(e,0,sizeof(e));
		while(scanf("%d%d",&u,&v)&&u!=-1)
			e[u][v]=e[v][u]=true;
		for(int i=0;i<(1<<n);i++)
		{
			int cnt=0,num=getnum(i);
			memset(flag,0,sizeof(flag)),tag=true;
			for(int j=1;j<=n;j++)
				if(!flag[j]&&!(i&(1<<(j-1))))
					cnt++,dfs(j,i,0,true);
			if(tag&&num>=cnt-1) ans=min(ans,num);
		}
		printf("Set %d: Minimum links to open is %d\n",++ks,ans);
	}
}
