#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
char s[maxn];
int main()
{
	int t,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%s",&a,&b,s+1);
		int n=strlen(s+1),tag=0,cnt=0,ans=0;
		for(int i=1;i<=n;i++)
		{
			if(!tag&&s[i]=='0') continue;
			tag=1;
			if(s[i]=='0') cnt++;
			else ans+=min(a,cnt*b),cnt=0;
		}
		if(tag) ans+=a;
		printf("%d\n",ans);
	}
}