#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
ll a[maxn],s[maxn]; 
int main()
{
	int n,m;
	ll ans=0;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++)
		s[i]=(i-m>=0?s[i-m]:0)+a[i];
	for(int i=0;i<n;i++)
	{
		ans+=s[i];
		cout<<ans<<" ";
	}
}

