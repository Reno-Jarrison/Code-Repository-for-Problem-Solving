#include<bits/stdc++.h>
using namespace std;
char s[1000];
int main()
{
	scanf("%s",s);
	int len=strlen(s),tag=0;
	int L=0,R=0,l=0,r=0,win=-1;
	for(int i=0;i<len;i++)
	{
		if(s[i]=='S')
			!tag?l++:r++;
		else if(s[i]=='R')
			tag?l++:r++,tag^=1;
		else if(win==-1)
		{
			printf("%d (%d",L,l);
			if(!tag) printf("*");
			printf(") - %d (%d",R,r);
			if(tag) printf("*");
			printf(")\n");
		}
		else
		{
			printf("%d",L);
			if(!win) printf(" (winner)");
			printf(" - %d",R);
			if(win) printf(" (winner)");
			puts("");
		}
		if((l>=5&&l-r>=2)||l==10) L++,l=r=0,tag=0;
		if((r>=5&&r-l>=2)||r==10) R++,l=r=0,tag=1;
		if(L==2) win=0;
		if(R==2) win=1;
	}
}