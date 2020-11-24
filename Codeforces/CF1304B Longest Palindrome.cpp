#include<bits/stdc++.h>
using namespace std;
set<string>st;
int main()
{
	int n,m;
	string s,t,p="",ans="";
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s,t=s;
		reverse(t.begin(),t.end());
		if(s==t) p=t;
		else if(st.count(t)) ans+=t;
		st.insert(s);
	}
	string r=ans;
	reverse(r.begin(),r.end());
	ans=ans+p+r;
	cout<<ans.size()<<endl<<ans<<endl;
}