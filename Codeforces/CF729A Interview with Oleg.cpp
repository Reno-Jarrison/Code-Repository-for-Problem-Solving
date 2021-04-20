#include<bits/stdc++.h>
using namespace std;
char s[105],t[105];
int main()
{
	int n,pt=0;
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++)
	{
		int ok=0;
		if(i+2<=n&&s[i]=='o'&&s[i+1]=='g'&&s[i+2]=='o')
		{
			ok=1;
			while(i+2<=n&&s[i+1]=='g'&&s[i+2]=='o') i+=2;
		}
		if(ok) t[pt++]='*',t[pt++]='*',t[pt++]='*';
		else t[pt++]=s[i];
	}
	printf("%s\n",t);
}