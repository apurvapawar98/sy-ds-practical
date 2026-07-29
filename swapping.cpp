#include<iostream>
using namespace std;
 int main()
 {
 	int a,b,temp;
 	int*p1,*p2;
 	
 	cout<<" enter two numbers:";
 	cin>>a>>b;
 	
 	p1= &a;
 	p2 = &b;
 	
 	temp = *p1;
 	*p1 = *p2;
 	*p2 = temp;
 	
 	cout<<"after swapping:"<<endl;
 	cout<<"a="<<a<<endl;
 	cout<<"b="<<b<<endl;
 	
 	return 0;
 	
 	
 }
