#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int a[maxn],tag[maxn];
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		vector<int>vec;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&tag[i]);
			if(!tag[i]) vec.push_back(a[i]);
		}
		sort(vec.begin(),vec.end());
		for(int i=1;i<=n;i++)
		{
			if(tag[i]) continue;
			a[i]=vec[vec.size()-1];
			vec.pop_back();
		}
		for(int i=1;i<=n;i++)
			printf("%d%c",a[i],i==n?'\n':' ');
	}
}