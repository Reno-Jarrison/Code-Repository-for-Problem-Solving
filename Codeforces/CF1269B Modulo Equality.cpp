#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e3+5;
int a[maxn],b[maxn],tmp[maxn];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	set<int>s;
	for(int i=1;i<=n;i++)
		cin>>b[i],s.insert((b[i]-a[1]+m)%m);
	sort(b+1,b+n+1);
	for(int x:s)
	{
		memcpy(tmp,a,sizeof(a));
		for(int i=1;i<=n;i++)
			tmp[i]=(tmp[i]+x)%m;
		sort(tmp+1,tmp+n+1);
		bool ok=true;
		for(int i=1;i<=n&&ok;i++)
			if(tmp[i]!=b[i]) ok=0;
		if(ok) { cout<<x; break; }
	}
}