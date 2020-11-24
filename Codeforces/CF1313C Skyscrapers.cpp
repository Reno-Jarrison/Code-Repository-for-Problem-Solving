#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+5,inf=0x7fffffff;
ll sum1[maxn],sum2[maxn],mxv;
int m[maxn],ans[maxn];
int main()
{
	int n,id;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>m[i];
	stack<int>s1,s2;
	s1.push(0),s2.push(n+1);
	for(int i=1;i<=n;i++)
	{
		while(!s1.empty()&&m[i]<m[s1.top()]) s1.pop();
		sum1[i]=sum1[s1.top()]+1LL*(i-s1.top())*m[i];
		s1.push(i);
	}
	for(int i=n;i;i--)
	{
		while(!s2.empty()&&m[i]<m[s2.top()]) s2.pop();
		sum2[i]=sum2[s2.top()]+1LL*(s2.top()-i)*m[i];
		s2.push(i);
	}
	for(int i=1;i<=n;i++)
		if(sum1[i]+sum2[i]-m[i]>mxv)
			mxv=sum1[i]+sum2[i]-m[i],id=i;
	ans[id]=m[id];
	for(int i=id+1;i<=n;i++) ans[i]=min(m[i],ans[i-1]);
	for(int i=id-1;i;i--) ans[i]=min(m[i],ans[i+1]);
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
}