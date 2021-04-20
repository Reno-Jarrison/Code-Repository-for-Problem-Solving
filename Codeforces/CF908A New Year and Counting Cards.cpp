#include<bits/stdc++.h>
using namespace std;
char v[6]="aeiou";
bool isvowel(char x)
{
	for(int i=0;i<5;i++)
		if(x==v[i]) return true;
	return false;
}
int main()
{
	char s[55];
	scanf("%s",s);
	int len=strlen(s),ans=0;
	for(int i=0;i<len;i++)
	{
		if(isdigit(s[i])&&((s[i]-'0')&1)) ans++;
		else if(isvowel(s[i])) ans++;
	}
	printf("%d\n",ans);
}