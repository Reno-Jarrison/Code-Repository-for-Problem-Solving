#include<iostream>
#include<string>
using namespace std;
int main()
{
	int t;
	string s;
	cin>>t;
	while(t--)
	{
		bool flag=true;
		cin>>s;
		for(int i=0;i<(int)s.size();i++)
			if(s[i]=='z') { flag?s[i]='b':0; break; }
			else if(s[i]!='y') flag=false;
		cout<<s<<endl;
	}
} 