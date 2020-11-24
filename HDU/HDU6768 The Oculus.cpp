#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e6+5;
ll fib[maxn];
int main()
{
	fib[0]=fib[1]=1LL;
	for(int i=2;i<maxn;i++)
		fib[i]=fib[i-1]+fib[i-2];
	int t,n1,n2,n3,x;
	ll a,b,c;
	scanf("%d",&t);
	while(t--)
	{
		a=b=c=0;
		scanf("%d",&n1);
		for(int i=1;i<=n1;i++)
			scanf("%d",&x),a+=x?fib[i]:0;
		scanf("%d",&n2);
		for(int i=1;i<=n2;i++)
			scanf("%d",&x),b+=x?fib[i]:0;
		scanf("%d",&n3);
		for(int i=1;i<=n3;i++)
			scanf("%d",&x),c+=x?fib[i]:0;
		for(int i=1;i<=n1+n2+1;i++)
			if(a*b==c+fib[i])
			{	printf("%d\n",i); break; }	
	}	
}