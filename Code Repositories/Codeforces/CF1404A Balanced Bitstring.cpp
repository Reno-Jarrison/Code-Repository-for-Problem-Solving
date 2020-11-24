#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+5;
char s[maxn];
int pos[maxn];
int main()
{
	int t,n,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%s",&n,&k,s);
		for(int i=0;i<k;i++)
		{
			if(s[i]=='0') pos[i]=0;
			if(s[i]=='1') pos[i]=1;
			if(s[i]=='?') pos[i]=2;
		}
		int ok=1;
		for(int i=k;ok&&i<n;i++)
		{
			if(s[i]=='?') continue;
			if(pos[i%k]==2) pos[i%k]=s[i]-'0';
			else if(s[i]-'0'!=pos[i%k]) ok=0;
		}
		int cnt[3]={0};
		for(int i=0;i<k;i++) cnt[pos[i]]++;
		if(max(cnt[0],cnt[1])>k/2) ok=0;
		puts(ok?"YES":"NO");
	}
}	