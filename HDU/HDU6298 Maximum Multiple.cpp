#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n%3==0) printf("%lld\n",1LL*n*n*n/27);
		else if(n%4==0) printf("%lld\n",1LL*n*n*n/32);
		else puts("-1");
	}
}