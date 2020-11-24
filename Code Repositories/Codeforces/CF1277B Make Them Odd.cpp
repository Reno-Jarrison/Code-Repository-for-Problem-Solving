#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t,n,a;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int ans=0;
		set<int>s;
		for(int i=1;i<=n;i++)
		{
			cin>>a;
			if(!(a&1)) s.insert(a);
		}
		while(s.size())
		{
			int x=*(--s.end());
			s.erase(x),x>>=1,ans++;
			if(!(x&1)) s.insert(x);
		}
		cout<<ans<<endl;
	}
}