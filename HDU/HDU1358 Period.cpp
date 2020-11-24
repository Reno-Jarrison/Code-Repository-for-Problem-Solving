#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
char str[maxn];
int nxt[maxn]={-1};
void getnxt(char *s)
{
	int i=0,j=-1,len=strlen(s);
	while(i<len)
	{
		if(s[i]==s[j]||j==-1)
		{
			nxt[++i]=++j;
			if(i-nxt[i]>0&&i%(i-nxt[i])==0&&i/(i-nxt[i])>1)
				printf("%d %d\n",i,i/(i-nxt[i]));
		}
		else j=nxt[j];
	}
}
int main()
{
	int n,ks=0;
	while(scanf("%d",&n)&&n)
	{
		scanf("%s",str);
		printf("Test case #%d\n",++ks);
		getnxt(str),puts("");
	}
}	