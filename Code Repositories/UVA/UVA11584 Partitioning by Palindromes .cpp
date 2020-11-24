#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
char s[maxn];
int dp[maxn],tag[maxn][maxn];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		int n=strlen(s+1);
		memset(tag,0,sizeof(tag));
		for(int i=1;i<=n;i++) 
			tag[i][i]=tag[i][i-1]=1;
		for(int i=2;i<=n;i++)
			for(int l=1,r=l+i-1;r<=n;l++,r++)
				if(s[l]==s[r]) tag[l][r]=tag[l+1][r-1];
		memset(dp,0x3f,sizeof(dp));
		for(int i=1;i<=n;i++)
		{
			if(tag[1][i]) dp[i]=1;
			else for(int j=2;j<=i;j++)
				if(tag[j][i]) dp[i]=min(dp[i],dp[j-1]+1);
		}
		printf("%d\n",dp[n]);
	}
}