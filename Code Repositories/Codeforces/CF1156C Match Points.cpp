#include<iostream>
#include<algorithm>
using namespace std;
int p[200005];
int main()
{
	int n,z,cnt=0;
	cin>>n>>z;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	sort(p+1,p+n+1);
	int mid=n>>1,left=mid+1,right=n;
	for(int i=1;i<=mid;i++) 
	{
		int *index=lower_bound(p+left,p+right,p[i]+z);
		left=index-p;
		if(left>n||p[i]+z>p[left]) break;
		left++;
		cnt++;
	}
	cout<<cnt;
}