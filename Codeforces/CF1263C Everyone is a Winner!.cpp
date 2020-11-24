#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		set<int>set;
		set.insert(0);
		for(int i=1;i*i<=n;i++)
			set.insert(n/i),set.insert(i);
		int siz=set.size();
		cout<<siz<<endl;
		for(int i:set) cout<<i<<" ";
		puts("");
	}	
}