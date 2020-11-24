#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int a[maxn];
int main()
{
	int n,p,mxv=0;
	cin>>n>>p;
	for(int i=0;i<n;i++)
		cin>>a[i],mxv=max(mxv,a[i]);
	sort(a,a+n);
	int l=0,r=mxv;
	for(int i=0;i<n;i++)
		l=max(l,a[i]-i);
	for(int i=0;i+p-1<n;i++)
		r=min(r,a[i+p-1]-i-1);
	if(l>r) l=r+1;
	cout<<r-l+1<<endl;
	for(int i=l;i<=r;i++)
		cout<<i<<" ";
}