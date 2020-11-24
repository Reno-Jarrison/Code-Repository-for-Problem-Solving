#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int cnt,a[maxn],ans[maxn];
set<int>s,vis;
int main()
{
	int n,id; 
	bool ok=true;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>id; 
		if(!s.size()) cnt++,vis.clear();
		if(id>0&&!s.count(id)&&!vis.count(id))
			vis.insert(id),s.insert(id);
		else if(id<0&&s.count(-id)) s.erase(-id);
		else ok=false;
		ans[cnt]++;
	}
	if(s.size()||!ok) { puts("-1"); return 0; }
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++)
		cout<<ans[i]<<" ";
}

