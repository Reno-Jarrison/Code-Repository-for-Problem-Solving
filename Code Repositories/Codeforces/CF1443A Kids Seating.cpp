#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1,x=4*n;i<=n;i++,x-=2)
			printf("%d ",x);
		puts("");
	}
}