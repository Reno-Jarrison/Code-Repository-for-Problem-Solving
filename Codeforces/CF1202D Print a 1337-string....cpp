#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int m=(int)sqrt(n*2)-1;
		while(m*(m+1)/2<=n) m++;
		cout<<"133";
		for(int i=1;i<=n-m*(m-1)/2;i++) cout<<'7';
		for(int i=1;i<=m-2;i++) cout<<'3';
		cout<<'7'<<endl;
	}
}

