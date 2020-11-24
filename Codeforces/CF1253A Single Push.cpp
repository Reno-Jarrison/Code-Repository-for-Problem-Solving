#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int a[maxn],b[maxn];
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		bool flag=false,ok=true;
		int k=10000;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) cin>>b[i],b[i]-=a[i];
		for(int i=1;i<=n;i++) if(b[i])
		{
			if(!flag) flag=true,k=b[i];
			else if(b[i]!=k||b[i]!=b[i-1]) ok=false;
		}
		if(k<0) ok=false;
		puts(ok?"YES":"NO");
	}
}