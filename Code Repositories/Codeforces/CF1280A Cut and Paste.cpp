#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e6+5;
const ll mod=1e9+7;
char s[maxn];
int main()
{
	int t,x;
	cin>>t;
	while(t--)
	{
		cin>>x>>(s+1);
		int pt=strlen(s+1),flag=true;
		for(int i=1;i<=x;i++)
		{
			int len=(pt-i+mod)%mod,cnt=s[i]-'1',tmp=pt;
			for(int j=1;j<=cnt&&flag;j++)
				for(int k=1;k<=len;k++)
				{
					s[++tmp]=s[i+k];
					if(tmp>x) { flag=false; break; }
				}
			pt=(1LL*len*cnt+pt)%mod;
		}
		cout<<pt<<endl;
	}
}