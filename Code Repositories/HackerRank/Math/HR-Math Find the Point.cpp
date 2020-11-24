#include<iostream>
using namespace std;
int main()
{
    int n,x1,x2,y1,y2;
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        cin>>x1>>y1>>x2>>y2;
        cout<<x2*2-x1<<" "<<y2*2-y1<<endl;
    }
}