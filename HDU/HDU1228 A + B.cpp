#include<stdio.h>
#include<string.h>
int main()
{
	const char *num[]={"zero","one","two","three","four","five","six","seven","eight","nine","+","="};
	char b[5]={0};
	int c[2]={0},c1=0,p,plus[2];
	while(scanf("%s",b)!=EOF)
	{
		for(int i=0;i<12;i++)
		{
			int count=0;
			int len=strlen(b);
			for(int j=0;j<len;j++)
			{
				if(b[j]!=num[i][j])
					break;
				count++;
			}
			if(count==len)
			{
				p=i;
				if(i<10)
					c[c1++]=i;
				break;
			}
		}
		if(p==10)
		{
			if(c1==1)
				plus[0]=c[0];
			else
				plus[0]=c[1]+c[0]*10;
			c1=0;
			
		}
		if(p==11)
		{
			if(c1==1)
				plus[1]=c[0];
			else
				plus[1]=c[1]+c[0]*10;
			c1=0;
			int sum=plus[0]+plus[1];
			if(sum)	
				printf("%d\n",sum);
		}
	}
}