#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=3e5+5;
int a[maxn];
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++) cin>>a[i];
		int idx=n,cnt=0,ok=1;
		for(int i=0;i<n;i++)
			if(a[i]<i) { idx=i-1; break; }
		for(int i=n-1;i>=idx;i--)
			if(a[i]<cnt++) ok=0;
		puts(ok?"Yes":"No");
	}
}