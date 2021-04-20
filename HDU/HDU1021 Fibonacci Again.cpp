#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int fib[maxn];
int main()
{
	fib[0]=7%3,fib[1]=11%3;
	for(int i=2;i<maxn;i++)
		fib[i]=(fib[i-1]+fib[i-2])%3;
	int n;
	while(~scanf("%d",&n))
		puts(fib[n]?"no":"yes");
}