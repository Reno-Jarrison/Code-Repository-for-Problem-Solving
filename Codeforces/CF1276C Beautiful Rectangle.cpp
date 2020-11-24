#include<bits/stdc++.h>
using namespace std;
const int maxn=4e5+5;
vector<int>num[maxn];
map<int,int>mp;
int sum[maxn];
int main()
{
	int n,a;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a),mp[a]++;
	for(auto i:mp)
		num[i.second].push_back(i.first);
	sum[n]=num[n].size();
	for(int i=n-1;i;i--)
		sum[i]=sum[i+1]+num[i].size();
	int siz=0,p=0,q=0,cnt=0;
	for(int i=1;i*i<=n;i++)
	{
		cnt+=sum[i];
		int j=cnt/i;
		if(i<=j&&i*j>siz) siz=i*j,p=i,q=j;
	}
	printf("%d\n%d %d\n",siz,p,q);
	vector<vector<int> >ans(p,vector<int>(q));
	int x=0,y=0;
	for(int i=n;i;i--)
		for(int val:num[i])
			for(int j=1;j<=min(i,p);j++)
			{
				if(ans[x][y]) x=(x+1)%p;
				if(!ans[x][y]) ans[x][y]=val;
				x=(x+1)%p,y=(y+1)%q;
			}
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<q;j++)
			printf("%d ",ans[i][j]);
		puts("");
	}
}