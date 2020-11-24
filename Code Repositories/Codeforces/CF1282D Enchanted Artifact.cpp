#include<bits/stdc++.h>
#define ll long long
using namespace std;
string sets(char c,int len)
{
	string ans="";
	while(len--) ans+=c;
	return ans;
}
int query(string s)
{
	cout<<s<<endl;
	int x; cin>>x;
	if(!x) exit(0);
	return x;
}
int main()
{
	int cnta=300-query(sets('a',300));
	int cntb=300-query(sets('b',300));
	int n=cnta+cntb,las=cntb;
	string s=sets('a',n);
	for(int i=0;i<n-1;i++)
	{
		s[i]='b';
		int ans=query(s);
		if(ans<las) las=ans,cntb--;
		else s[i]='a',cnta--;
	}
	if(cntb) s[n-1]='b';
	query(s);
}