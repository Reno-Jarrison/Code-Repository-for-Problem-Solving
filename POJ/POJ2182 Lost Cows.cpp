#include<iostream>
#define lowbit(x) (x)&(-x)
using namespace std;
const int maxn=8e3+5;
int a[maxn],tree[maxn],ans[maxn];
void update(int x,int val,int n)
{	while(x<=n) tree[x]+=val,x+=lowbit(x); }
int query(int x)
{
	int ans=0;
	while(x) ans+=tree[x],x-=lowbit(x);
	return ans;
}
int find(int x,int n)
{
	int l=0,r=n,mid;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(query(mid)<x) l=mid+1;
		else r=mid-1;
	}
	return l;
}
int main()
{
	int n;
	cin>>n,a[1]=0;
	for(int i=2;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) tree[i]=lowbit(i);
	for(int i=n;i;i--)
		ans[i]=find(a[i]+1,n),update(ans[i],-1,n);
	for(int i=1;i<=n;i++) cout<<ans[i]<<endl;
}