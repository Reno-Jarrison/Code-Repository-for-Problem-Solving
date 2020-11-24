#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e4+5;
int s[105],sg[maxn],mex[maxn];
void getsg(int k)
{
	sort(s+1,s+k+1);
	for(int i=1;i<=maxn-5;i++)
	{
		memset(mex,0,sizeof(mex));
		for(int j=1;j<=k&&s[j]<=i;j++)
			mex[sg[i-s[j]]]=1;
		for(int j=0;j<=k;j++)
			if(!mex[j]) { sg[i]=j; break; }
	}
}
int main()
{
	int n,m,k,x,sum;
	while(~scanf("%d",&k)&&k)
	{
		for(int i=1;i<=k;i++)
			scanf("%d",&s[i]);
		getsg(k);
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&n),sum=0;
			for(int i=1;i<=n;i++)
				scanf("%d",&x),sum^=sg[x];
			putchar(sum?'W':'L');
		}
		puts("");
	}
}