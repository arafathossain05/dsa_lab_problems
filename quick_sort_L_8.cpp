#include<iostream>
using namespace std;
int partitionarray(int a[],int low,int high)
{
  int pivot=a[low];
  int i=low+1;
  int j=high;

  while (i<=j)
  {
     while (i<=high && a[i]<=pivot)
     {
       i++;
     }
     while (j>=low && a[j]>pivot)
     {
       j--;
     }
     if(i<j)
     {
       swap(a[i],a[j]);
     }
  }
  swap(a[low],a[j]);
  return j;
}
void quicksort(int a[],int low,int high)
{
  if(low<high)
  {
    int p=partitionarray(a,low,high);
    quicksort(a,low,p-1);
    quicksort(a,p+1,high);
  }
}
int main()
{
  int n;
  cout<<"Enter the number of elements: ";
  cin>>n;
  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin>>a[i];
  }
  quicksort(a,0,n-1);
  cout<<"Sorted array: ";
  for (int i = 0; i < n; i++)
  {
    cout<<a[i]<<" ";
  }
  return 0;
}