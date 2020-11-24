#include<bits/stdc++.h>
using namespace std;
const int maxn=3005;
char s[maxn];
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n>>s;
		vector<int>ans;
		for(int i=0;i<n&&ans.size()<2;i++)
			if((s[i]-'0')&1) ans.push_back(s[i]);
		if(ans.size()!=2) puts("-1");
		else printf("%c%c\n",ans[0],ans[1]);
	}
}