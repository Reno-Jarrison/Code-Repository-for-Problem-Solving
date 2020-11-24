#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
int a[maxn];
int main()
{
	int n,l,r;
	cin>>n,l=1,r=n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[l]==i) l++;
		else if(a[r]==i) r--;
		else { cout<<"NO"; return 0; }
	}
	cout<<"YES";
	return 0;
}

