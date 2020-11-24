#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
char txt[maxn][maxn/10],pat[maxn];
struct ACAM
{
	int tot,cnt[maxn],nxt[maxn][26],fail[maxn];
	void clear()
	{	tot=0,newnode(); }
	int newnode()
	{	
		memset(nxt[tot],0,sizeof(nxt[tot]));
		return cnt[tot]=fail[tot]=0,tot++;
	}
	void insert(char *s)
	{
		int len=strlen(s),pt=0;
		for(int i=0;i<len;i++)
		{
			int to=s[i]-'a';
			if(!nxt[pt][to])
				nxt[pt][to]=newnode();
			pt=nxt[pt][to];
		}
		cnt[pt]++;
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
				if(v) fail[v]=nxt[f][i],que.push(v);
				else nxt[u][i]=nxt[f][i];
			}
		}
	}
	int run(char *s)
	{
		int len=strlen(s),pt=0,ans=0;
		for(int i=0;i<len;i++)
		{
			int to=s[i]-'a';
			pt=nxt[pt][to];
			for(int x=pt;x;x=fail[x])
				ans+=cnt[x];
		}
		return ans;
	}
}acam;
int main()
{
	int t,n,m;
	scanf("%d",&t);
	while(t--)
	{
		acam.clear();
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%s",txt[i]);
		for(int i=1;i<=m;i++)
			scanf("%s",pat),acam.insert(pat);
		acam.getfail();
		for(int i=1;i<=n;i++)
			printf("%d\n",acam.run(txt[i]));
	}
}