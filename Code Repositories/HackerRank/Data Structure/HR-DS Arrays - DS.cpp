#include<iostream>
using namespace std;
int main()
{
    int n,a[1005];
    cin>>n;
    for(int i=1;i<=n;i++) 
    	cin>>a[i];
    for(int i=n;i;i--) 
    	cout<<a[i]<<' ';
}