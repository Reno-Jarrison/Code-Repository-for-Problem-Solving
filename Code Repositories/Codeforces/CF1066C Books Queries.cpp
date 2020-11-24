#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int q,countr=0,countl=0,r[200005]={0},l[200005]={0};
	scanf("%d",&q);
	for(int k=0;k<q;k++)
	{
		char ch;
		int a;
		scanf("\n%c%d",&ch,&a); 
		if(ch=='R')
			r[a]=++countr;
		if(ch=='L')
			l[a]=++countl;
		if(ch=='?')
		{
			if(r[a])
			printf("%d\n",countr-r[a]<r[a]+countl-1?countr-r[a]:r[a]+countl-1);
			if(l[a])
			printf("%d\n",countl-l[a]<l[a]+countr-1?countl-l[a]:l[a]+countr-1);
		}
	}
 } 