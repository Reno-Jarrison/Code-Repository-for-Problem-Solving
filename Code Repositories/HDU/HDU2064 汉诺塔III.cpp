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
	int n;
	while(~scanf("%d",&n))
		printf("%llu\n",pow3[n]-1);
}