#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int cnt[maxn];
int main()
{
	int k,n,x;
	cin>>k;
	while(k--)
	{
		memset(cnt,0,sizeof(cnt));
		cin>>n;
		for(int i=1;i<=n;i++) 
		{
			cin>>x;
			for(int j=1;j<=x;j++) cnt[j]++; 
 		}
		for(int i=n;i;i--)
			if(cnt[i]>=i)
			{	cout<<i<<endl; break; }		
	} 
}

