#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+5;
char s[2][maxn];
int dp[maxn][maxn],l[2][26],r[2][26],vis[26];
int cnt(int id1,int id2)
{
	int ans=0;
	for(int i=0;i<26;i++)
	{
		if(l[0][i]>id1&&l[1][i]>id2) continue;
		if(id1>=r[0][i]&&id2>=r[1][i]) continue;
		ans++;
	}
	return ans;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%s",s[0]+1,s[1]+1);
		int n[2]={strlen(s[0]+1),strlen(s[1]+1)},idx;
		memset(l,0x3f,sizeof(l));
		memset(r,0,sizeof(r));
		memset(vis,0,sizeof(vis));
		for(int i=0;i<=1;i++)
			for(int j=1;j<=n[i];j++)
			{
				idx=s[i][j]-'A',vis[idx]=1;
				l[i][idx]=min(l[i][idx],j);
				r[i][idx]=max(r[i][idx],j);
			}
		for(int i=0;i<=n[0];i++)
			for(int j=0;j<=n[1];j++)
			{
				if(i||j) dp[i][j]=0x3f3f3f3f;
				if(i) dp[i][j]=min(dp[i][j],dp[i-1][j]);
				if(j) dp[i][j]=min(dp[i][j],dp[i][j-1]);
				dp[i][j]+=cnt(i,j);
			}
		printf("%d\n",dp[n[0]][n[1]]);
	}
}