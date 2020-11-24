#include<iostream>
using namespace std;
const int maxn=1e6+5;
char a[maxn],b[maxn];
int main()
{
	int n,ans=0;
	cin>>n>>(a+1)>>(b+1);
	for(int i=1;i<n;i++)
		if(a[i]!=b[i]&&a[i+1]!=b[i+1]&&a[i]==b[i+1]&&a[i+1]==b[i])
			swap(a[i],a[i+1]),ans++,i++;
	for(int i=1;i<=n;i++)
		if(a[i]!=b[i]) ans++;
	cout<<ans;
}