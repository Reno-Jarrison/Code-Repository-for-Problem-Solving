#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long b,x;
		scanf("%lld%lld",&b,&x);
		puts(b%x==1?"T":"F");
	}
}