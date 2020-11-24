#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
ll a[maxn],sum[maxn],s;
int main()
{
	int t,n,idx,ans,mid;
	cin>>t;
	while(t--)
	{
		ll mxv=0;
		cin>>n>>s,idx=mid=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i],sum[i]=sum[i-1]+a[i];
			if(sum[i]<=s) { idx=i; if(a[i]>mxv) mxv=a[i],mid=i; }
		}
		if(idx==n) ans=0;
		else
		{
			int id1=idx+2,cnt1=0; ll tmp1=sum[idx];
			while(id1<=n&&tmp1+a[id1]<=s) cnt1++,tmp1+=a[id1++];
			int id2=idx+1,cnt2=0; ll tmp2=sum[idx]-mxv;
			while(id2<=n&&tmp2+a[id2]<=s) cnt2++,tmp2+=a[id2++];
			if(max(cnt1,cnt2)==0) ans=0;
			else ans=cnt1>=cnt2?idx+1:mid;
		}
		printf("%d\n",ans);
	}
}