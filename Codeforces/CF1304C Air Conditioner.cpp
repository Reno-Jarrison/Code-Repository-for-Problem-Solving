#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=105;
int main()
{
	int q,n,m;
	cin>>q;
	while(q--)
	{
		cin>>n>>m;
		ll l,h,t,L=m,H=m,las=0;
		bool ok=true;
		for(int i=1;i<=n;i++)
		{
			cin>>t>>l>>h;
			H+=t-las,L-=t-las;
			H=min(H,h),L=max(L,l);
			if(L>H) ok=false;
			las=t;
		}
		puts(ok?"YES":"NO");
	}
}