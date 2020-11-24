#include<iostream>
#include<string>
#include<map>
using namespace std;
string s1,s2,src,dst;
int main()
{
	int t,n,ks=0;
	cin>>t;
	while(t--)
	{
		cin>>n>>s1>>s2>>dst;
		map<string,int>vis;
		src.resize(n*2);
		int ans=-1,step=0;
		while(++step)
		{
			for(int j=0;j<n;j++)
				src[j*2+1]=s1[j],src[j*2]=s2[j];
			if(src==dst) { ans=step; break; }
			if(vis[src]) break;
			vis[src]=1;
			for(int j=0;j<n;j++)
				s1[j]=src[j],s2[j]=src[j+n];
		}
		cout<<++ks<<" "<<ans<<endl;
	}
}