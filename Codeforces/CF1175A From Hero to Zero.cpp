#include<iostream>
#include<cmath>
#define ll long long
using namespace std;
int main()
{
	int t;
	ll n,k,step;
	cin>>t;
	while(t--)
	{
		step=0;
		cin>>n>>k;
		while(n)
		{
			if(n%k)
			{
				ll maxn=n/k*k;
				step+=n-maxn-1,n=maxn;
			}
			else n/=k;
			step++;
		}
		cout<<step<<endl;
	}
}
