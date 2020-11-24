#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=35;
char s1[maxn],s2[maxn];
ll dp1[maxn][maxn],dp2[maxn][maxn];
int main()
{
	int t;
	scanf("%d",&t),getchar();
	for(int i=1;i<=t;i++)
	{
		gets(s1+1),gets(s2+1);
		int n1=strlen(s1+1),n2=strlen(s2+1);
		memset(dp1,0,sizeof(dp1));
		memset(dp2,0,sizeof(dp2));
		for(int j=0;j<=n1;j++) dp2[j][0]=1;
		for(int j=0;j<=n2;j++) dp2[0][j]=1;
		for(int j=1;j<=n1;j++)
			for(int k=1;k<=n2;k++)
			{
				if(s1[j]==s2[k])
				{
					dp1[j][k]=dp1[j-1][k-1]+1;
					dp2[j][k]=dp2[j-1][k-1];
				}
				else
				{
					dp1[j][k]=max(dp1[j-1][k],dp1[j][k-1]);
					if(dp1[j][k]==dp1[j-1][k])
						dp2[j][k]+=dp2[j-1][k];
					if(dp1[j][k]==dp1[j][k-1])
						dp2[j][k]+=dp2[j][k-1];
				}
			}
		printf("Case #%d: %lld %lld\n",i,n1+n2-dp1[n1][n2],dp2[n1][n2]);
	}
}