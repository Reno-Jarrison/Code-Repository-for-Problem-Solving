#include<stdio.h>
#include<stdlib.h>
#define N 10000
int main()
{
	int T,ID[N],i,id;
	while(scanf("%d",&T)!=EOF)
	{
		int j=-1;
		for(i=0;i<N;i++)
	 	{
	 		ID[i]=0;
		 }
		 for(i=0;i<T;i++)
		 {
		 	scanf("%d",&id);
		 	ID[id]++;
		 }
		 for(i=0;i<N;i++)
		 {
		 	if(ID[i]>(T/2))
		 	{
		 		j=i;
			 }
		 }
	  	printf("%d\n",j);
	}
}