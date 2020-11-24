#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e3+5;
int m,a[15],s[15],sg[maxn];
bool mex[maxn];
void getsg()
{
	for(int i=1;i<=maxn-5;i++)
	{
		memset(mex,0,sizeof(mex));
		for(int j=1;j<=m&&s[j]<=i;j++)
			mex[sg[i-s[j]]]=true;
		for(int j=0;j<=m;j++)
			if(!mex[j]) { sg[i]=j; break; }
	}
}
int main()
{
	int n,sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&s[i]);
	getsg();
	for(int i=1;i<=n;i++)
		sum^=sg[a[i]];
	if(sum)
	{
		printf("YES\n");
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				int tmp=sum^sg[a[i]];
				if(a[i]>=s[j]&&(tmp^sg[a[i]-s[j]])==0)
				{	printf("%d %d",i,s[j]); return 0; }
			}
	}
	else printf("NO");
}