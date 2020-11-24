#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll d[25];
void init(int n)
{
	d[1]=0,d[2]=1;
	for(int i=3;i<=n;i++)
		d[i]=(d[i-1]+d[i-2])*(i-1);
}
int main()
{
	init(20);
	int n;
	while(~scanf("%d",&n))
		printf("%lld\n",d[n]);
}