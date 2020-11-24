#include<iostream>
#include<algorithm>
#define maxn 300005
#define ll long long
using namespace std;
int a[maxn];
ll s[maxn];
int main()
{
	int n,k;
	ll ans=0,total;
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=n-1;i;i--) s[i]=s[i+1]+a[i];
	total=a[0]+s[1];
	sort(s+1,s+n);
	for(int i=n-1;i>n-k;i--) ans+=s[i];
	cout<<ans+total;
}
