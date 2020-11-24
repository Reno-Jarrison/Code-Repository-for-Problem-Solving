#include<bits/stdc++.h>
using namespace std;
char pswd[26],dwsp[26];
int main()
{
	char s1[105],s2[105],s[105];
	cin>>s1>>s2>>s;	
	int len=strlen(s1),slen=strlen(s),fail=0;
	for(int i=0;i<len;i++)
	{
		if(!pswd[s1[i]-'A'])
			pswd[s1[i]-'A']=s2[i],dwsp[s2[i]-'A']=s1[i];
		else if(pswd[s1[i]-'A']!=s2[i]||dwsp[s2[i]-'A']!=s1[i])
		{
			fail=1;
			break;
		}	
	}
	for(int i=0;i<26;i++)
		if(!(pswd[i])||!(dwsp[i]))
			fail=1;
	if(fail)
		cout<<"Failed";
	else
		for(int i=0;i<slen;i++)
			cout<<pswd[s[i]-'A']; 
}