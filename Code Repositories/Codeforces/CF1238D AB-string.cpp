#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=3e5+5;
char s[maxn];
int main()
{
	int n,id,cnt[2]={0},flag[2]={0};
	ll ans=0;
	scanf("%d%s",&n,s);
	cnt[s[0]-'A']++,flag[s[0]-'A']=1;
	for(int i=1;i<n;i++)
	{
		id=s[i]-'A',ans+=i;
		if(s[i]==s[i-1]) ans-=flag[id^1];
		else ans-=cnt[id^1];
		flag[id]=1,cnt[id]++,cnt[id^1]=0;
	}
	printf("%lld",ans);
}