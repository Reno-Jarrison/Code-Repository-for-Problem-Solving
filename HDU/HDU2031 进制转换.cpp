#include<iostream>
using namespace std;
char radix[]={"0123456789ABCDEF"},rev[1000000];
int main()
{
	int n,r;
	while(cin>>n>>r)
	{
		int flag=0,k=0;
		if(n<0)
			flag=1,n=-n,cout<<"-";
		if(!n)
			cout<<0;
		else
			while(n)
				rev[k++]=radix[n%r],n/=r;
		for(int i=0;i<k;i++)
			cout<<rev[k-i-1];
		cout<<endl;
	}
}