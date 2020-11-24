#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib> 
using namespace std;
int maxm,minm,k;
char num[30];
void search(char *s,int time,int flag,int len)
{
	int temp=atoi(s);
	if(time==k||flag==len-1)
	{
		maxm=max(maxm,temp);
		minm=min(minm,temp);
		return;	
	}
	for(int i=flag+1;i<len;i++)
	{
		if(!flag&&num[i]=='0')	
			continue;
		swap(s[i],s[flag]);
		search(num,time+1,flag+1,len);
		swap(s[i],s[flag]);
	}
	search(s,time,flag+1,len);
}
int main()
{
	int t,len;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%d",&num,&k);
		len=strlen(num);
		k=min(len,k);
		minm=INT_MAX;
		maxm=-1;
		search(num,0,0,len);
		printf("%d %d\n",minm,maxm,len); 
	}
}