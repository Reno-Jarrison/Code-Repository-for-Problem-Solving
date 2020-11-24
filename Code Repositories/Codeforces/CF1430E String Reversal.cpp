#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-x))
using namespace std;
const int maxn=2e5+5;
char s[maxn],r[maxn];
queue<int>que[26];
ll tree[maxn];
void update(int x,int val,int lim)
{	while(x<=lim) tree[x]+=val,x+=lowbit(x); }
ll query(int x)
{
	ll ans=0;
	while(x) ans+=tree[x],x-=lowbit(x);
	return ans;
}
int main()
{
	int n;
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++)
		r[i]=s[n-i+1];
	for(int i=1;i<=n;i++)
		que[s[i]-'a'].push(i),update(i,1,n);
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		int cur=r[i]-'a',id=que[cur].front();
		que[cur].pop();
		ans+=query(id)-i;
		update(1,1,n),update(id+1,-1,n);
	}
	printf("%lld\n",ans);
}