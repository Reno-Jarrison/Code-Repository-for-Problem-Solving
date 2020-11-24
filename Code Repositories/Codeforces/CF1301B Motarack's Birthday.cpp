#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
ll a[maxn];
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		set<int>s;
		ll m=0,k=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		a[0]=a[n+1]=-1;
		for(int i=1;i<=n;i++)
			if(a[i]==-1) 
			{
				if(a[i-1]!=-1) s.insert(a[i-1]);
				if(a[i+1]!=-1) s.insert(a[i+1]);
			}
			else
			{
				if(a[i-1]!=-1) m=max(m,abs(a[i]-a[i-1]));
				if(a[i+1]!=-1) m=max(m,abs(a[i]-a[i+1]));
			}
		if(s.size())
		{
			ll mnv=*s.begin(),mxv=*--s.end();
			k=(mnv+mxv)/2;
			m=max(m,max(mxv-k,k-mnv));
		}
		cout<<m<<" "<<k<<endl;
	}
}