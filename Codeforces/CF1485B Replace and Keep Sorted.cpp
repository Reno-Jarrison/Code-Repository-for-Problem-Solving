#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int a[maxn],pre[maxn];
int main()
{
	int n,q,k,l,r;
	scanf("%d%d%d",&n,&q,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	a[0]=0,a[n+1]=k+1;
	for(int i=1;i<=n;i++)
		pre[i]=pre[i-1]+a[i+1]-a[i-1]-2;
	while(q--)
	{
		scanf("%d%d",&l,&r);
		int ans=0;
		if(r>l)
			ans=pre[r-1]-pre[l]+k-a[r-1]+a[l+1]-3;
		else ans=k-1;
		printf("%d\n",ans);
	}
}