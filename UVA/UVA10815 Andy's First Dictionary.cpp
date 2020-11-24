#include<iostream>
#include<set>
#include<string>
using namespace std;
int main()
{
	string str;
	set<string>s;
	while(cin>>str)
	{
		str+=' ';
		string tmp="";
		for(int i=0;i<(int)str.size();i++)
		{
			if(tmp!=""&&!isalpha(str[i]))
				s.insert(tmp),tmp="";
			if(isalpha(str[i]))
				tmp+=tolower(str[i]);
		}
	}
	for(string txt:s)
		cout<<txt<<endl;
}