#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
char s[maxn],dst[maxn<<1];
int len,p[maxn<<1];
char* init(char *s,char *t)
{
	len=0,t[len++]='$',t[len++]='#';
	while(*s) t[len++]=*s++,t[len++]='#';
	t[len]='*';
	return t;
}
int manacher(char *s)
{
	s=init(s,dst);
	int id=1,mx=1,ans=0;
	for(int i=1;i<len;i++)
	{
		p[i]=i<mx?min(p[2*id-i],mx-i):1;
		while(s[i-p[i]]==s[i+p[i]]) p[i]++;
		if(i+p[i]>mx) id=i,mx=i+p[i];
		ans=max(ans,p[i]);
	}
	return ans-1;
}
int main()
{
	while(~scanf("%s",s))
		printf("%d\n",manacher(s));
}