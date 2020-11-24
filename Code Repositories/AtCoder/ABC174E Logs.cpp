#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int a[maxn],n,k;
bool check(int mval)
{
	int cnt=0;
	for(int i=1;i<=n;i++)
		cnt+=a[i]/mval-(a[i]%mval==0);
	return cnt<=k;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int l=1,r=1e9;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",l);
}