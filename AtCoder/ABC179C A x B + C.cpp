#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) ans+=n/i-(n%i==0);
	printf("%d\n",ans);
}