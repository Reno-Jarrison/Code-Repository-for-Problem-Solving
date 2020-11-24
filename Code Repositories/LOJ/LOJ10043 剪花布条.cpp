#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e5+5;
char txt[maxn],pat[maxn];
int nxt[maxn]={-1};
void getnxt(char *s)
{
	int i=0,j=-1,len=strlen(s);
	while(i<len)
		s[i]==s[j]||j==-1?nxt[++i]=++j:j=nxt[j];
}
int kmp(char *t,char *p)
{
	int i=0,j=0,tlen=strlen(t),plen=strlen(p),ans=0;
	while(i<tlen)
	{
		t[i]==p[j]||j==-1?i++,j++:j=nxt[j];
		if(j==plen) ans++,j=0;
	}
	return ans;
}
int main()
{
	while(scanf("%s",txt))
	{
		if(txt[0]=='#'&&strlen(txt)==1) return 0;
		scanf("%s",pat);
		getnxt(pat),printf("%d\n",kmp(txt,pat));
	}
}