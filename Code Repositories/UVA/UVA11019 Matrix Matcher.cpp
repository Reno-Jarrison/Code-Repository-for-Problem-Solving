#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5,maxm=1e3+5;
char txt[maxm][maxm],pat[105][105];
int num[maxm][maxm];
struct ACAM
{
	int tot,nxt[maxn][26],fail[maxn];
	vector<int>idx[maxn];
	void clear()
	{	tot=0,newnode(); }
	int newnode()
	{	
		memset(nxt[tot],0,sizeof(nxt[tot]));
		idx[tot].clear();
		return fail[tot]=0,tot++;
	}
	void insert(char* s,int id)
	{
		int len=strlen(s),pt=0;
		for(int i=0;i<len;i++)
		{
			int to=s[i]-'a';
			if(!nxt[pt][to])
				nxt[pt][to]=newnode();
			pt=nxt[pt][to];
		}
		idx[pt].push_back(id);
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
				if(v) fail[v]=fnxt,que.push(v);
				else nxt[u][i]=fnxt;
			}
		}
	}
	void run(char* s,int id)
	{
		int len=strlen(s),pt=0;
		for(int i=0;i<len;i++)
		{
			int to=s[i]-'a';
			pt=nxt[pt][to];
			for(int r:idx[pt]) if(id>=r)
				num[id-r][i]++;
		}
	}
}acam;
int main()
{
	int t,n,m,r,c;
	scanf("%d",&t);
	while(t--)
	{

		scanf("%d%d",&r,&c);
		for(int i=0;i<r;i++)
			scanf("%s",txt[i]);
		acam.clear();
		memset(num,0,sizeof(num));
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
			scanf("%s",pat[i]),acam.insert(pat[i],i);
		acam.getfail();
		for(int i=0;i<r;i++)
			acam.run(txt[i],i);
		int ans=0;
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				if(num[i][j]==n) ans++;
		printf("%d\n",ans);
	}
}