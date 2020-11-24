#include<stdio.h>
int main()
{
	//freopen("C:\\Users\\罗庚欣\\Desktop\\文件\\Freopen.txt","r",stdin);
	int m,max=0,count=0;
	scanf("%d",&m);
	int a[105]={0};
	for(int i=0;i<m;i++)
	{
		scanf("%d",&a[i]);
		if(!i)
			if(a[i]==1) 
				count+=2;
			else
				count++;	
		else if(a[i]==1000&&a[i-1]+1==a[i])
		{
			count++;
			if(count>1&&count-1>max)
				max=count-1;
		}	
		else if(i==m-1||a[i-1]+1!=a[i])
		{
			if(a[i-1]+1==a[i])
				count++;
			if(count>2&&count-2>max)
				max=count-2;
			count=1;
		}
		else if(a[i-1]+1==a[i])
			count++;
	}
	printf("%d\n",max);
}
