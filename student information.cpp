#include<iostream>
using namespace std;

 struct Student 

{
	 int studentrollNo;
	char studentName[50];
	float studentMarks;
	 
};

void addStudent(Student s[100], int n)
{

	for(int i=0;i<n;i++)
	
	{
		cout<<"\n enter details  of student"<<i+1<<endl;
		
		cout<<"student roll no :";
		cin>>s[i].studentrollNo;

		cout<<"student name :";
		cin>>s[i].studentName;
		
		cout<<"student marks:";
		cin>>s[i].studentMarks;
	}

}
void displayStudent(Student *s,int n)
{
cout<<"\nstudent record";	
	 for(int i=0;i<n;i++)
	 {
	 	cout<<"\ student:"<<i+1<<endl;
	 	cout<<"student id :"<<(s+i)->studentrollNo <<endl;
	
	 	cout<<"studentname :"<<(s+i)->studentName<<endl; 
	 	cout<<"student marks :"<<(s+i)->studentMarks<<endl;
	 }
}
 int main()
 {
 	int n;
 	cout<<"enter no of student:";
 	cin>>n;
 	Student s[n];
 	addStudent(s,n);
 	displayStudent(s,n);
 	
 }
