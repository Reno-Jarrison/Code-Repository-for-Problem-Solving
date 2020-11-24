#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e4;
string s;
ll num[105];
ll gcd(ll a,ll b)
{	return !b?a:gcd(b,a%b); }
int main()
{
	int n;
	cin>>n;
	getchar();
	while(n--)
	{
		getline(cin,s);
		ll d=1,cnt=0;
		stringstream nums(s);
        while (nums>>num[cnt++]);
		for(int i=0;i<cnt-1;i++)
		for(int i=0;i<cnt-1;i++)
			for(int j=i+1;j<cnt-1;j++)
				d=max(d,gcd(num[i],num[j])); 
		cout<<d<<endl;
	}
}
