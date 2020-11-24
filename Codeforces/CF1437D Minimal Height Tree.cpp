#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int a[maxn];
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int cnt=0;
		vector<int>vec;
		for(int i=2;i<=n;i++,cnt++)
			if(a[i]<a[i-1])
				vec.push_back(cnt),cnt=0;
		vec.push_back(cnt);
		int siz=vec.size(),pt=0,las=1,cur=0,ans=0;
		while(pt<siz)
		{
			ans++,cur=0;
			for(int i=0;i<las&&pt<siz;i++)
				cur+=vec[pt++];
			las=cur;
		}
		printf("%d\n",ans);
	}
}