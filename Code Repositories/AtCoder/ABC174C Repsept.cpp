#include<bits/stdc++.h>
using namespace std;
int main()
{
	int k,x=0;
	scanf("%d",&k);
	for(int i=1;i<=k;i++)
	{
		x=(x*10+7)%k;
		if(!x)
		{	printf("%d",i); return 0; }
	}
	printf("-1");
}