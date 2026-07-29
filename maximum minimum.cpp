#include<iostream>
using namespace std;
 
 int main()
 {
 	int a[10]={10,20,30,40,50};
 	int *p =a;
 	int max =*p;
 	for (int i=1; i<5;i++)
 	{
 		if(*(p+1)>max)
 		max =*(p+1);
 		
	 }
	 cout<<"maximum ="<<max;
 }
 

