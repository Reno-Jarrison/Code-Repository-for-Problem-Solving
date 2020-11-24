#include<iostream>
#include<cstring>
using namespace std;
char ch[1005],del[1005];
int main()
{
	int len1,len2;
	while(cin>>ch&&ch[0]!='#')
	{
		int count=0;
		cin>>del;
		len1=strlen(ch);
		len2=strlen(del);
		for(int i=0;i<=len1-len2;i++)
		{
			int flag=1;
			if(ch[i]==del[0])
			{
				flag=0;
				for(int j=1;j<len2;j++)
					if(ch[i+j]!=del[j])
						flag++;
				if(!flag)
					count++,i+=len2-1;
			}
		}
		memset(ch,0,sizeof(ch));
		memset(del,0,sizeof(del));
		cout<<count<<endl;
	}
 } 