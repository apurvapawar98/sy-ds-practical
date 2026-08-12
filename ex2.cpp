#include <iostream>
#include <string>
using namespace std;

struct Employee
{
    int empid;
    string empname;
    float salary;
    Employee *next;
};

Employee *head = NULL;


void insert()
{
    Employee *newNode = new Employee;

    cout << "Enter Employee Id: ";
    cin >> newNode->empid;

    cout << "Enter Employee Name: ";
    cin >> newNode->empname;

    cout << "Enter Employee Salary: ";
    cin >> newNode->salary;

    newNode->next = head;
    head = newNode;

    cout << "Employee record inserted successfully.\n";
}


void deleteNode(int id)
{
    if (head == NULL)
    {
        cout << "List is Empty.\n";
        return;
    }

    Employee *temp = head;
    Employee *prev = NULL;

    
    if (head->empid == id)
    {
        head = head->next;
        delete temp;
        cout << "Employee record deleted successfully.\n";
        return;
    }

    while (temp != NULL && temp->empid != id)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Employee record not found.\n";
        return;
    }

    prev->next = temp->next;
    delete temp;

    cout << "Employee record deleted successfully.\n";
}


void search(int id)
{
    Employee *temp = head;

    while (temp != NULL)
    {
        if (temp->empid == id)
        {
            cout << "\nEmployee Found\n";
            cout << "Employee Id   : " << temp->empid << endl;
            cout << "Employee Name : " << temp->empname << endl;
            cout << "Salary        : " << temp->salary << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Employee record not found.\n";
}


void display()
{
    if (head == NULL)
    {
        cout << "List is Empty.\n";
        return;
    }

    Employee *temp = head;

    cout << "\nEmployee Records\n";
    cout << "--------------------------\n";

    while (temp != NULL)
    {
        cout << "Id     : " << temp->empid << endl;
        cout << "Name   : " << temp->empname << endl;
        cout << "Salary : " << temp->salary << endl;
        cout << "--------------------------\n";

        temp = temp->next;
    }
}

int main()
{
    int choice, id;

    do
    {
        cout << "\n------ Employee Record Management ------\n";
        cout << "1. Insert Employee\n";
        cout << "2. Delete Employee\n";
        cout << "3. Display Employees\n";
        cout << "4. Search Employee\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            insert();
            break;

        case 2:
            cout << "Enter Employee Id to Delete: ";
            cin >> id;
            deleteNode(id);
            break;

        case 3:
            display();
            break;

        case 4:
            cout << "Enter Employee Id to Search: ";
            cin >> id;
            search(id);
            break;

        case 5:
            cout << "Program Ended.\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}
