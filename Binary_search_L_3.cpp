#include<iostream>
using namespace std;
int binary_search(int a[],int n,int key)
{
  int low=0;
  int high=n-1;
  
  while (low<=high)
  {
    int mid=low+(high-low)/2;
    if(a[low]==key)
    {
      return mid;
    }
    else if(a[mid]<key)
    {
      low=mid+1;
    }
    else
      high=mid-1;
  }
  return -1;
}
int main()
{
  int n;
  cout<<"Enter the number of elements: ";
  cin>>n;
  int a[n];
  cout<<"Enter the elements:";
  for (int i = 0; i < n; i++)
  {
    cin>>a[i];
  }
  int key;
  cout<<"Enter the element to search : ";
  cin>>key;
  int position=binary_search(a,n,key);
  if (position != -1)
    {
        cout << "\nElement found at position "
             << position + 1 << endl;
    }
    else
        cout<<"Element not found";
  return 0;
}