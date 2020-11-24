#include<bits/stdc++.h>
#define ll long long
using namespace std;
int p[30];
ll fac(int x) { return x==1?1:x*fac(x-1); }
int main()
{
	ll x,tmp,cnt,tot,ans;
	while(cin>>x)
	{
		tmp=x,cnt=tot=0;
		for(int i=2;i*i<=x&&tmp!=1;i++)
			if(!(tmp%i))
			{
				p[++cnt]=0;
				while(!(tmp%i)) 
					tmp/=i,p[cnt]++;
				tot+=p[cnt];
			}
		tmp!=1?tot++:false;
		ans=fac(tot); 
		for(int i=1;i<=cnt;i++)
			ans/=fac(p[i]);
		cout<<tot<<" "<<ans<<endl;
	}
}