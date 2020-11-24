#include<iostream>
using namespace std;
int main()
{
	int n,k,last=1;
	cin>>n>>k;
	cout<<1;
	for(int i=1;i<=k;i++)
	{
		if(i%2) last+=k-i+1;
		else last-=k-i+1;
		cout<<" "<<last;
	}
	for(int i=k+2;i<=n;i++)
		cout<<" "<<i;	 
} 