#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+5;
char s[maxn];
int idx[maxn],val[maxn];
struct ACAM
{
	int	tot,nxt[maxn][26],fail[maxn],las[maxn];
	multiset<int>mst[maxn];
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
		idx[id]=pt,mst[pt].insert(0);
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
					las[v]=(!mst[fnxt].empty()?fnxt:las[fnxt]);
				}
				else nxt[u][i]=fnxt;
			}
		}
	}
	int query(char* s)
	{
		int len=strlen(s),pt=0,ans=-1;
		for(int i=0;i<len;i++)
		{
			int to=s[i]-'a';
			pt=nxt[pt][to];
			if(mst[pt].size())
				ans=max(ans,*--mst[pt].end());
			int tmp=las[pt];
			while(tmp)
				ans=max(ans,*--mst[tmp].end()),tmp=las[tmp];
		}
		return ans;
	}
}acam;
int main()
{
	int n,m,o,id,x;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",s),acam.insert(s,i);
	acam.getfail();
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&o);
		if(o==1)
		{
			scanf("%d%d",&id,&x);
			int pt=idx[id];
			acam.mst[pt].erase(acam.mst[pt].find(val[id]));
			val[id]=x,acam.mst[pt].insert(x);
		}
		else scanf("%s",s),printf("%d\n",acam.query(s));
	}
}