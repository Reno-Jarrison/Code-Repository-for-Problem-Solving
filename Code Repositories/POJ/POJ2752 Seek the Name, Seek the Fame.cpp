#include<iostream>
#include<cstdio>
#include<cstring>
#define mod 19260817
using namespace std;
char s[400005];
int nxt[400005];
void printnxt(int x)
{
	if(x==0) return;
	printnxt(nxt[x]);
	printf("%d ",x);
}
int main()
{
	while(scanf("%s",&s)!=EOF)
	{
		int len=strlen(s),i=0,j=-1;
		nxt[0]=-1;
		while(s[i])
			if(j==-1||s[i]==s[j])
				nxt[++i]=++j;
			else
				j=nxt[j];
		printnxt(nxt[i]);
		cout<<len<<" ";
		cout<<endl;
	}
}