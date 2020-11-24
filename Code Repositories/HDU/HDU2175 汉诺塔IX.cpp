#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)&&n)
	{
		int cnt=0;
		while(!(m&1)) cnt++,m>>=1;
		printf("%d\n",cnt+1);
	}
}