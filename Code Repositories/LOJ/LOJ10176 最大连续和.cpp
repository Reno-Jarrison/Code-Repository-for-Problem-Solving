#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
int a[maxn],sum[maxn],q[maxn];
int main()
{
	int n,m,h=1,t=0,ans=-INT_MAX;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) 
		scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];
	q[++t]=0; 
	for(int i=1;i<=n;i++)
	{
		if(h<=t&&q[h]<i-m) h++;
		while(h<=t&&sum[q[t]]>=sum[i]) t--;
		ans=max(ans,sum[i]-sum[q[h]]);
		q[++t]=i;
	}
	printf("%d",ans);
}