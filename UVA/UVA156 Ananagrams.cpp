#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
string txt[1005],str;
map<string,int>mp;
string f(string str)
{
	int len=str.size();
	for(int i=0;i<len;i++) 
		str[i]=tolower(str[i]);
	sort(str.begin(),str.end());
	return str;
}
int main()
{
	int cnt=0;
	set<string>s;
	while(cin>>str&&str!="#")
		txt[cnt++]=str,mp[f(str)]++;
	for(int i=0;i<cnt;i++)
		if(mp[f(txt[i])]==1)
			s.insert(txt[i]);
	for(string tmp:s)
		cout<<tmp<<endl;
}