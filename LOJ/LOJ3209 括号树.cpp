#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+5;
char s[maxn];
int fat[maxn],dp[maxn];
ll ans[maxn],res;
vector<int>e[maxn];
stack<int>stk;
void link(int u,int v)
{	e[u].push_back(v),fat[v]=u; }
void dfs(int u)
{
	int top=-1;
	if(s[u]==')'&&!stk.empty())
	{
		top=stk.top(); stk.pop();
		dp[u]=dp[fat[top]]+1;
	}
	else if(s[u]=='(') stk.push(u);
	ans[u]=ans[fat[u]]+dp[u];
	res^=u*ans[u];
	for(int v:e[u]) dfs(v);
	if(s[u]=='(') stk.pop();
	else if(top!=-1) stk.push(top);
}
int main()
{
	int n,f;
	scanf("%d%s",&n,s+1);
	for(int i=2;i<=n;i++)
		scanf("%d",&f),link(f,i);
	dfs(1),printf("%lld\n",res);
}