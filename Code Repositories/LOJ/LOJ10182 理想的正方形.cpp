#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int m[maxn][maxn],maxm[maxn][maxn],minm[maxn][maxn],q1[maxn],q2[maxn];
int main()
{
	int a,b,n,ans=0x7fffffff;
	scanf("%d%d%d",&a,&b,&n);
	for(int i=1;i<=a;i++)
		for(int j=1;j<=b;j++)
			scanf("%d",&m[i][j]);
	for(int i=1;i<=a;i++)	
		for(int j=1,h1=1,h2=1,t1=0,t2=0;j<=b;j++)
		{
			if(h1<=t1&&q1[h1]<=j-n) h1++;
			if(h2<=t2&&q2[h2]<=j-n) h2++;
			while(h1<=t1&&m[i][q1[t1]]<=m[i][j]) t1--;
			while(h2<=t2&&m[i][q2[t2]]>=m[i][j]) t2--;
			q1[++t1]=q2[++t2]=j;
			if(j>=n)
			{
				maxm[i][j-n+1]=m[i][q1[h1]];
				minm[i][j-n+1]=m[i][q2[h2]];
			}
		}
	for(int i=1;i<=b-n+1;i++)
		for(int j=1,h1=1,h2=1,t1=0,t2=0;j<=a;j++)
		{
			if(h1<=t1&&q1[h1]<=j-n) h1++;
			if(h2<=t2&&q2[h2]<=j-n) h2++;
			while(h1<=t1&&maxm[q1[t1]][i]<=maxm[j][i]) t1--;
			while(h2<=t2&&minm[q2[t2]][i]>=minm[j][i]) t2--;
			q1[++t1]=q2[++t2]=j;
			if(j>=n) ans=min(ans,maxm[q1[h1]][i]-minm[q2[h2]][i]);
		}
	printf("%d",ans);
}