#include<iostream>
using namespace std;
int main()
{
	int ans1,ans2;
	cout<<"? ";
	for(int i=1;i<=100;i++)
		cout<<i<<" ";
	cout<<endl,cin>>ans1;
	cout<<"? ";
	for(int i=1;i<=100;i++)
		cout<<(i<<7)<<" ";
	cout<<endl,cin>>ans2;
	ans1&=0x3f80,ans2&=0x7f;
	cout<<"! "<<(ans1|ans2)<<flush;
}
