#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll l[105];
bool check(ll a,ll b,ll c)
{	return a!=b&&b!=c&&a!=c&&a+b>c&&abs(a-b)<c; }
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&l[i]);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				if(check(l[i],l[j],l[k])) ans++;
	printf("%d",ans);
}