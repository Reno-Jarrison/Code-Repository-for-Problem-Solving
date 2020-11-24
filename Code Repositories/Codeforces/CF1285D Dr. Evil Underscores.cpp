#include<bits/stdc++.h>
using namespace std;
int dfs(vector<int>& u,int bit)
{
	if(!bit) return 0;
	vector<int>v[2];
	for(int x:u)
		v[(x&(1<<(bit-1)))!=0].push_back(x);
	if(!v[0].size()||!v[1].size()) 
		return dfs(u,bit-1);
	return (1<<(bit-1))+min(dfs(v[0],bit-1),dfs(v[1],bit-1));
}
int main()
{
	int n,x;
	cin>>n;
	vector<int>vt;
	for(int i=1;i<=n;i++)
		cin>>x,vt.push_back(x);
	cout<<dfs(vt,30);
}