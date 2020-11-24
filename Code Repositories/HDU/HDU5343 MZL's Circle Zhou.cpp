#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int maxn=2e5+5;
char s1[maxn],s2[maxn];
int bkt[maxn],rk[maxn];
ull dp[maxn],sum[26];
struct SAM
{
	int tot,las,nxt[maxn][26],fat[maxn],len[maxn];
	void init()
	{	tot=las=1,memset(nxt,0,sizeof(nxt)); }
	void insert(int to)
	{
		int p=las,np=las=++tot;
		len[np]=len[p]+1;
		while(p&&!nxt[p][to])
			nxt[p][to]=np,p=fat[p];
		if(!p) { fat[np]=1; return; }
		int q=nxt[p][to];
		if(len[q]==len[p]+1)
		{	fat[np]=q; return; }
		int nq=++tot;
		memcpy(nxt[nq],nxt[q],sizeof(nxt[q]));
		len[nq]=len[p]+1,fat[nq]=fat[q];
		fat[np]=fat[q]=nq;
		while(p&&nxt[p][to]==q)
			nxt[p][to]=nq,p=fat[p];
	}
	void solve1(int n)
	{
		memset(bkt,0,sizeof(bkt));
		for(int i=1;i<=tot;i++)
			bkt[len[i]]++;
		for(int i=1;i<=n;i++)
			bkt[i]+=bkt[i-1];
		for(int i=1;i<=tot;i++)
			rk[bkt[len[i]]--]=i;
		for(int i=tot;i;i--)
		{
			int pt=rk[i];
			dp[pt]=1;
			for(int i=0;i<26;i++)
				dp[pt]+=dp[nxt[pt][i]];
		}
		for(int i=0;i<26;i++)
			sum[i]=dp[nxt[1][i]];
	}
	ull solve2()
	{
		ull ans=1;
		for(int i=0;i<26;i++)
			if(!nxt[1][i]) ans+=sum[i];
		for(int i=1;i<=tot;i++)
		{
			ull cnt=len[i]-len[fat[i]];
			for(int j=0;j<26;j++)
				if(!nxt[i][j]) ans+=cnt*sum[j];
			ans+=cnt;
		}
		return ans;
	}
}sam1,sam2;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%s",s1,s2);
		int len1=strlen(s1),len2=strlen(s2);
		sam1.init(),sam2.init();
		for(int i=0;i<len1;i++)
			sam1.insert(s1[i]-'a');
		for(int i=0;i<len2;i++)
			sam2.insert(s2[i]-'a');
		sam2.solve1(len2);
		printf("%llu\n",sam1.solve2());
	}
}