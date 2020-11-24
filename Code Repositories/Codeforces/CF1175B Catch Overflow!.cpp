#include<iostream>
using namespace std;
long long flag[100005]={1};
int main()
{
	int l,f=0,n;
	bool over=0,warn=0;
	long long ans=0;
	const long long inf=4294967295;
	char s[10];
	cin>>l;
	for(int i=0;i<l;i++)
	{
		cin>>s;
		if(s[0]=='f')
		{
			cin>>n;
			if(over) continue;
			f++;
			flag[f]=flag[f-1]*n;
			if(flag[f]>inf||flag[f]<flag[f-1])
				warn=true;
		}
		else if(!over&&s[0]=='a')
		{
			long long tmp=ans;
			ans+=flag[f];
			if(warn||ans>inf||ans<tmp)
				over=true;
		}
		else if(!over&&s[0]=='e')
		{
			f--;
			if(flag[f]<inf&&flag[f]>flag[f-1])
				warn=false;
			
		}
	}
	if(over) cout<<"OVERFLOW!!!";
	else cout<<ans;
}
