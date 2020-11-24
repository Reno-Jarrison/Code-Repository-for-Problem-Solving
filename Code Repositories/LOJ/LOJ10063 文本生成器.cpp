#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5,mod=1e4+7;
int dp[105][maxn];
struct ACAM
{
	int tot,tag[maxn],nxt[maxn][26],fail[maxn];
	void insert(char *s)
	{
		int len=strlen(s),pt=0;
		for(int i=0;i<len;i++)
		{
			int to=s[i]-'A';
			if(!nxt[pt][to])
				nxt[pt][to]=++tot;
			pt=nxt[pt][to];
		}
		tag[pt]=1;
	}
	void getfail()
	{
		queue<int>que;
		for(int i=0;i<26;i++)
			if(nxt[0][i]) que.push(nxt[0][i]);
		while(!que.empty())
		{
			int u=que.front(); que.pop();
			for(int i=0;i<26;i++)
			{
				int v=nxt[u][i],f=fail[u];
				if(v) fail[v]=nxt[f][i],tag[v]|=tag[fail[v]],que.push(v);
				else nxt[u][i]=nxt[f][i];
			}
		}
	}
	int solve(int m)
	{
		dp[0][0]=1;
		int ans=1;
		for(int i=1;i<=m;i++,ans=ans*26%mod)
			for(int j=0;j<=tot;j++)
				for(int k=0;k<26;k++) if(!tag[nxt[j][k]])
					(dp[i][nxt[j][k]]+=dp[i-1][j])%=mod;
		for(int i=0;i<=tot;i++)
			ans=(ans-dp[m][i]+mod)%mod;
		return ans;
	}
}acam;
char s[105];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",s),acam.insert(s);
	acam.getfail();
	printf("%d\n",acam.solve(m));
}