#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e4+5;
ll a[maxn],c2[maxn];
int main()
{
	int n,m;
	for(int i=1;i<=maxn-5;i++)
		c2[i]=1LL*i*(i-1);
	while(~scanf("%d",&n))
		while(n--)
		{
			ll sum=0; bool ok=true;
			scanf("%d",&m);
			for(int i=1;i<=m;i++)
				scanf("%lld",&a[i]);
			sort(a+1,a+m+1);
			for(int i=1;i<m;i++)
				sum+=a[i],ok&=(sum>=c2[i]);
			sum+=a[m];
			if(sum!=c2[m]) ok=false;
			puts(ok?"T":"F");
		}
}
