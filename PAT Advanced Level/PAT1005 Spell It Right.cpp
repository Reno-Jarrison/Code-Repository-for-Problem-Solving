#include<bits/stdc++.h>
using namespace std;
char s[105],digit[10][10]={"zero","one","two","three","four",
			"five","six","seven","eight","nine"};
int num[10];
int main()
{
	scanf("%s",s);
	int len=strlen(s),sum=0,cnt=0;
	for(int i=0;i<len;i++)
		sum+=s[i]-'0';
	if(!sum) num[++cnt]=0;
	while(sum)
		num[++cnt]=sum%10,sum/=10;
	for(int i=cnt;i;i--)
		printf("%s%c",digit[num[i]],i==1?'\n':' ');
}