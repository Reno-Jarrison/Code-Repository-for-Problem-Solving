#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int a[maxn],n;
int main()
{
	cin>>n;
	vector<int>bit[35];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int tmp=a[i],cnt=0;
		while(tmp)
		{
			if(tmp&1) bit[cnt].push_back(a[i]);
			tmp>>=1,cnt++;
		}
	}
	int ans=-1;
	for(int i=0;i<=32;i++)
		if(bit[i].size()==1) ans=bit[i][0];
	if(ans!=-1) for(int i=1;i<=n;i++)
		if(a[i]==ans) 
		{ 	swap(a[i],a[1]); break; }
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
}