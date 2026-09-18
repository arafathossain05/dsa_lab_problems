#include<iostream>
using namespace std;
int count=0;
void tower_of_hanoi(int N,char source,char auxilary,char destination,int &step)
{
  if(N==1)
  {
    cout<<"step->"<<step++<<":"<<"disk move 1 from "<<source<<" to "<<destination<<endl;
    count++;
    return ;
  }
  tower_of_hanoi(N-1,source,destination,auxilary,step);  
  cout<<"step->"<<step++<<":"<<"Disk move "<<N<<" from "<<source<<" to "<<destination<<endl;
  count++;
  tower_of_hanoi(N-1,auxilary,source,destination,step);
}
int main()
{
  int N;
  cout<<"Enter the number of disk : ";
  cin>>N;
  int step=1;
  tower_of_hanoi(N,'A','B','C',step);
  cout<<"Total step is required : "<<count<<endl;
  return 0;
}