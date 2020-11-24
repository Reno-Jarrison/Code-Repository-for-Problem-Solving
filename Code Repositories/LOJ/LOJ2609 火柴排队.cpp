#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-x))
using namespace std;
const int maxn=1e5+5,mod=1e8-3;
int ida[maxn],idb[maxn],q[maxn],tree[maxn];
void update(int x,int lim,int val)
{	while(x<=lim) tree[x]+=val,x+=lowbit(x); }
int query(int x)
{
	int ans=0;
	while(x) ans+=tree[x],x-=lowbit(x);
	return ans;
}
struct node
{	int num,pos; }a[maxn],b[maxn];
bool operator <(const node& x,const node& y)
{	return x.num<y.num; }
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i].num),a[i].pos=i;
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i].num),b[i].pos=i;
	sort(a+1,a+n+1),sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)
		q[a[i].pos]=b[i].pos;
	int ans=0;
	for(int i=n;i;i--)
	{
		ans=(ans+query(q[i]))%mod;
		update(q[i],n,1);
	}
	printf("%d\n",ans);
}