#include<iostream>
#include<cstring>
using namespace std;
#define Maxn 100005
char eng[Maxn][25],tra[Maxn][85],com[85],ch;
int main()
{
	int k=0,n;
	while(cin>>eng[k]&&eng[k][0]!='@')
	{
		int j=0;
		getchar();
		while((tra[k][j++]=getchar())!='\n');
		tra[k++][j-1]='\0';
	}	
	cin>>n;
	getchar();
	for(int i=0;i<n;i++)
	{
		int j=0,flag=0;
		while((com[j++]=getchar())!='\n');
		com[j-1]='\0';
		for(int m=0;m<k;m++)
		{
		if(com[0]=='[')
		{
			if(strcmp(com,eng[m])==0)
			{
				cout<<tra[m]<<endl;
				flag=1;
				break;
			}
		}
		else
			if(strcmp(com,tra[m])==0)
			{
				int t=0;
				while(eng[m][++t]!=']')
					cout<<eng[m][t];
				cout<<endl;
				flag=1;
				break;
			}
		}
		if(!flag)
			cout<<"what?"<<endl;
		memset(com,0,sizeof(com));
	}
}