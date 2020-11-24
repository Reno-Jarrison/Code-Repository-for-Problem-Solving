#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
struct node
{
    int l,r;
    friend bool operator <(const node& x,const node& y)
    {	return x.l<y.l; }
}a[maxn];
bool check(ll mval,int n,ll lim)
{
	int mid=(n>>1)+1,cnt=0;
    ll cost=0;
	for(int i=n;i;i--)
		if(cnt<mid&&a[i].r>=mval)
			cost+=max(mval,(ll)a[i].l),cnt++; 	
		else cost+=a[i].l;
	return cnt==mid&&cost<=lim;
}
int main()
{
    int t,n; 
	ll s,l,r=0,mid;
    scanf("%d",&t);
    while(t--)
    {
    	scanf("%d%lld",&n,&s);
    	for(int i=1;i<=n;i++)
    		scanf("%d%d",&a[i].l,&a[i].r),r=max(r,(ll)a[i].r);
    	sort(a+1,a+n+1),l=a[(n>>1)+1].l;
    	while(l<=r)
    	{
    		mid=(l+r)>>1;
    		if(check(mid,n,s)) l=mid+1;
    		else r=mid-1;
    	}
    	printf("%lld\n",r);
   	}
}
