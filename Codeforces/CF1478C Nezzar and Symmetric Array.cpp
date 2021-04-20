#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
ll d[maxn<<1];
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++)
			scanf("%lld",&d[i]);
		sort(d+1,d+2*n+1);
		int ok=1; ll sum=0;
		for(int i=2*n;i&&ok;i-=2)
		{
			if(d[i]!=d[i-1]) ok=0;
			if(i>2&&d[i]==d[i-2]) ok=0;
			ll cur=d[i]-sum;
			if(cur<=0||cur%i) ok=0;
			sum+=2LL*cur/i;
		}
		puts(ok?"YES":"NO");
	}
}