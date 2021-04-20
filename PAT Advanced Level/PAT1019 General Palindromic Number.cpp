#include<bits/stdc++.h>
using namespace std;
int num[15];
int main()
{
	int n,b,len=0;
	scanf("%d%d",&n,&b);
	while(n) num[++len]=n%b,n/=b;
	int ok=1;
	for(int i=1;i<=len;i++)
		ok&=num[i]==num[len-i+1];
	puts(ok?"Yes":"No");
	for(int i=len;i;i--)
		printf("%d%c",num[i],i==1?'\n':' ');
}