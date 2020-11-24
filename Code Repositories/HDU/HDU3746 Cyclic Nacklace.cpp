#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
char s[maxn];
int nxt[maxn];
int getnxt(char *s)
{
	nxt[0]=-1;
	int len=strlen(s),i=0,j=-1;
	while(i<len)
		j==-1||s[i]==s[j]?nxt[++i]=++j:j=nxt[j];
	int rpt=len-nxt[len];
	if(rpt<len&&len%rpt==0) return 0;
	return rpt-len%rpt;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		scanf("%s",s),printf("%d\n",getnxt(s));
}