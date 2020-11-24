#include<iostream>
using namespace std;
int main()
{
	int n,x=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		char a[4]={0};
		cin>>a;
		if(a[0]=='+'||a[2]=='+')
			x++;
		if(a[0]=='-'||a[2]=='-')
			x--;
	}
	cout<<x<<endl;
}