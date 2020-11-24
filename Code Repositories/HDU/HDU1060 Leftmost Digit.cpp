#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		double power=n*log10(n);
		power-=(long long)power;
		printf("%d\n",(int)pow(10,power));
	}
}