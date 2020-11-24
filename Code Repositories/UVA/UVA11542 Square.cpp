#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=500;
int pcnt,prime[maxn];
bool vis[maxn+5],mat[maxn][105];
void getprime()
{
	for(int i=2;i<=maxn;i++)
	{
		if(!vis[i]) prime[++pcnt]=i;
		for(int j=1;i*prime[j]<=maxn;j++)
		{
			vis[i*prime[j]]=true;
			if(i%prime[j]==0) break;
		}
	}
}
int getrank(int r,int c)
{
	int rk=0;
	for(int i=1,j=1;i<=r&&j<=c;j++)
	{
		int pt=i;
		for(int k=i;k<=r;k++) 
			if(mat[k][j]) { pt=k; break; }
		if(!mat[pt][j]) continue;
		if(i!=pt) swap(mat[i],mat[pt]);
		for(int k=i+1;k<=r;k++) if(mat[k][j])
			for(int d=i;d<=c;d++) mat[k][d]^=mat[i][d];
		i++,rk++;
	}
	return rk;
}
int main()
{
	getprime();
	int t,n;
	ll x;
	scanf("%d",&t);
	while(t--)
	{
		memset(mat,0,sizeof(mat));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&x);
			for(int j=1;j<=pcnt;j++)
				while(x%prime[j]==0)
					x/=prime[j],mat[j][i]^=1;
		}
		printf("%lld\n",(1LL<<(n-getrank(pcnt,n)))-1);
	}
}