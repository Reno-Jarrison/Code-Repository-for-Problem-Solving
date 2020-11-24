#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+5,maxm=4e5+5;
const int mod=20071027;
struct Tire
{
	int tot,cnt[maxm],nxt[maxm][26];
	int newnode()
	{	return cnt[tot]=nxt[tot][0]=nxt[tot][1]=0,tot++; }
	void clear()
	{	tot=0,newnode(); }
	void insert(char *s)
	{
		int len=strlen(s);
		int pt=0;
		for(int i=0;i<len;i++)
		{
			if(!nxt[pt][s[i]-'a'])
				nxt[pt][s[i]-'a']=newnode();
			pt=nxt[pt][s[i]-'a'];
		}
		cnt[pt]++;
	}
}t;
char txt[maxn],pat[105];
int dp[maxn],ks;
int main()
{
	while(~scanf("%s",txt+1))
	{
		int n;
		scanf("%d",&n);
		t.clear();
		memset(t.cnt,0,sizeof(t.cnt));
		memset(t.nxt,0,sizeof(t.nxt));
		for(int i=1;i<=n;i++)
			scanf("%s",pat),t.insert(pat);
		memset(dp,0,sizeof(dp));
		int len=strlen(txt+1);
		dp[len+1]=1;
		for(int i=len;i;i--)
		{
			int pt=0;
			for(int j=i;j<=len;j++)
			{
				pt=t.nxt[pt][txt[j]-'a'];
				if(!pt) break;
				if(t.cnt[pt]) 
					dp[i]=(dp[i]+dp[j+1])%mod;
			}
		}
		printf("Case %d: %d\n",++ks,dp[1]);
	}
}	