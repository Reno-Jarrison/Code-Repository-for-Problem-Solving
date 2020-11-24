#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		cout<<min(a[n-1]-1,n-2)<<endl;
	}
}

