#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,x;
	cin>>t;
	while(t--)
	{
		int ans=0,tmp=0,pt=0;
		scanf("%d",&n);
		set<int>s;
		vector<int>a;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&x);
			a.push_back(x);
			if(!s.count(x)) tmp++,s.insert(x);
			else 
			{	while(a[pt]!=x) s.erase(a[pt++]),tmp--; pt++; }
			ans=max(ans,tmp);
		}
		printf("%d\n",ans);
	}
}