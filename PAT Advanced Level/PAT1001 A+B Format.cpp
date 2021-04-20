#include<bits/stdc++.h>
using namespace std;
int num[10];
int main()
{
	int a,b,sum,neg=0,len=0;
	scanf("%d%d",&a,&b);
	sum=a+b,neg=sum<0,sum=abs(sum);
	if(neg) putchar('-');
	if(!sum) putchar('0');
	while(sum)
		num[++len]=sum%10,sum/=10;
	for(int i=len;i;i--)
	{
		if(i<len&&i%3==0) putchar(',');
		printf("%d",num[i]);
	}
}