#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
struct node
{
	int l,r,d;
}p[maxn];
operator <(const node& x,const node& y)
{	return x.l<y.l; }
int a[maxn],m,n,k,t;
int check(int mval)
{
	int s=0,pt=1,ptx=0,l=-1,r=-1;
	while(pt<=k)
	{
		l=p[pt].l,r=p[pt].r;
		if(p[pt].d<=mval)
		{	pt++; continue; }
		while(p[++pt].l<=r)
			if(p[pt].d>mval) r=max(r,p[pt].r);
		s+=l-ptx-1+3*(r-l+1),ptx=r;
	}
	s+=n+1-ptx;
	return s<=t;
}
int main()
{
	scanf("%d%d%d%d",&m,&n,&k,&t);
	for(int i=1;i<=m;i++) 
		scanf("%d",&a[i]);
	for(int i=1;i<=k;i++) 
		scanf("%d%d%d",&p[i].l,&p[i].r,&p[i].d);
	sort(a+1,a+m+1);
	sort(p+1,p+k+1);
	int l=a[1],r=a[m];
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) r=mid-1;
		else l=mid+1;
	}
	int id=lower_bound(a+1,a+m+1,l)-a;
	printf("%d",m-id+1);
}

