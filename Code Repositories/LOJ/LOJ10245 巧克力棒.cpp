#include<cstdio>
using namespace std;
int a[15];
int getsum(int x,int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
		if(x&(1<<i)) sum^=a[i];
	return sum;
}
int main()
{
	int n;
	for(int i=1;i<=10;i++)
	{
		bool flag=false;
		scanf("%d",&n);
		for(int j=0;j<n;j++)
			scanf("%d",&a[j]);
		for(int i=1;i<(1<<n);i++)
			if(!getsum(i,n))	
			{	flag=true; break; }
		printf(flag?"NO":"YES"),puts("");
	}
}