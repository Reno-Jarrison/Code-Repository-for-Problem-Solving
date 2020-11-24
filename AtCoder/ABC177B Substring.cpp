#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
char s[maxn],t[maxn];
int main()
{
	scanf("%s%s",s,t);
	int lens=strlen(s),lent=strlen(t),ans=0;
	for(int i=0;i+lent<=lens;i++)
	{
		int cnt=0;
		for(int j=0;j<lent;j++)
			cnt+=(s[i+j]==t[j]);
		ans=max(ans,cnt);
	}
	printf("%d\n",lent-ans);
}	