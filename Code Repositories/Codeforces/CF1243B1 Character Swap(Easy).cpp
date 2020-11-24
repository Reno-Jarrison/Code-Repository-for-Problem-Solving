#include<bits/stdc++.h>
using namespace std;
int main()
{
	int k,n;
	string s,t;
	cin>>k;
	while(k--)
	{
		cin>>n>>s>>t;
		int id1=-1,id2=-1,ok=1;
		for(int i=0;i<n;i++)
			if(s[i]!=t[i])
			{
				if(id1==-1) id1=i;
				else if(id2==-1) id2=i;
				else ok=0;
			}
		if(id1!=-1&&id2==-1) ok=0;
		if(ok&&s[id1]==s[id2]&&t[id1]==t[id2]) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}

