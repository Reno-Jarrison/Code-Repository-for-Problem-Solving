#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	if(n<4) cout<<"NO";
	else if(n%2)
	{
		cout<<"YES"<<endl;
		cout<<"4 * 5 = 20"<<endl;
		cout<<"20 + 3 = 23"<<endl;
		cout<<"23 + 2 = 25"<<endl;
		cout<<"25 - 1 = 24"<<endl;
		for(int i=n;i>5;i-=2)
			cout<<i<<" - "<<i-1<<" = 1"<<endl<<"24 * 1 = 24"<<endl;
	}
	else
	{
		cout<<"YES"<<endl;
		cout<<"4 * 3 = 12"<<endl;
		cout<<"12 * 2 = 24"<<endl;
		cout<<"24 * 1 = 24"<<endl;
		for(int i=n;i>4;i-=2)
			cout<<i<<" - "<<i-1<<" = 1"<<endl<<"24 * 1 = 24"<<endl;
	}
}