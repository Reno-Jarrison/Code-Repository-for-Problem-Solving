#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int w[maxn],s[maxn],x[maxn],y[maxn],vis[maxn];
vector<int>vec[maxn];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=m;i++)
	{
		cin>>x[i]>>y[i];
		s[x[i]]++,s[y[i]]++;
		vec[x[i]].push_back(i);
		vec[y[i]].push_back(i);
	}
	set<pair<int,int>>st;
	for(int i=1;i<=n;i++) if(s[i]) 
		w[i]-=s[i],st.insert(make_pair(w[i],i));
	int ok=1;
	vector<int>ans;
	while(st.size())
	{
		auto cur=st.end(); cur--;
		if(cur->first<0) { ok=0; break; }
		int id=cur->second;
		vis[id]=1,st.erase(cur);
		for(int i:vec[id])
		{
			if(vis[x[i]]&&vis[y[i]]) continue;
			ans.push_back(i);
			int pt=vis[y[i]]?x[i]:y[i];
			st.erase(make_pair(w[pt],pt));
			st.insert(make_pair(++w[pt],pt));
		}
	}
	if(!ok) puts("DEAD");
	else
	{
		puts("ALIVE");
		reverse(ans.begin(),ans.end());
		for(int i:ans)
			cout<<i<<" ";
	}
}