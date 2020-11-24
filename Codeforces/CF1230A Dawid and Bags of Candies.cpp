#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a1,a2,a3,a4,sum;
	cin>>a1>>a2>>a3>>a4;
	sum=a1+a2+a3+a4;
	if(a1+a2==a3+a4||a1+a3==a2+a4||a1+a4==a2+a3||a1==sum-a1||a2==sum-a2||a3==sum-a3||a4==sum-a4)
		cout<<"YES";
	else cout<<"NO";
}

