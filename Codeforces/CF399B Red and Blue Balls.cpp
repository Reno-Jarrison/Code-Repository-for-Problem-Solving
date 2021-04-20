#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	char s[55];
	int n;
	scanf("%d%s",&n,s);
	ll ans=0;
	for(int i=0;i<n;i++)
		if(s[i]=='B') ans|=1ll<<i;
	printf("%lld\n",ans);
}