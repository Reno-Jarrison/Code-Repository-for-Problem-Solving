#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5,maxm=2e5+5;
string s[maxn];
int tag[maxm],cnt[maxm];
struct EXSAM
{
	int tot,las,nxt[maxm][128],fat[maxm],len[maxm];
	void insert(int to)
	{
		if(nxt[las][to]&&len[las]+1==len[nxt[las][to]])
		{	las=nxt[las][to]; return; }
		int p=las,np=las=++tot;
		len[np]=len[p]+1;
		while(p&&!nxt[p][to])
			nxt[p][to]=np,p=fat[p];
		if(!p) { fat[np]=1; return; }
		int q=nxt[p][to];
		if(len[q]==len[p]+1)
		{	fat[np]=q; return; }
		int nq=++tot;
		if(p==las) las=nq;
		memcpy(nxt[nq],nxt[q],sizeof(nxt[q]));
		len[nq]=len[p]+1;
		fat[nq]=fat[q];
		fat[q]=fat[np]=nq;
		while(p&&nxt[p][to]==q)
			nxt[p][to]=nq,p=fat[p];
	}
}sam;
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	sam.tot=sam.las=1;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i],sam.las=1;
		for(int x:s[i])
			sam.insert(x);
	}
	for(int i=1;i<=n;i++)
	{
		int pt=1;
		for(int x:s[i])
		{
			pt=sam.nxt[pt][x];
			for(int j=pt;j&&tag[j]!=i;j=sam.fat[j])
				tag[j]=i,cnt[j]++;
		}
	}
	while(m--)
	{
		cin>>s[0];
		int pt=1;
		for(int x:s[0])
		{
			pt=sam.nxt[pt][x];
			if(!pt) break;	
		}
		printf("%d\n",cnt[pt]);
	}
}