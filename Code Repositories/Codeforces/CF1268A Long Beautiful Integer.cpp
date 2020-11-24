#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
char s[maxn];
int ans[maxn];
int main()
{
	int n,k;
	cin>>n>>k>>s;
	for(int i=0;i<k;i++) ans[i]=s[i]-'0';
	for(int i=k;i<n;i++) 
	{
		int x=s[i]-'0';
		if(ans[i%k]==x) continue;
		if(ans[i%k]<x)
		{
			int pt=k-1;
			while(pt>=0)
			{
				ans[pt]=(ans[pt]+1)%10;
				if(ans[pt--]) break;
			}
		}
		break;
	}
	cout<<n<<endl;
	for(int i=0;i<n;i++)
		cout<<ans[i%k];
}