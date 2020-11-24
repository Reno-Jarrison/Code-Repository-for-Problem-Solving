#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
char s[maxn];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(s,0,sizeof(s));
		cin>>(s+1);
		int len=strlen(s+1);
		vector<int>v;
		for(int i=1;i<=len;i++)
		{
			if(s[i]=='o'&&s[i+1]=='n'&&s[i+2]=='e')
				v.push_back(i+1),i+=2;
			if(s[i]=='t'&&s[i+1]=='w'&&s[i+2]=='o')
			{
				if(s[i+3]=='n'&&s[i+4]=='e')
					v.push_back(i+2),i+=4;
				else v.push_back(i+1),i+=2;
			}
		}
		cout<<v.size()<<endl;
		for(int i:v) cout<<i<<" ";
		puts("");
	}
}