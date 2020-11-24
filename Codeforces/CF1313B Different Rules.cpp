#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,x,y;
	cin>>t;
	while(t--)
	{
		cin>>n>>x>>y;
		cout<<min(max(x+y-n,0)+1,n)<<" "<<min(n,x+y-1)<<endl;
	}
}