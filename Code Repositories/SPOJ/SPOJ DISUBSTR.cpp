#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
struct SAM
{
	int tot,las,nxt[maxn<<1][26],fat[maxn<<1],len[maxn<<1];
	void init()
	{
		las=tot=1; 
		memset(nxt,0,sizeof(nxt));
		memset(fat,0,sizeof(fat));
	}
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
		len[nq]=len[p]+1;
		fat[nq]=fat[q];
		fat[q]=fat[np]=nq;
		while(p&&nxt[p][to]==q) 
			nxt[p][to]=nq,p=fat[p];
	}
}sam;
char s[maxn];
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		sam.init();
		long long ans=0;
		scanf("%s",s);
		n=strlen(s);
		for(int i=0;i<n;i++)
			sam.insert(s[i]-'A');
		for(int i=1;i<=sam.tot;i++)
			ans+=sam.len[i]-sam.len[sam.fat[i]];
		printf("%lld\n",ans);
	}
}