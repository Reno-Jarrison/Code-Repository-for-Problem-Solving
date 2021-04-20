#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
char s[maxn],t[maxn];
int k[maxn],tlen[maxn];
vector<int>pos[maxn];
struct ACAM
{
	int	tot,tag[maxn],nxt[maxn][26],fail[maxn],las[maxn];
	void insert(char *s,int id)
	{
		int len=strlen(s),pt=0;
		for(int i=0;i<len;i++)
		{
			int to=s[i]-'a';
			if(!nxt[pt][to])
				nxt[pt][to]=++tot;
			pt=nxt[pt][to];
		}
		tag[pt]=id,tlen[id]=len;
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
				int v=nxt[u][i],f=fail[u],fnxt=nxt[f][i];
				if(v) 
				{
					fail[v]=fnxt,que.push(v);
					las[v]=tag[fnxt]?fnxt:las[fnxt];
				}
				else nxt[u][i]=fnxt;
			}
		}
	}
	void find(char* s)
	{
		int len=strlen(s),pt=0;
		for(int i=0;i<len;i++)
		{
			int to=s[i]-'a';
			pt=nxt[pt][to];
			if(tag[pt])
				pos[tag[pt]].push_back(i);
			int tmp=las[pt];
			while(tmp)
				pos[tag[tmp]].push_back(i),tmp=las[tmp];
		}
	}
}acam;
int main()
{
	int n;
	scanf("%s%d",s,&n);
	for(int i=1;i<=n;i++)
		scanf("%d%s",&k[i],t),acam.insert(t,i);
	acam.getfail();
	acam.find(s);
	for(int i=1;i<=n;i++)
	{
		int siz=pos[i].size(),ans=1e5;
		if(siz<k[i])
		{	puts("-1"); continue; }
		for(int j=k[i]-1;j<siz;j++)
			ans=min(ans,pos[i][j]-(pos[i][j-k[i]+1]-tlen[i]));
		printf("%d\n",ans);
	}
}