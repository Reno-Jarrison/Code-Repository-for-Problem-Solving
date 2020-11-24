#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
ll s[maxn],n;
int a[maxn],tag[maxn];
int main()
{
	int m,len1=0,len2=0;
	scanf("%lld%d%d",&n,&a[1],&m);
	s[1]=a[1],tag[a[1]]=1;
	for(int i=2;i<=m+1;i++)
	{
		a[i]=1LL*a[i-1]*a[i-1]%m;
		if(tag[a[i]])
		{	len1=tag[a[i]]-1,len2=i-tag[a[i]]; break; }
		tag[a[i]]=i;
		s[i]=s[i-1]+a[i];
	}
	ll ans=s[min((ll)len1,n)];
	n-=min(n,(ll)len1);
	ans+=n/len2*(s[len1+len2]-s[len1]);
	ans+=s[len1+n%len2]-s[len1];
	printf("%lld\n",ans);
}