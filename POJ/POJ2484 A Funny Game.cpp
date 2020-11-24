#include<cstdio>
using namespace std;
int main()
{
	int n;
	while(~scanf("%d",&n)&&n)
		puts(n<=2?"Alice":"Bob");
}