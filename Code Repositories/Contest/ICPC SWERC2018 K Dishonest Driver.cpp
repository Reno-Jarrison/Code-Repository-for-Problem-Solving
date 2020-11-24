#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int maxn=1e3+5,base=233;
char s[maxn];
int dp[maxn][maxn];
ull hval[maxn],powb[maxn];
void init(int n,char *s)
{
	powb[0]=1;
	for(int i=1;i<=n;i++)
	{
		hval[i]=(hval[i-1]*base+s[i]);
		powb[i]=powb[i-1]*base;
	}
}
ull gethash(int l,int r)
{	return hval[r]-hval[l-1]*powb[r-l+1];	}
int main()
{
	int n;
	scanf("%d%s",&n,s+1);
	init(n,s);
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=n;i++) dp[i][i]=1;
	for(int i=2;i<=n;i++)
		for(int l=1,r=l+i-1;r<=n;l++,r++)
		{
			for(int k=l;k<r;k++)
				dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]);
			for(int k=1;k<i;k++) if(i%k==0)
			{
				ull base=gethash(l,l+k-1); int ok=1;
				for(int j=l+k;j<=r;j+=k)
					if(gethash(j,j+k-1)!=base)
					{	ok=0; break; }
				if(ok) dp[l][r]=min(dp[l][r],dp[l][l+k-1]);
			}
		}
	printf("%d",dp[1][n]);
}