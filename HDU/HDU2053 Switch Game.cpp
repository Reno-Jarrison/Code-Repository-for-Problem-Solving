#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		if((int)sqrt(n)*(int)sqrt(n)==n)
			cout<<"1"<<endl;
		else
			cout<<"0"<<endl;
	}
 } 