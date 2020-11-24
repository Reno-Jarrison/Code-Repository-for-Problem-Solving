#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+5;
int mnv[maxn];
int main()
{
	int t; 
	cin>>t;
	while(t--)
	{
		string s,c; 
		cin>>s>>c;
		int len=s.size();
		mnv[len-1]=len-1;
		for(int i=len-2;i>=0;i--)
		{
			if(s[i]<s[mnv[i+1]]) mnv[i]=i;
			else mnv[i]=mnv[i+1];
		}
		for(int i=0;i<len-1;i++)
			if(s[i]>s[mnv[i+1]])
			{	swap(s[i],s[mnv[i+1]]); break; }
		if(s<c) cout<<s<<endl;
		else puts("---");
	}
}