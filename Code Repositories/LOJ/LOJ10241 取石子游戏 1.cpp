#include<iostream>
using namespace std;
int main()
{
	int n,k,ans;
	cin>>n>>k;
	ans=n%(k+1)?1:2;
	cout<<ans;
}