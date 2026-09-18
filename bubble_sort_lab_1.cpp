#include<iostream>
using namespace std;
int main()
{
  int n;
  cout<<"Enter the number of element: ";
  cin>>n;
  int v[n];
  cout<<"Enter array element:";
  for (int i = 0; i < n; i++)
  {
    cin>>v[i];
  }
  for (int i = 0; i < n-1; i++)
  {
    cout<<"pass "<<i+1<<": "<<endl;
    
    for (int j = 0; j < n-1-i; j++)
    {
       cout<<"comparing "<<v[j]<<" and "<<v[j+1]<<endl;
       if(v[j]>v[j+1])
       {
         cout<<"swapping "<<v[j]<<" and "<<v[j+1]<<endl;
         swap(v[j],v[j+1]);
       }
    }
    cout<<"After pass ->"<<i+1<<": "<<endl;
    for (int j = 0; j < n; j++)
    {
      cout<<v[j]<<" ";
    }
    cout<<"\n";
  }
  cout<<"Bubble sort array: ";
  for (int i = 0; i < n; i++)
  {
    cout<<v[i]<<" ";
  }
  
}