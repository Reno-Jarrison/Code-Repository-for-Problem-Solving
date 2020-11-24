#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int p[maxn],cnt[2];
int main()
{
	int n; cin>>n;
	vector<int>v,num[2];
	cnt[0]=n>>1,cnt[1]=n-cnt[0];
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		if(p[i]) cnt[p[i]&1]--,v.push_back(i);
	}
	int siz=v.size(),ans=0;
	if(!siz) { puts(n==1?"0":"1"); return 0; }
	for(int i=1;i<siz;i++)
	{
		int dif=v[i]-v[i-1]-1;
		if((p[v[i]]&1)!=(p[v[i-1]]&1)) ans++;
		else if(dif) num[p[v[i]]&1].push_back(dif);
	}
	for(int i=0;i<=1;i++)
	{
		sort(num[i].begin(),num[i].end());
		for(int x:num[i])
			cnt[i]<x?ans+=2:cnt[i]-=x;
	}
	int l=v[0],r=v[siz-1];
	l-1&&cnt[p[l]&1]<l-1?ans++:cnt[p[l]&1]-=l-1;
	n-r&&cnt[p[r]&1]<n-r?ans++:cnt[p[r]&1]-=n-r;
	cout<<ans<<endl;
}