#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,ans=0;
	long long d,x,y;
	scanf("%d%lld",&n,&d);
	d=d*d;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&x,&y);
		if(x*x+y*y<=d) ans++;
	}
	printf("%d",ans);
}