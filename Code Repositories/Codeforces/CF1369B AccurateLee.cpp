#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
char s[maxn];
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n>>s;
		int l=n,r=-1;
		for(int i=0;i<n;i++)
			s[i]=='1'?l=min(l,i):r=max(r,i);
		if(l>r) cout<<s;
		else
		{
			for(int i=0;i<=l;i++) cout<<0;
			for(int i=r+1;i<n;i++) cout<<1;
		}
		puts("");
	}
}