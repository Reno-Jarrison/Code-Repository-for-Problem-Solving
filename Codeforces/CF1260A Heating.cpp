#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int n,c,sum;
	ll ans;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>c>>sum;
		ll k=sum/c,num=sum%c;
		ans=num*pow(k+1,2)+(c-num)*pow(k,2);
		cout<<ans<<endl;
	}		 
}

