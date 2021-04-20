#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
char s[maxn],key[maxn],t[maxn];
int main()
{
	scanf("%s%s",s,key);
	int lens=strlen(s),lenk=strlen(key);
	for(int i=0;i<lens;i++)
	{
		if(i<lenk) t[i]=(s[i]-key[i]+26)%26+'A';
		else t[i]=(s[i]-t[i-lenk]+26)%26+'A';
	}
	printf("%s\n",t);
}