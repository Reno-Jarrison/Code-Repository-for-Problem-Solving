#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
char s[maxn];
int ans[maxn];
int main()
{
	int t,x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%d",s+1,&x);
		int n=strlen(s+1),ok=1;
		fill(ans+1,ans+n+1,1);
		for(int i=1;i<=n;i++) if(s[i]=='0')
		{
			if(i-x>=1) ans[i-x]=0;
			if(i+x<=n) ans[i+x]=0;
		}
		for(int i=1;i<=n&&ok;i++) if(s[i]=='1')
		{
			int tag=0;
			if(i-x>=1&&ans[i-x]==1) tag=1;
			if(i+x<=n&&ans[i+x]==1) tag=1;
			if(!tag) ok=0;
		}
		if(!ok) printf("-1");
		else for(int i=1;i<=n;i++)
			printf("%d",ans[i]);
		puts("");
	}
}