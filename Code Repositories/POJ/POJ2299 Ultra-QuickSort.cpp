#include<iostream>
#define Maxn 500005
using namespace std;
int num[Maxn],temp[Maxn];
long long counter;
void merge_sort(int l,int m,int r)
{
	int i=l,j=m+1,k=l;
	while(i<=m&&j<=r)
	{
		if(num[i]<=num[j])
			temp[k++]=num[i++];
		else
			temp[k++]=num[j++],counter+=m-i+1;
	}
	while(j<=r)
		temp[k++]=num[j++];
	while(i<=m)
		temp[k++]=num[i++];
	for(i=l;i<=r;i++)
		num[i]=temp[i];
}
void merge(int left,int right)
{
	if(left<right)
	{
		int mid=(left+right)/2;
		merge(left,mid);
		merge(mid+1,right);
		merge_sort(left,mid,right);
	}
}
int main()
{
	int n;
	while(cin>>n&&n)
	{
		counter=0;
		for(int i=0;i<n;i++)
			cin>>num[i];
		merge(0,n-1);
		cout<<counter<<endl;
	}
}