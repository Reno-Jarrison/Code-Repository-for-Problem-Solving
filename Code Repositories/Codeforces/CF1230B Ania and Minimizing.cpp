#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	string s;
	cin>>n>>k>>s;
	if(k)
	{
		if(n==1) s="0",k=0;
		else if(s[0]!='1') s[0]='1',k--;
		for(int i=1;i<n&&k;i++)
			if(s[i]!='0') s[i]='0',k--;
 	}
	cout<<s; 
}

