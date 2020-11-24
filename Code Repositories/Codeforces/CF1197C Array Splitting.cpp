#include<bits/stdc++.h>
#define ll long long
#define maxn 300005
using namespace std;
ll a[maxn],b[maxn],ans;
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],b[i]=a[i]-a[i-1];
	sort(b+2,b+n+1);
	ans=a[n]-a[1];
	for(int i=n;i>n-k+1;i--)
		ans-=b[i];
	cout<<ans; 
}
