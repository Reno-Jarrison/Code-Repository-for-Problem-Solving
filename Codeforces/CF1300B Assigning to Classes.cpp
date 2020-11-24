#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int a[maxn];
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n*2;i++) cin>>a[i];
		sort(a+1,a+2*n+1);
		cout<<a[n+1]-a[n]<<endl;
	}
}