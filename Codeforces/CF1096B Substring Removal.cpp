#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int maxn=1e6+5,mod=998244353;
char s[maxn];
int main()
{
	int n,l=1,r=1,ans=0;
	scanf("%d%s",&n,s+1);
	for(int i=2;i<=n;i++)
		if(s[i]!=s[i-1]) break;
		else l++;
	for(int i=n-1;i;i--)
		if(s[i]!=s[i+1]) break;
		else r++;
	if(s[1]==s[n]) ans=(1LL*(l+1)*(r+1))%mod;
	else ans=(l+r+1)%mod;
	printf("%d",ans);
}