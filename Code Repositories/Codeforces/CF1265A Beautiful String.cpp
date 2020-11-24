#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
char s[maxn];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		int len=strlen(s),ok=1;
		if(s[0]=='?')
		{
			if(len==1||s[1]=='?') s[0]='a';
			else s[0]=(s[1]-'a'+1)%3+'a';
		}
		for(int i=1;i<len;i++)
		{
			if(s[i]=='?')
			{
				int tag[3]={0,0,0};
				tag[s[i-1]-'a']=1;
				if(i<len-1&&s[i+1]!='?')
					tag[s[i+1]-'a']=1;
				for(int j=0;j<3;j++)
					if(!tag[j]) { s[i]=j+'a'; break; }
			}
			else if(s[i]==s[i-1]) ok=0;
		}
		puts(ok?s:"-1");
	}
}