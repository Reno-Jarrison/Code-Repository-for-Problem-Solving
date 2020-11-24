#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t,n,x;
	scanf("%d",&t);
	while(t--)
	{
		ll m,sum=0;
		scanf("%d%lld",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&x),sum+=x;
		puts(sum==m?"YES":"NO");
	}	
}