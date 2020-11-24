#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5,mod=1e9+7;
char s[maxn];
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	ll ans=0,cnt=0,pre=0,num=0;
	for(int i=1;i<=n;i++)
	{
		ll x=s[i]-'0';
		ans=(ans*10+x*(cnt+1)+pre)%mod;
		cnt=(cnt+i)%mod;
		num=(num*10+x)%mod;
		pre=(pre+num)%mod;
	}
	printf("%lld\n",(ans-num+mod)%mod);
}