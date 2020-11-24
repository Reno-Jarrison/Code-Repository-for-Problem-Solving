#include<stdio.h>
void judge(int x,int y);
int count,j;
int main()
{
	int x=1,y=1;
	while(1)
	{
		count=0,j=0;
		scanf("%d%d",&x,&y);
		judge(x,y);
		if(count)
			break;
		if(j)
			printf("Sorry\n");
		else
			printf("OK\n");
	}
}

void judge(int x,int y)
{
	if(x||y)
		for(int n=x;n<=y;n++)
		{
			int c=n*n+n+41;
			if(c<2)
				j++;
			else
			{
				for(int k=2;k<c;k++)
					if(!(c%k))
						j++;					
			 } 
		}
	else 
		count++;
}