#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e6+5;
char pat[maxn];
int nxt[maxn]={-1};
void getnxt(char *s)
{
	int i=0,j=-1,len=strlen(s);
	while(i<len)
		s[i]==s[j]||j==-1?nxt[++i]=++j:j=nxt[j];
}
int main()
{
	while(scanf("%s",pat))
	{
		if(pat[0]=='.'&&strlen(pat)==1) return 0;
		getnxt(pat);
		int len=strlen(pat),tmp=len-nxt[len],ans=0;
		if(nxt[len]%tmp==0) ans=nxt[len]/tmp;
		printf("%d\n",ans+1);
	}
}