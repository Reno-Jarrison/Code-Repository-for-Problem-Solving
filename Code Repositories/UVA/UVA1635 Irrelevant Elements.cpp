#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e5,maxm=1e4;
int cnt,vis[maxn+5],id[maxn+5],prime[maxm];
int p[maxm],tot[maxm],tmp[maxm],ans[maxn];
void getprime()
{
	for(int i=2;i<=maxn;i++)
	{
		if(!vis[i]) prime[++cnt]=i,id[i]=cnt;
		for(int j=1;i*prime[j]<=maxn;j++)
		{
			vis[i*prime[j]]=true;
			if(i%prime[j]==0) break;
		}
	}
}
void update(int x,int flag,int num)
{
	for(int i=1;i<=num;i++)
		while(x%p[i]==0)
			x/=p[i],tmp[i]+=flag;
}
int main()
{
	getprime();
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		memset(tot,0,sizeof(tot));
		memset(tmp,0,sizeof(tmp));
		int num=0,k=0;
		for(int i=1;1LL*prime[i]*prime[i]<=m;i++)
			if(m%prime[i]==0)
			{
				p[++num]=prime[i];
				while(m%prime[i]==0)
					m/=prime[i],tot[num]++;
			}
		if(m>1) p[++num]=m,tot[num]=1;
		for(int i=1;i<=n-1;i++)
		{
			update(n-i,1,num),update(i,-1,num);
			bool flag=true;
			for(int j=1;j<=num;j++)
				if(tmp[j]<tot[j])
					{ flag=false; break; }
			if(flag) ans[++k]=i+1;
		}
		printf("%d\n",k);
		if(!k) puts("");
		for(int i=1;i<=k;i++)
			printf("%d%c",ans[i],i==k?'\n':' ');
	}
}