#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int vis[maxn];
char s[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		int len=strlen(s),tmp=0;
		if(s[0]=='-'||len>7) continue;
		for(int i=0;i<len;i++)
			tmp=tmp*10+s[i]-'0';
		if(tmp<maxn) vis[tmp]=1;
	}
	for(int i=0;i<=n;i++) if(!vis[i]) 
	{	printf("%d",i); return 0; }
}