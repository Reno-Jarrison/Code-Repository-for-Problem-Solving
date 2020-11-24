#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
string s1,s2;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int pt,ans;
		cin>>s1>>s2;
		reverse(s1.begin(),s1.end()); 
		reverse(s2.begin(),s2.end()); 
		for(int i=0;i<s2.length();i++)
			if(s2[i]=='1')
			{	pt=i; break; }
		for(int i=pt;i<s1.length();i++)
			if(s1[i]=='1')
			{	ans=i; break; }
		cout<<ans-pt<<endl;
	}
}

