#include<iostream>
#include<string>
using namespace std;
string pre,mid;
void find(string pre,string mid)
{
	if(!pre.size())
		return;
	char r=pre[0]; 
	int root=mid.find(r);
	find(pre.substr(1,root),mid.substr(0,root)); 
	find(pre.substr(root+1),mid.substr(root+1)); 
	cout<<r;
}
int main()
{
	while(cin>>pre>>mid)
		find(pre,mid),cout<<endl;
} 
