#include<cstdio>
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n<0)
			printf("-"),n=-n;
		if(n==1)
			printf("1\n");
		else
		{
			int mod[100005]={1},i=1; 
			printf("0.");
			while(!mod[i])
			{
				mod[i]=1;
				i*=10;
				printf("%d",i/n);
				i%=n;
			}
			printf("\n");
		}
	}
}