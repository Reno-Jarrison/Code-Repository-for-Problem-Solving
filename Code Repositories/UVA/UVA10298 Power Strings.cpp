#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int nxt[1000005];
int main()
{
	ios::sync_with_stdio(false);
	string s;
	while(cin>>s)
	{
		int len=s.size();
		if(len==1&&s[0]=='.')
			break;
		int i=1,j=-1,counter;
		nxt[0]=-1;
		while(s[i])
		{
			while(j!=-1&&s[i]!=s[j+1])
				j=nxt[j];
			if(s[i]==s[j+1])
				j++;
			nxt[i++]=j;
		}
		counter=len-nxt[s.size()-1]-1;
		if(len%counter)
			cout<<1<<endl;
		else
			cout<<fixed<<len/counter<<endl;
	}
}