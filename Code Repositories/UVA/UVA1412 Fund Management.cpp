#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5,maxm=5e7;
int k[8],pow9[9]={1},sta[maxn],mp[maxm];
int opt[105][maxn],las[105][maxn],pre[maxn][15],suc[maxn][15];
double p[105][8],c,dp[105][maxn];
char s[8][10];
int count(int x)
{
	int ans=0;
	while(x) ans+=x%9,x/=9;
	return ans;
}
bool check(int x,int n,int tot)
{
	int cnt=0;
	for(int j=0;j<n;j++)
	{
		if(x%9>k[j]) return false;
		cnt+=x%9,x/=9;
	}
	return cnt<=tot;
}
void update(int step,int cur,int nxt,double val,int o)
{
	if(val<=dp[step+1][nxt]) return;
	dp[step+1][nxt]=val;
	opt[step+1][nxt]=o;
	las[step+1][nxt]=cur;
}
void print(int step,int sta)
{
	if(!step) return;
	print(step-1,las[step][sta]);
	if(!opt[step][sta]) puts("HOLD");
	if(opt[step][sta]>0) printf("BUY %s\n",s[opt[step][sta]-1]);
	if(opt[step][sta]<0) printf("SELL %s\n",s[-opt[step][sta]-1]);
}
int main()
{
	int m,n,tot,x,idx;
	for(int i=1;i<=8;i++)
		pow9[i]=pow9[i-1]*9;
	while(~scanf("%lf%d%d%d",&c,&m,&n,&tot))
	{
		for(int i=0;i<n;i++)
		{
			scanf("%s%d%d",s[i],&x,&k[i]);
			for(int j=0;j<m;j++)
				scanf("%lf",&p[j][i]),p[j][i]*=x;
		}
		idx=0;
		memset(pre,-1,sizeof(pre));
		memset(suc,-1,sizeof(suc));
		for(int i=0;i<pow9[n];i++)
			if(check(i,n,tot)) sta[++idx]=i,mp[i]=idx;
		for(int i=1;i<=idx;i++)
		{
			int s0=sta[i],cnt=count(s0);
			for(int j=0;j<n;j++)
			{
				int bit=s0%9;
				if(bit>0) pre[i][j]=mp[sta[i]-pow9[j]];
				if(bit<k[j]&&cnt<tot) suc[i][j]=mp[sta[i]+pow9[j]];
				s0/=9;
			}
		}
		for(int i=0;i<=m;i++)
			for(int j=1;j<=idx;j++)
				dp[i][j]=-1e12;
		dp[0][1]=c;
		for(int i=0;i<=m;i++)
			for(int j=1;j<=idx;j++)
			{
				double val=dp[i][j];
				if(val<-1e-8) continue;
				update(i,j,j,val,0);
				for(int l=0;l<n;l++)
				{
					//printf("%d %d  %d\n",i,j,l);
					if(~suc[j][l]&&val>=p[i][l]-1e-3)
						update(i,j,suc[j][l],val-p[i][l],l+1);
					if(~pre[j][l])
						update(i,j,pre[j][l],val+p[i][l],-l-1);
				}
			}
		printf("%.2lf\n",dp[m][1]);
		print(m,1);
	}
}