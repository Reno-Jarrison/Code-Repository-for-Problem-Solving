#include<iostream>
using namespace std;
int d[50005],dist,n,m;
bool check(int len)
{
	int cnt=0,last=0,pt=1;
	while(pt<=n)
	{
		if(d[pt]-d[last]<len) cnt++;
		else last=pt;
		pt++;
	}
	return cnt<=m;
}
int main()
{
	cin>>dist>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>d[i];
	int l=1,r=dist;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<r;		
}