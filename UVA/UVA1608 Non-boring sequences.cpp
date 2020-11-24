#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int a[maxn],lst[maxn],nxt[maxn];
bool dac(int l,int r)
{
	if(l>=r) return true;
	int lpt=l,rpt=r;
	while(lpt<=rpt)
	{
		if(lst[lpt]<l&&nxt[lpt]>r)
			return dac(l,lpt-1)&&dac(lpt+1,r);
		else if(lst[rpt]<l&&nxt[rpt]>r)
			return dac(l,rpt-1)&&dac(rpt+1,r);
		lpt++,rpt--;
	}
	return false;
}
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		unordered_map<int,int>mp;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			lst[i]=mp[a[i]],mp[a[i]]=i;
		}
		mp.clear();
		for(int i=n;i;i--)
			nxt[i]=mp[a[i]]?mp[a[i]]:n+1,mp[a[i]]=i;
		puts(dac(1,n)?"non-boring":"boring");
	}
 } 