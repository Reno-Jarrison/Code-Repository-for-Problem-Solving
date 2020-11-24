#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int>sta[105];
int dp[105][100][100];
bool check(int s)
{	return !(s&(s<<1))&&!(s&(s<<2)); }
int count(int s)
{	
	int ans=0;
	while(s) ans+=s&1,s>>=1;
	return ans;
}
int main()
{
	int n,m,ans=0;
	char str[15];
	scanf("%d%d",&n,&m);
	sta[0].push_back(0);
	for(int i=1;i<=n;i++)
	{
		int s=0;
		scanf("%s",str);
		for(int j=0;j<m;j++)
		{
			s<<=1;
			if(str[j]=='P') s|=1;
		}
		for(int sub=s;sub;sub=(sub-1)&s)
			if(check(sub)) sta[i].push_back(sub);
		sta[i].push_back(0);
	}
	for(int i=0;i<(int)sta[1].size();i++)
		dp[1][i][0]=count(sta[1][i]);
	for(int i=2;i<=n;i++)
		for(int j=0;j<(int)sta[i].size();j++)
		{
			int s0=sta[i][j],cnt=count(s0);
			for(int k=0;k<(int)sta[i-1].size();k++)
			{
				int s1=sta[i-1][k];
				if(s0&s1) continue;
				for(int l=0;l<(int)sta[i-2].size();l++)
				{
					int s2=sta[i-2][l];
					if((s0&s2)||(s1&s2)) continue; 
					dp[i][j][k]=max(dp[i][j][k],dp[i-1][k][l]+cnt);
					ans=max(ans,dp[i][j][k]);
				}
			}
		}
	printf("%d\n",ans);
}