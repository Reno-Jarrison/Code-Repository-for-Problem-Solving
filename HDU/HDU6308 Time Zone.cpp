#include<stdio.h>
#include<string.h>
 
int main()
{
	int n,a,b,len,x,y,flag;
	char time[15];
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d%s",&a,&b,time);
		len=strlen(time);
		flag=x=y=0;
		for(int i=4;i<len;i++)
			if(time[i]=='.')
				flag=1;
			else
			{
				if(!flag)	
					x*=10,x+=time[i]-'0';
				else
					y=time[i]-'0';
			}
		if(time[3]=='+')
			a+=x-8,b+=y*6;
		else
			a-=x+8,b-=y*6;	
		if(b>=60)
			b-=60,a++;
		else if(b<0)
			b+=60,a--;	
		if(a>=24)
			a-=24;
		else if(a<0)
			a+=24;
		printf("%02d:%02d\n",a,b);
	}
	return 0;
}