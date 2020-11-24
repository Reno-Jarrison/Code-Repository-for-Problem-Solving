#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n; cin>>n;
	for(long long i=2;i*i<n;i++)
		if(!(n%i)) { printf("%d",n/i); return 0; } 
}