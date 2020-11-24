#include<iostream>
#include<cstring>
using namespace std;
char key[31]={"qwertyuiopasdfghjkl;zxcvbnm,./"};
int move(char x)
{
	if(x=='L')
		return 1; 
	else if(x=='R')
		return -1;
}
int main()
{
	char d,ch[105]={0};
	cin>>d>>ch;
	int len=strlen(ch),s=move(d);
	for(int i=0;i<len;i++)
		for(int j=0;j<30;j++)
			if(key[j]==ch[i])
				cout<<key[j+s];
}