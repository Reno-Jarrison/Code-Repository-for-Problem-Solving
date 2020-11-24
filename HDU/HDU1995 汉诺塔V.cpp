#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		printf("%lld\n",1LL<<(n-k));
	}
}