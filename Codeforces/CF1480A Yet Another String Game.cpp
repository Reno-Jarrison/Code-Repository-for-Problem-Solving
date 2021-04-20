#include<bits/stdc++.h>
using namespace std;
char s[55];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		int len=strlen(s);
		for(int i=0;i<len;i++)
		{
			if(i&1) s[i]=s[i]=='z'?'y':'z';
			else s[i]=s[i]=='a'?'b':'a';
		}
		puts(s);
	}
}