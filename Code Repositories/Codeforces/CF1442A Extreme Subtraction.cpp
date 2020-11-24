#include<bits/stdc++.h>
using namespace std;
const int maxn=3e4+5;
int a[maxn],pre[maxn],suc[maxn];
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		pre[1]=a[1],suc[n]=a[n];
		for(int i=2;i<=n;i++)
			pre[i]=pre[i-1]-max(0,a[i-1]-a[i]);
		for(int i=n-1;i;i--)
			suc[i]=suc[i+1]-max(0,a[i+1]-a[i]);
		int ok=0;
		for(int i=1;!ok&&i<=n;i++)
			if(pre[i]>=0&&suc[i]>=0&&pre[i]+suc[i]>=a[i]) ok=1;
		puts(ok?"YES":"NO");
	}
}