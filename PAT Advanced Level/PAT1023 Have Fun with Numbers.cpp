#include<bits/stdc++.h>
using namespace std;
char s[25];
int num[25],cnt[10][2];
int main()
{
	scanf("%s",s+1);
	int len=strlen(s+1);
	for(int i=len;i;i--)
	{
		int cur=s[i]-'0';
		cnt[cur][0]++;
		num[i]+=cur*2;
		num[i-1]+=num[i]/10;
		num[i]%=10;
		cnt[num[i]][1]++;
	}
	int ok=1;
	if(num[0]) ok=0;
	for(int i=0;i<=9;i++)
		ok&=cnt[i][0]==cnt[i][1];
	puts(ok?"Yes":"No");
	if(num[0]) putchar('1');
	for(int i=1;i<=len;i++)
		putchar(num[i]+'0');
}