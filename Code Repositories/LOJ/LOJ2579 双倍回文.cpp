#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
char s[maxn];
struct PAM
{
	int tot,las,nxt[maxn][26],fail[maxn],half[maxn],len[maxn];
	void clear()
	{	tot=las=0,newnode(0),newnode(-1),fail[0]=1; }
	int newnode(int x)
	{
		memset(nxt[tot],0,sizeof(nxt[tot]));
		return fail[tot]=half[tot]=0,len[tot]=x,tot++;
	}
	int getfail(char *s,int pos,int pt)
	{
		while(s[pos-len[pt]-1]!=s[pos]) pt=fail[pt];
		return pt;
	}
	void insert(char *s,int pos)
	{
		int pt=getfail(s,pos,las),to=s[pos]-'a';
		if(!nxt[pt][to])
		{
			int cur=newnode(len[pt]+2),f=getfail(s,pos,fail[pt]);
			fail[cur]=nxt[f][to];
			nxt[pt][to]=cur;
			if(len[cur]<=2) half[cur]=fail[cur];
			else
			{
				int x=half[pt];
				while(s[pos-len[x]-1]!=s[pos]||(len[x]+2)*2>len[cur])
					x=fail[x];
				half[cur]=nxt[x][to];
			}
		}
		las=nxt[pt][to];
	}
	int solve()
	{
		int ans=0;
		for(int i=2;i<tot;i++)
			if(len[i]==len[half[i]]*2&&len[i]%4==0)
				ans=max(ans,len[i]);
		return ans;
	}
}pam;
int main()
{
	int n;
	scanf("%d%s",&n,s);
	pam.clear();
	for(int i=0;i<n;i++)
		pam.insert(s,i);
	printf("%d\n",pam.solve());
}