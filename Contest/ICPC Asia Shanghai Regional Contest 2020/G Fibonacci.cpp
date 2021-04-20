#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll C2(int x)
{	return 1LL*x*(x-1)/2; }
int main()
{
	int n;
	scanf("%d",&n);
	printf("%lld\n",C2(n)-C2(n-n/3));
}