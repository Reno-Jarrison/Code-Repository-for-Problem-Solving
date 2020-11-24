#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,tag;
	cin>>t;
	while(t--)
	{
		cin>>n,tag=n&1,n=n/2-1;
		cout<<(tag?7:1);
		while(n--) cout<<1;
		cout<<endl;
	}
}