#include<bits/stdc++.h>
#define maxn 1000005 
using namespace std;
int a[maxn],minq[maxn],maxq[maxn],dp[maxn][2];
int main()
{
	int n,k,maxh,maxt,minh,mint;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) 
		scanf("%d",&a[i]);
	maxh=minh=1,maxt=mint=0;
	for(int i=1;i<=n;i++)
	{
		if(maxh<=maxt&&maxq[maxh]<=i-k) maxh++;
		while(maxh<=maxt&&a[maxq[maxt]]<=a[i]) maxt--;
		if(minh<=mint&&minq[minh]<=i-k) minh++;
		while(minh<=mint&&a[minq[mint]]>=a[i]) mint--;
		maxq[++maxt]=minq[++mint]=i;
		dp[i][0]=a[maxq[maxh]],dp[i][1]=a[minq[minh]];
 	} 
	for(int i=k;i<=n;i++) printf("%d ",dp[i][1]); 
	printf("\n");
	for(int i=k;i<=n;i++) printf("%d ",dp[i][0]); 
}