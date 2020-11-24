#include<iostream>
#include<string>
#include<cstring>
using namespace std;
string a,b;
int nxt[100005];
void getnext(string b)
{
	memset(nxt,0,sizeof(nxt));
	nxt[0]=-1;
	int i=0,j=-1;
	while(b[i])
		if(j==-1||b[i]==b[j]) nxt[++i]=++j;
		else j=nxt[j];
}
int main()
{
	while(cin>>a>>b)
	{
		a+=a;
		getnext(b);
		int flag=0,i=0,j=0,lenb=b.size();
		while(a[i])
		{
			if(j==-1||a[i]==b[j]) i++,j++;
			else j=nxt[j];
			if(j==lenb)
				{ flag=1; break; }
		}
		if(flag) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
} 