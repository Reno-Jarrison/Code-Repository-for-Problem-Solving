#include<iostream>
#include<set>
using namespace std;
int main()
{
	int t,n,a,k,s;
	cin>>t;
	while(t--)
	{
		set<int>set;
		cin>>n>>s>>k;
		for(int i=1;i<=k;i++)
			cin>>a,set.insert(a);
		int ans=0;
		while((set.count(s+ans)||s+ans>n)&&(set.count(s-ans)||s<=ans)) ans++;
		cout<<ans<<endl;
	}
}