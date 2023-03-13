#include <iostream>
#include <string.h>
using namespace std;

int n; /*Global because many functions use it and the size is variable during deletion*/
int valueId;

struct employee
{
    char name[20];
    int id;
    char designation[20];
    int experience;
    int age;
    int salary;
    char department[20];
};

void read(struct employee e[], int beg, int size)
{
    for (int i = beg; i <= size; i++)
    {
        cout << "\nEnter the details of the " << i << " Employee in the following order:" << endl
             << "1:Name" << endl
             << "2:Id" << endl
             << "3:Designation" << endl
             << "4:Experience" << endl
             << "5:Age" << endl
             << "6.Department" << endl
             << "7.Salary\n"
             << endl
             << endl;
        cin >> e[i].name >> e[i].id >> e[i].designation >> e[i].experience >> e[i].age >> e[i].department >> e[i].salary;
    }
}

void printer(struct employee e[], int index[], int k)
{
    for (int i = 1; i < k; i++)
    {
        cout << "\nName: " << e[index[i]].name << endl
             << "Id: " << e[index[i]].id << endl
             << "Designation: " << e[index[i]].designation << endl
             << "Experience: " << e[index[i]].experience << endl
             << "Age: " << e[index[i]].age << endl
             << "Department: " << e[index[i]].department << endl
             << "Salary: " << e[index[i]].salary << endl;
    }
    cout << "\n";
}

void searchDepartment(struct employee e[], int size, char department[])
{
    int flag = 0, index[10000], k = 1;
    for (int i = 1; i <= size; i++)
    {

        if (strcmp(e[i].department, department) == 0)
        {
            flag = 1;
            index[k] = i;
            k++;
        }
    }
    if (flag == 1)
    {
        cout << "\nThe details of the respective employee is as follows:" << endl;
        printer(e, index, k);
    }
    else
        cout << "\nNot Found" << endl;
}

void searchName(struct employee e[], int size, char name[])
{
    int flag = 0, index[10000], k = 1;
    for (int i = 1; i <= size; i++)
    {

        if (strcmp(e[i].name, name) == 0)
        {
            flag = 1;
            index[k] = i;
            k++;
        }
    }
    if (flag == 1)
    {
        cout << "\nThe details of the respective employee is as follows:" << endl;
        printer(e, index, k);
    }
    else
        cout << "\nNot Found" << endl;
}

void searchDesignation(struct employee e[], int size, char designation[])
{
    int flag = 0, index[10000], k = 1;
    for (int i = 1; i <= size; i++)
    {

        if (strcmp(e[i].designation, designation) == 0)
        {
            flag = 1;
            index[k] = i;
            k++;
        }
    }
    if (flag == 1)
    {
        cout << "\nThe details of the respective employee is as follows:" << endl;
        printer(e, index, k);
    }
    else
        cout << "\nNot Found" << endl;
}

void searchSalary(struct employee e[], int size, int salary)
{
    int flag = 0, index[10000], k = 1;
    for (int i = 1; i <= size; i++)
    {

        if (e[i].salary == salary)
        {
            flag = 1;
            index[k] = i;
            k++;
        }
    }
    if (flag == 1)
    {
        cout << "\nThe details of the respective employee is as follows:" << endl;
        printer(e, index, k);
    }
    else
        cout << "\nNot Found" << endl;
}

void searchId(struct employee e[], int size, int id)
{
    int flag = 0, index[10000], k = 1;
    for (int i = 1; i <= size; i++)
    {

        if (e[i].id == id)
        {
            flag = 1;
            index[k] = i;
            k++;
        }
    }
    if (flag == 1)
    {
        cout << "\nThe details of the respective employee is as follows:" << endl;
        valueId=k;
        printer(e, index, k);
    }
    else
        cout << "\nNot Found" << endl;
}

void searchExperience(struct employee e[], int size, int experience)
{
    int flag = 0, index[10000], k = 1;
    for (int i = 1; i <= size; i++)
    {

        if (e[i].experience == experience)
        {
            flag = 1;
            index[k] = i;
            k++;
        }
    }
    if (flag == 1)
    {
        cout << "\nThe details of the respective employee is as follows:" << endl;
        printer(e, index, k);
    }
    else
        cout << "\nNot Found" << endl;
}

void searchAge(struct employee e[], int size, int age)
{
    int flag = 0, index[10000], k = 1;
    for (int i = 1; i <= size; i++)
    {

        if (e[i].age == age)
        {
            flag = 1;
            index[k] = i;
            k++;
        }
    }
    if (flag == 1)
    {
        cout << "\nThe details of the respective employee is as follows:" << endl;
        printer(e, index, k);
    }
    else
        cout << "\nNot Found" << endl;
}

void print(struct employee e[], int size)
{
    if (size == 0)
        cout << "The database is empty" << endl;
    else
    {
        for (int i = 1; i <= size; i++)
        {
            cout << "\nThe details of the " << i << " Employee are" << endl;
            cout << "Name: " << e[i].name << endl
                 << "Id: " << e[i].id << endl
                 << "Designation: " << e[i].designation << endl
                 << "Experience: " << e[i].experience << endl
                 << "Age: " << e[i].age << endl
                 << "Department: " << e[i].department << endl
                 << "Salary: " << e[i].salary << endl;
        }
    }
}

void deleteEmployee(struct employee e[], int size, int id)
{
    searchId(e,size,id);
    int index=valueId;
    for (int i = index; i <= size; i++)
    {
        strcpy(e[index].name, e[index + 1].name);
        e[index].id = e[index + 1].id;
        strcpy(e[index].designation, e[index + 1].designation);
        e[index].experience = e[index + 1].experience;
        e[index].age = e[index + 1].age;
        strcpy(e[index].department, e[index + 1].department);
        e[index].salary = e[index + 1].salary;
        // size--;
        // n = size;
        cout << "\nRequired entry has successfully been deleted, you can check so by printing the details\n"
             << endl;
    }
    size--;
    n = size;
}

int main()
{
    cout << "\nSome General Instructions/Restrictions to use this Employee Management System," << endl
         << "1)The Program is well instructed so do read the screen before clicking on any option(s).\n2)The Program is case sensitive.\n3)You can search the employee details based on multiple parameters.\n4)Enter only the first name of the Employee.\n5)The parameter 'designation' is of the type character, eg:Teacher,Assistant,developer,director etc..\n6)You can delete the data with only the employee id, this was done on purpose as deletion is a very sensitive case so deleting it with primary key made sense i.e; the Employee id in our case which uniquely identifies each employee.\n\nPS:However with a very minimal tweak the deletion can also be done based on any parameter.\n   Do Inform me if there are any improvements that can be made in this program.\n   Contact me at pranav_b210460cs@nitc.ac.in\n";
    char ch;
    int oldsize;
    cout << "\nEnter the number of Employees: ";
    cin >> n;
    struct employee e[10000];
    read(e, 1, n);

    do
    {
        cout << "\nEnter your choice of operation: " << endl
             << "i:To insert new data" << endl
             << "p:To print the data" << endl
             << "s:To search" << endl
             << "d:To Delete" << endl
             << "t:To Terminate\n\n";
        cin >> ch;
        switch (ch)
        {
            char ch1;
        case 's':
            cout << "\nEnter the parameter based on which you have to search: " << endl
                 << "1:Name" << endl
                 << "2:ID" << endl
                 << "3:Designation" << endl
                 << "4:Experience" << endl
                 << "5:Age" << endl
                 << "6:Department" << endl
                 << "7:Salary" << endl;
            cin >> ch1;
            switch (ch1)
            {
                char name[20];
                int id;
            case '1':
                cout << "Enter the Employee Name: ";
                cin >> name;
                searchName(e, n, name);
                break;
            case '2':
                cout << "Enter the Employee Id: ";
                cin >> id;
                searchId(e, n, id);
                break;
            case '3':
                cout << "Enter the Employee's Designation: ";
                char designation[20];
                cin >> designation;
                searchDesignation(e, n, designation);
                break;
            case '4':
                cout << "Enter the Employee's Experience: ";
                int experience;
                cin >> experience;
                searchExperience(e, n, experience);
                break;
            case '5':
                cout << "Enter the Employee's Age: ";
                int age;
                cin >> age;
                searchAge(e, n, age);
                break;
            case '6':
                cout << "Enter the Employee's Department: ";
                char department[20];
                cin >> department;
                searchDepartment(e, n, department);
                break;
            case '7':
                cout << "Enter the Employee's Salary: ";
                int salary;
                cin >> salary;
                searchSalary(e, n, salary);
                break;
            }
            break;
        case 'i':
            oldsize = n;
            cout << "Enter the number of new entries you want to insert: ";
            int p;
            cin >> p;
            n = n + p;
            read(e, oldsize + 1, n);
            break;
        case 'd':
            if (n == 0)
                cout << "The database is already empty, you don't have anymore data to be deleted" << endl;
            else if (n == 1)
                cout << "The database has just one data left, the database cannot be empty\n";
            else
            {
                cout << "Enter the Employee id to be deleted: ";
                int id;
                cin >> id;
                deleteEmployee(e, n, id);
            }
            break;
        case 'p':
            print(e, n);
            break;
        case 't':
            return 0;
        default:
            cout << "The entered choice is INVALID !!" << endl;
            break;
        }
    } while (ch != 't');

    return 0;
}
