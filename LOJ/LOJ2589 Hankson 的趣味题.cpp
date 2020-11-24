#include<bits/stdc++.h>
#define ll long long
using namespace std;
int gcd(int a,int b)
{	return b?gcd(b,a%b):a; }
bool check(int i,int j,int a1,int a,int b)
{	return i%a1==0&&gcd(i/a1,a)==1&&gcd(j,b)==1; } 
int main()
{
	int n;
	ll a0,a1,b0,b1,a,b;
	cin>>n;
	while(n--)
	{
		int cnt=0;
		cin>>a0>>a1>>b0>>b1,a=a0/a1,b=b1/b0;
		for(int i=1;(ll)i*i<=b1;i++)
			if(b1%i==0)
			{
				int j=b1/i;
				check(i,j,a1,a,b)? cnt++:false;
				j!=i&&check(j,i,a1,a,b)? cnt++:false;
			}
		cout<<cnt<<endl;
	}
}