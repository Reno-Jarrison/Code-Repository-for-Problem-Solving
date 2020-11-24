#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<vector>
#define lowbit(x) ((x)&(-x))
using namespace std;
const int maxn=1e5+5;
struct node
{	int nxt[26],fail; }trie[maxn];
struct query {	int x,y,id; }q[maxn];
int cnt,fat[maxn],idx,id[maxn];
int in[maxn],out[maxn],tree[maxn],ans[maxn];
char s[maxn];
vector<int>e[maxn];
bool operator <(const query& a,const query& b)
{	return a.y<b.y; }
void build(char *s)
{
	int len=strlen(s),u=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]=='B') u=fat[u];
		else if(s[i]=='P') id[++idx]=u;
		else 
		{
			int v=s[i]-'a';
			if(!trie[u].nxt[v])
				trie[u].nxt[v]=++cnt;
			fat[trie[u].nxt[v]]=u,u=trie[u].nxt[v];
		}
	}
}
void getfail()
{
	queue<int>q;
	for(int i=0;i<26;i++)
		if(trie[0].nxt[i])
			q.push(trie[0].nxt[i]),e[0].push_back(trie[0].nxt[i]);
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		for(int i=0;i<26;i++)
		{
			int v=trie[u].nxt[i],f=trie[u].fail,fnxt=trie[f].nxt[i];
			if(v) trie[v].fail=fnxt,q.push(v),e[fnxt].push_back(v);
			else trie[u].nxt[i]=fnxt;
		}
	}
}
void dfs(int u)
{
	in[u]=++idx;
	for(int i=0;i<(int)e[u].size();i++) dfs(e[u][i]);
	out[u]=idx;
}
void update(int x,int val,int n)
{	while(x<=n) tree[x]+=val,x+=lowbit(x); }
int query(int x)
{
	int ans=0;
	while(x) ans+=tree[x],x-=lowbit(x);
	return ans;
}
int query_tree(int x)
{	return query(out[x])-query(in[x]-1); }
int main()
{
	int n;
	scanf("%s%d",s,&n);
	build(s),getfail(),idx=0,dfs(0),cnt++;
	for(int i=1;i<=n;i++)
		scanf("%d%d",&q[i].x,&q[i].y),q[i].id=i;
	sort(q+1,q+n+1);
	int len=strlen(s),pt=0,qx=1,tag=0;
	for(int i=0;i<len&&qx<=n;i++)
	{
		if(s[i]=='B') update(in[pt],-1,cnt),pt=fat[pt];
		else if(s[i]=='P')
		{	tag++; while(q[qx].y==tag) ans[q[qx].id]=query_tree(id[q[qx].x]),qx++; }
		else pt=trie[pt].nxt[s[i]-'a'],update(in[pt],1,cnt);
	}
	for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
}