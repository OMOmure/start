#include<iostream>
using namespace std;
int main()
{
    int count =5;
    cout<<"i++ group: ";
    for (int i = 0; i <= count; i++)
    {
       cout<<i<<" , ";
    }
    cout<<'\n';
    cout<<"++i group: ";
    for (int j = 0; j <= count; ++j)
    {
        cout<<j<<" , ";
    }
    cout<<endl;
    return 10;
}
