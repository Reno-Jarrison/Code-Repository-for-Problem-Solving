#include<bits/stdc++.h>
using namespace std;
const int maxn=2e3+5;
int a[maxn];
vector<int>vec;
int main()
{
	int n,p,mxv=0;
	cin>>n>>p;
	for(int i=0;i<n;i++)
		cin>>a[i],mxv=max(mxv,a[i]);
	sort(a,a+n);
	for(int i=mxv-n+1;i<mxv;i++)
	{
		int ok=1,cnt=0,pt=0;
		while(pt<n&&a[pt]<i) pt++,cnt++;
		for(int j=0;j<n;j++)
		{
			while(pt<n&&a[pt]==i+j) pt++,cnt++;
			if(cnt%p==0)
			{	ok=0; break; }
			cnt--;
		}
		if(ok) vec.push_back(i);
	}
	cout<<vec.size()<<endl;
	for(int x:vec) cout<<x<<" ";
}