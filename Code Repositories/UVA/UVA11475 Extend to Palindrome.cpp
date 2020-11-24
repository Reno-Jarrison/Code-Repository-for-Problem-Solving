#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=2e5+5;
int len,p[maxn];
char s[maxn],t[maxn<<1];
void init(char *s,char *t)
{
	len=0,t[len++]='*',t[len++]='#';
	while(*s) t[len++]=*s++,t[len++]='#';
}
void manacher(char *s,char *t)
{
	init(s,t);
	int id=1,mx=1;
	for(int i=1;i<len;i++)
	{
		if(i<mx) p[i]=min(p[id*2-i],mx-i);
		else p[i]=1;
		while(t[i-p[i]]==t[i+p[i]]) p[i]++;
		if(i+p[i]>mx) mx=p[i]+i,id=i;
	}
}
int main()
{
	while(~scanf("%s",s))
	{
		manacher(s,t);
		for(int i=1;i<len;i++)
			if(i+p[i]==len)
			{
				printf("%s",s);
				for(int j=(i-p[i])>>1;j;j--)
					putchar(s[j-1]);
				break;
			}
		puts("");
	}
}