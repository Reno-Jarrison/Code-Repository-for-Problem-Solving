#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t; cin>>t;
	while(t--)
	{
		string s; cin>>s;
		char ch=*--s.end();
		if(ch=='o') puts("FILIPINO");
		if(ch=='u') puts("JAPANESE");
		if(ch=='a') puts("KOREAN");
	}
}