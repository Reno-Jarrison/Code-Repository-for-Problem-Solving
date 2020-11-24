#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
char s[maxn];
int main()
{
	scanf("%s",s);
	int len=strlen(s),sum=0;
	for(int i=0;i<len;i++)
		sum=(sum+s[i]-'0')%9;
	puts(sum?"No":"Yes");
}