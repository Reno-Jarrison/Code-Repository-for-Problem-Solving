#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
int main()
{
	int t,n;
	ll a,b;
	char s[maxn];
	cin>>t;
	while(t--)
	{
		cin>>n>>a>>b>>s;
		ll ans=a*n+b*(n+1),cnt0=0,cnt1=0;
		bool flag1=false;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='1') 
			{
				flag1=true;
				cnt1++;
				if(s[i+1]=='0') 
					ans+=(cnt1+1)*b,cnt1=0;
			}
			else 
			{
				if(flag1&&s[i-1]=='1') cnt0=1;
				else if(cnt0) cnt0++;
				if(flag1&&i<n-1&&s[i+1]=='1')
					ans+=min(a*2LL,b*(cnt0-1));
			}
		}
		if(flag1) ans+=a*2LL;
		cout<<ans<<endl;
	}
}

