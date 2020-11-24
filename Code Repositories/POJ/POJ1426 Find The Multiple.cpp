#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
int n,ok;
void dfs(int step,ll cur)
{
	if(step==20||ok) return;
	if(cur%n==0)
	{	printf("%lld\n",cur),ok=1; return; }
	ll nxt=cur*10;
	dfs(step+1,nxt),dfs(step+1,nxt+1);
}
int main()
{
	while(scanf("%d",&n)&&n)
		ok=0,dfs(1,1);
}