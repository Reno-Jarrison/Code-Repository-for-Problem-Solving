#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
char s[maxn];
int main()
{
	scanf("%s",s);
	int len=strlen(s);
	if(s[len-1]!='s') s[len]='s';
	else s[len]='e',s[len+1]='s';
	printf("%s\n",s);
}