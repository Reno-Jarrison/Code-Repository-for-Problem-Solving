#include<bits/stdc++.h>
using namespace std;
char s[105];
void print(int cnt,char c)
{
	if(cnt>1) printf("%d",cnt);
	putchar(c);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		int n=strlen(s+1),las=-1,cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(las!=s[i]-'A')
			{
				if(~las) print(cnt,las+'A');
				cnt=0,las=s[i]-'A';
			}
			cnt++;
			if(i==n) print(cnt,s[i]);
		}
		puts("");
	}	
}