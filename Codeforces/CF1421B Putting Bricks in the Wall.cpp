#include<bits/stdc++.h>
using namespace std;
char s[205][205];
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%s",s[i]+1);
		vector<pair<int,int>>ans[2];
		ans[s[1][2]=='1'].push_back(make_pair(1,2));
		ans[s[2][1]=='1'].push_back(make_pair(2,1));
		ans[s[n-1][n]=='0'].push_back(make_pair(n-1,n));
		ans[s[n][n-1]=='0'].push_back(make_pair(n,n-1));
		if(ans[0].size()>2) swap(ans[0],ans[1]);
		printf("%d\n",(int)ans[0].size());
		for(auto x:ans[0])
			printf("%d %d\n",x.first,x.second);
	}
}