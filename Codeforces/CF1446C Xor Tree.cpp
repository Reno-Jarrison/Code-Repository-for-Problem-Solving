#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int a[maxn];
int solve(int pos,vector<int> vec)
{
	if(!pos) return 0;
	vector<int>cur[2];
	for(int x:vec)
		cur[(x&(1<<pos))!=0].push_back(x);
	if(cur[0].size()<=1)
		return solve(pos-1,cur[1]);
	if(cur[1].size()<=1)
		return solve(pos-1,cur[0]);
	int ans0=solve(pos-1,cur[0]),ans1=solve(pos-1,cur[1]);
	return min(cur[0].size()-1+ans1,cur[1].size()-1+ans0);
}
int main()
{
	int n;
	scanf("%d",&n);
	vector<int>vec;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),vec.push_back(a[i]);
	printf("%d\n",solve(30,vec));
}