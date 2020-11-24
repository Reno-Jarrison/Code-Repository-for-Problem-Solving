#include<cstdio>
using namespace std;
int main()
{
	int n,p=1;
	scanf("%d",&n);
	while(n)
	{
		if(n==3) { printf("%d %d %d",p,p,p*3); break; }
		for(int i=1;i<=n/2;i++)
			printf("%d ",p);
		if(n&1) printf("%d ",p);
		p<<=1,n>>=1;
	}
}