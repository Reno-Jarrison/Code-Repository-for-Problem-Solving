#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int l[maxn],r[maxn],n;
bool check(int len)
{
	for(int i=1;i+len-1<=n;i++)
	{
		int L=max(l[i],l[i+len-1]);
		int R=min(r[i],r[i+len-1]);
		if(R-L+1>=len) return true;
	}
	return false;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&l[i],&r[i]);
	int l=0,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	printf("%d",r);
}