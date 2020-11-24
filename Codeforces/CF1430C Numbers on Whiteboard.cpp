#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		puts("2");
		if(n==2)
		{	puts("1 2"); continue; }
		printf("%d %d\n",n-2,n);
		printf("%d %d\n",n-1,n-1);
		for(int i=n-3;i;i--)
			printf("%d %d\n",i,i+2);
	}
}