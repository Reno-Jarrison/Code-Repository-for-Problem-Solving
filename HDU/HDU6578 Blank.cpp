#include<bits/stdc++.h>
using namespace std;
const int maxn=105,mod=998244353;
int dp[2][maxn][maxn][maxn];
struct node
{
	int las,num;
	node(int las,int num):las(las),num(num){}
};
vector<node>vec[maxn];
void update(int& cur,int val)
{	cur=(cur+val)%mod; }
bool check(int i,int j,int k,int l)
{
	for(node x:vec[i])
	{
		int las=x.las,num=x.num;
		if(num==1&&j>=las) return false;
		if(num==2&&(j<las||k>=las)) return false;
		if(num==3&&(k<las||l>=las)) return false;
		if(num==4&&l<las) return false;
	}
	return true;
}
int main()
{
	int t,n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) vec[i].clear();
		for(int i=1;i<=m;i++)
		{
			int l,r,x;
			scanf("%d%d%d",&l,&r,&x);
			vec[r].push_back(node(l,x));
		}
		int tag=0,ans=0;
		memset(dp[0],0,sizeof(dp[0]));
		dp[tag][0][0][0]=1;
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=i;j++)
				for(int k=0;k<=j;k++)
					for(int l=0;l<=k;l++)
						dp[!tag][j][k][l]=0;
			for(int j=0;!j||j<i;j++)
				for(int k=0;!k||k<j;k++)
					for(int l=0;!l||l<k;l++)
					{
						int val=dp[tag][j][k][l];
						if(!check(i,j,k,l)||!val) continue;
						if(i==n)
						{	update(ans,val); continue; }
						update(dp[!tag][j][k][l],val);
						update(dp[!tag][i][k][l],val);
						update(dp[!tag][i][j][l],val);
						update(dp[!tag][i][j][k],val);
					}
			tag^=1;
		}
		printf("%d\n",ans);
	}
}