#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=1e6+5; 
int main()
{
	ll n,p=-1,tmp,cnt=0;
	cin>>n,tmp=n;
	for(ll i=2;i<=maxn;i++)
		if(tmp%i==0) 
		{
			cnt++,p=i;
			while(tmp%i==0) tmp/=i;
		}
	if(tmp>1) cnt++,p=tmp; 
	if(cnt==1) cout<<p;
	else cout<<1;
}

