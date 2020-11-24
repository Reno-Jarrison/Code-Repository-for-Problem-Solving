#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll pow3[40];
void solve(int n)
{
	pow3[0]=1;
	for(int i=1;i<=n;i++)
		pow3[i]=pow3[i-1]*3;
}
int main()
{
	solve(35);
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%lld\n",pow3[n]);
	}
}