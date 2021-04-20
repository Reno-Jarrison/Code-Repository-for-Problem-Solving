#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int dp[1<<8],odd[1<<8],bit[maxn];
int main()
{
	int n,m,k,l,r;
	scanf("%d%d%d",&n,&m,&k);
	vector<pair<int,int>>vec;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&l,&r);
		vec.emplace_back(l,i);
		vec.emplace_back(r+1,-i);
	}
	sort(vec.begin(),vec.end());
	int las=0,cur=0;
	for(int i=0;i<(1<<k);i++)
		odd[i]=odd[i>>1]^(i&1);
	for(auto x:vec)
	{
		int sum=x.first-las,idx=x.second;
		if(idx>0)
		{
			bit[idx]=0;
			while(cur&(1<<bit[idx])) bit[idx]++;
			int pos=1<<bit[idx];
			for(int i=0;i<(1<<k);i++) if((i|cur)==cur)
				dp[i|pos]=dp[i]=dp[i]+sum*odd[i];
			cur^=pos;
		}
		else
		{
			int pos=1<<bit[-idx];
			cur^=pos;
			for(int i=0;i<(1<<k);i++) if((i|cur)==cur)
				dp[i]=max(dp[i]+sum*odd[i],dp[i|pos]+sum*odd[i|pos]);
		}
		las=x.first;
	}
	printf("%d\n",dp[0]);
}