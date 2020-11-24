#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5,mod=1e9+7;
ll fib[maxn]={1,1};
char s[maxn];
void getfib()
{
	for(int i=2;i<=maxn-5;i++)
		fib[i]=(fib[i-1]+fib[i-2])%mod;
}
int main()
{
	getfib();
	ll ans=1,cnt=1;
	cin>>(s+1);
	int len=strlen(s+1);
	for(int i=1;i<=len+1;i++)
	{
		if(s[i]=='m'||s[i]=='w') { cout<<0; return 0; }
		if(s[i]!=s[i-1]) ans=ans*fib[cnt]%mod,cnt=1;
		else if(s[i]=='n'||s[i]=='u') cnt++;
	}
	cout<<ans;
}

