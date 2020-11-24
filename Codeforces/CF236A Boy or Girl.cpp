#include<iostream>
#include<cstring>
using namespace std;
char name[105];
int al[26];
int main()
{
	int count=0,len;
	cin>>name;
	len=strlen(name);
	for(int i=0;i<len;i++)
		al[name[i]-'a']++;
	for(int i=0;i<26;i++)
		if(al[i])
			count++;	
	if(count%2)
		cout<<"IGNORE HIM!"<<endl;		
	else
		cout<<"CHAT WITH HER!"<<endl;		
}