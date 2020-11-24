#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=3e5+5;
int main()
{
	int n;
	cin>>n;
	ll x,cnt[2]={0};
	for(int i=0;i<n;i++)
	{
		cin>>x,cnt[i&1]+=x&1;
		x>>=1,cnt[0]+=x,cnt[1]+=x;
	}
	cout<<min(cnt[0],cnt[1]);
}