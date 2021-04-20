#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,ans=1e6;
	scanf("%d",&n);
	for(int i=1;i*i<=n;i++)
		if(n%i==0) ans=min(ans,(i+n/i)*2);
	printf("%d\n",ans);
}