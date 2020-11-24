#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
vector<int>e[maxn];
string s[maxn];
int idx,nid[maxn],dfn[maxn],siz[maxn],root[maxn];
struct ACAM
{
	int tot,tag[maxn],nxt[maxn][26],fail[maxn];
	void insert(string s,int id)
	{
		int len=s.size(),pt=0;
		for(int i=0;i<len;i++)
		{
			int to=s[i]-'a';
			if(!nxt[pt][to])
				nxt[pt][to]=++tot;
			pt=nxt[pt][to];
		}
		nid[id]=pt;
	}
	void getfail()
	{
		queue<int>que;
		for(int i=0;i<26;i++)
			if(nxt[0][i]) que.push(nxt[0][i]);
		while(!que.empty())
		{
			int u=que.front();
			e[fail[u]].push_back(u);
			que.pop();
			for(int i=0;i<26;i++)
			{
				int v=nxt[u][i],f=fail[u];
				if(v) fail[v]=nxt[f][i],que.push(v);
				else nxt[u][i]=nxt[f][i];
			}
		}
	}
}acam;
struct PsdTree
{
	int tot,sum[maxn*40],lson[maxn*40],rson[maxn*40];
	void update(int& rt,int prt,int l,int r,int pos)
	{
		rt=++tot,sum[rt]=sum[prt];
		lson[rt]=lson[prt],rson[rt]=rson[prt];
		sum[rt]++;
		if(l==r) return;
		int mid=(l+r)>>1;
		if(pos<=mid) update(lson[rt],lson[prt],l,mid,pos);
		else update(rson[rt],rson[prt],mid+1,r,pos);
	}
	int query(int lrt,int rrt,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R) return sum[rrt]-sum[lrt];
		int mid=(l+r)>>1,ans=0;
		if(L<=mid) ans+=query(lson[lrt],lson[rrt],l,mid,L,R);
		if(R>mid) ans+=query(rson[lrt],rson[rrt],mid+1,r,L,R);
		return ans;
	}
}t;
void dfs1(int u)
{
	dfn[u]=++idx,siz[u]=1;
	for(int v:e[u])
		dfs1(v),siz[u]+=siz[v];
}
int main()
{	
	std::ios::sync_with_stdio(false);
	int n,q,l,r,k;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i],acam.insert(s[i],i);
	acam.getfail(),dfs1(0);
	for(int i=1;i<=n;i++)
	{
		int len=s[i].size(),pt=0,las=root[i-1];
		for(int j=0;j<len;j++)
		{
			int to=s[i][j]-'a';
			pt=acam.nxt[pt][to];
			t.update(root[i],las,1,idx,dfn[pt]),las=root[i];
		}
	} 
	while(q--)
	{
		cin>>l>>r>>k;
		int L=dfn[nid[k]],R=L+siz[nid[k]]-1;
		cout<<t.query(root[l-1],root[r],1,idx,L,R)<<endl;
	}
}