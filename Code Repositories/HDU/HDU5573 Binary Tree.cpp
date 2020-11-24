#include<cstdio>
using namespace std;
int tag[65];
int main()
{
	int t,n,k,ks=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		int x=0,flag=0;
		for(int i=k-1;~i;i--)
		{
			if(x<n) x|=(1<<i),tag[i]=1;
			else x-=(1<<i),tag[i]=0; 
		}
		if(x!=n) flag=1;
		printf("Case #%d:\n",++ks);
		for(int i=0;i<k;i++)
			printf("%d %c\n",1<<i|((i==k-1)&flag),tag[i]?'+':'-');
	}
}