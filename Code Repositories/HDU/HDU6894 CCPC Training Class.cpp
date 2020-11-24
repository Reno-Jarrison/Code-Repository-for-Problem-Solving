#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
char s[maxn];
int main()
{
	int t,ks=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		int len=strlen(s),ans=0,cnt[26]={0};
		for(int i=0;i<len;i++)
			cnt[s[i]-'a']++;
		for(int i=0;i<26;i++)
			ans=max(ans,cnt[i]);
		printf("Case #%d: %d\n",++ks,ans);
	}
}