#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
char s[maxn];
int main()
{
	int t,k;
	cin>>t;
	while(t--)
	{
		cin>>k>>s;
		int ans=0,tmp=0,ok=0;
		for(int i=0;i<k;i++)
			if(s[i]=='P') tmp++;
			else
			{
				if(ok) ans=max(ans,tmp);
				tmp=0,ok=1;
			}
		if(ok) ans=max(ans,tmp);
		cout<<ans<<endl;
	}
}