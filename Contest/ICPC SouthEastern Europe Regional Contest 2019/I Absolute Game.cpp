#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int a[maxn],b[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	sort(a+1,a+n+1),sort(b+1,b+n+1);
	int ans=0,pt=1;
	for(int i=1;i<=n;i++)
	{
		while(pt<n&&b[pt+1]<a[i]) pt++;
		int cur=abs(a[i]-b[pt]);
		if(pt<n) cur=min(cur,abs(a[i]-b[pt+1]));
		ans=max(ans,cur);
	}
	printf("%d",ans);
}