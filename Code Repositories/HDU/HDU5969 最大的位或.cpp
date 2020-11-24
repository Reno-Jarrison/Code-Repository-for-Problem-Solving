#include<iostream>
#include<cstring>
#define ll long long 
using namespace std;
int lbit[70],rbit[70];
ll f(int x)
{
	if(x<30) return 1<<x;
	ll tmp=f(x/2);
	if(x&1) return tmp*tmp*2;
	else return tmp*tmp;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll l,r,ans=0;
		memset(lbit,0,sizeof(lbit));
		memset(rbit,0,sizeof(rbit));
		int lcnt=0,rcnt=0;
		cin>>l>>r;
		if(l<r) swap(l,r);
		while(l) lbit[lcnt++]=l&1,l>>=1;
		while(r) rbit[rcnt++]=r&1,r>>=1;
		for(ll i=lcnt-1;i>=0;i--)
		{
			if(lbit[i]==rbit[i]) ans+=lbit[i]?f(i):0;
			else
			{
				ans+=f(i+1)-1;
				break;
			}
		}
		cout<<ans<<endl;
	} 
} 