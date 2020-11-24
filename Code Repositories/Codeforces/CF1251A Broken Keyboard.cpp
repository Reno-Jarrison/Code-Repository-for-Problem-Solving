#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
char s[maxn];
int ans[30];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(ans,0,sizeof(ans));
		scanf("%s",s);
		int len=strlen(s),cnt=1;
		for(int i=1;i<len;i++)
			if(s[i]==s[i-1]) cnt++;
			else
			{
				if(cnt&1) ans[s[i-1]-'a']=1;
				cnt=1;
			}
		if(cnt&1) ans[s[len-1]-'a']=1;
		for(int i=0;i<26;i++)
			if(ans[i]) putchar(i+'a');
		puts("");
	}
}

