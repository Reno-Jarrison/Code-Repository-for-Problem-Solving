#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5,maxm=1e4+5;
char txt[maxn],pat[maxm];
int nxt[maxm];
void getnxt(char *s)
{
	nxt[0]=-1;
	int len=strlen(s),i=0,j=-1;
	while(i<len)
		j==-1||s[i]==s[j]?nxt[++i]=++j:j=nxt[j];
}
int kmp(char *p,char *t)
{
	int plen=strlen(p),tlen=strlen(t);
	int i=0,j=0,ans=0;
	while(i<tlen)
	{
		if(j==-1||t[i]==p[j]) i++,j++;
		else j=nxt[j];
		if(j==plen) ans++,j=nxt[j];
	}
	return ans;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%s",pat,txt);
		getnxt(pat);
		printf("%d\n",kmp(pat,txt));
	}
}