#include<iostream>
#include<cstring>
#include<cstdlib>
#include<stack>
using namespace std;
int main()
{
	int n;
	cin>>n;
	getchar();
	while(n--)
	{
		string temp;
		stack<int>s;
		getline(cin,temp);
		int len=temp.size();
		for(int i=0;i<len;i++)
		{
			if(!s.empty()&&temp[i]>s.top()&&temp[i]<s.top()+3)
				s.pop();
			else
				s.push(temp[i]);
		}
		if(!s.empty())
			cout<<"No"<<endl;
		else
			cout<<"Yes"<<endl;
	}
	return 0;
}