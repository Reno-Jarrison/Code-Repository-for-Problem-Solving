#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
char s[maxn];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>(s+1);
		int len=strlen(s+1),cnt=0,l=len,r=1;
		for(int i=1;i<=len;i++)
			if(s[i]=='1') l=min(l,i),r=max(r,i),cnt++;
		if(!cnt) cout<<0<<endl;
		else cout<<len-cnt-(l-1)-(len-r)<<endl;
	}
}