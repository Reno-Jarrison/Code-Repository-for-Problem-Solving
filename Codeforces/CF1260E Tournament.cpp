#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1<<20;
int p[maxn];
int main()
{
	int n; ll ans=0;
	cin>>n;
	priority_queue<int,vector<int>,greater<int> >q;
	for(int i=1;i<=n;i++) cin>>p[i];
	for(int i=n;i&&p[i]!=-1;i--)
	{
		q.push(p[i]);
		if(!(i&(i-1))) ans+=q.top(),q.pop();
	}
	cout<<ans;
}