#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Student
{
    char studentName[50];
    char studentId[15];
    char studentDept[10];
    char studentAddress[100];
    char studentContactNum[15];
    float studentCGPA;
};
void createAccount();
void displayInfo();
void updateInfo();
void deleteInfo();
void searchInfo();
int main()
{
    char option;
    while (option != '0')
    {
        system("cls");
        cout << "\t\t====== Student Management Database System ======\n";
        cout << "\n\t\t\t1. Create Student Account";
        cout << "\n\t\t\t2. Display All Students Information";
        cout << "\n\t\t\t3. Update Student Information";
        cout << "\n\t\t\t4. Delete Student Information";
        cout << "\n\t\t\t5. Search Student Information";
        cout << "\n\t\t\t5. Student Result";
        cout << "\n\t\t\t0. Exit";
        cout << "\n\n\n\t\t\tEnter Your Option: ";
        cin >> option;
        switch (option)
        {
        case '1':
            createAccount();
            break;
        case '2':
            displayInfo();
            break;
        case '3':
            updateInfo();
            break;
        case '4':
            deleteInfo();
            break;
        case '5':
            searchInfo();
            break;
        case '0':
            cout << "\n\t\t\t====== Thank You ======";
            break;
        default:
            cout << "\n\t\t\tInvalid Option, Please Enter Right Option !\n";
        }
    }
    return 0;
}

void createAccount()
{
    ofstream fileOne("studentInfo.bin", ios::binary | ios::app);
    if (!fileOne)
    {
        cout << "\n\t\t\tError !\n";
    }
    Student studentInformation;
    system("cls");
    cout << "\t\t\t====== Create Student Account ======\n";
    cout << "\n\t\t\tEnter Student's Name : ";
    cin.ignore();
    cin.getline(studentInformation.studentName, 50);
    cout << "\t\t\tEnter Student's ID : ";
    cin.getline(studentInformation.studentId, 15);
    cout << "\t\t\tEnter Student's Department : ";
    cin.getline(studentInformation.studentDept, 10);
    cout << "\t\t\tEnter Student's Address : ";
    cin.getline(studentInformation.studentAddress, 100);
    cout << "\t\t\tEnter Student's Contact Number : ";
    cin.getline(studentInformation.studentContactNum, 15);
    cout << "\t\t\tEnter Student's Current CGPA : ";
    cin >> studentInformation.studentCGPA;
    fileOne.write(reinterpret_cast<char*>(&studentInformation), sizeof(studentInformation));
    cout << "\n\n\t\t\tInformations have been stored successfully\n";
    cout << "\n\n\t\t\tEnter any keys to continue.......";
    cin.ignore();
    cin.get();
    fileOne.close();
}

void displayInfo()
{
    ifstream fileOne("studentInfo.bin", ios::binary);
    if (!fileOne)
    {
        cout << "\n\t\t\tError !\n";
    }
    Student studentInformation;
    system("cls");
    cout << "\t\t\t\t====== All Students Information ======\n"<<endl;
    cout << " Name           ID          Dept          Address         Contact            CGPA"<<endl;
    cout << "----------------------------------------------------------------------------------------"<<endl;
    while (fileOne.read(reinterpret_cast<char*>(&studentInformation), sizeof(studentInformation)))
    {
        cout<<" "<<studentInformation.studentName<<"          "<<studentInformation.studentId<<"          "<<studentInformation.studentDept<<"             "<<studentInformation.studentAddress<<"           "<<studentInformation.studentContactNum<<"          "<<studentInformation.studentCGPA<<endl;
    }
    cout << "\n\n\t\tEnter any keys to continue.......";
    cin.ignore();
    cin.get();
    fileOne.close();
}

void updateInfo()
{
    ifstream fileOne("studentInfo.bin", ios::binary);
    ofstream temp("temp.bin", ios::binary);
    Student studentInformation, tempInformation;
    int choice, flag = 0;
    if (!fileOne || !temp)
    {
        std::cout << "\n\t\t\tError !\n";
    }
    system("cls");
    cout << "\t\t\t\t====== Update Students Information ======\n";
    cout << "\n\t\t\tEnter Student's ID : ";
    cin.ignore();
    cin.getline(tempInformation.studentId, 15);
    while (fileOne.read(reinterpret_cast<char*>(&studentInformation), sizeof(studentInformation)))
    {
        if (strcmp(studentInformation.studentId, tempInformation.studentId) == 0)
        {
            flag++;
            cout << "\n\t\t\tChoose your option :\n\t\t\t1.Update Student Name\n\t\t\t2.Update Student Dept.\n\t\t\t3.Update Student Address\n\t\t\t4.Update Student Contact No.\n\t\t\t5.Update Student CGPA";
            cout << "\n\n\t\t\tEnter Your Option : ";
            cin >> choice;
            if (choice == 1)
            {
                cout << "\n\t\t\tEnter Student's Name to Update: ";
                cin.ignore();
                cin.getline(tempInformation.studentName, 50);
                strcpy(studentInformation.studentName, tempInformation.studentName);
                temp.write(reinterpret_cast<char*>(&studentInformation), sizeof(studentInformation));
                cout << "\n\n\t\t\tUpdated successfully!\n\n";
            }
            else if (choice == 2)
            {
                cout << "\n\t\t\tEnter Student's Dept. to Update: ";
                cin.ignore();
                cin.getline(tempInformation.studentDept, 10);
                strcpy(studentInformation.studentDept, tempInformation.studentDept);
                temp.write(reinterpret_cast<char*>(&studentInformation), sizeof(studentInformation));
                cout << "\n\n\t\t\tUpdated successfully!\n\n";
            }
            else if (choice == 3)
            {
                cout << "\n\t\t\tEnter Student's Address to Update: ";
                cin.ignore();
                cin.getline(tempInformation.studentAddress, 100);
                strcpy(studentInformation.studentAddress, tempInformation.studentAddress);
                temp.write(reinterpret_cast<char*>(&studentInformation), sizeof(studentInformation));
                cout << "\n\n\t\t\tUpdated successfully!\n\n";
            }
            else if (choice == 4)
            {
                cout << "\n\t\t\tEnter Student's Contact No. to Update: ";
                cin.ignore();
                cin.getline(tempInformation.studentContactNum, 15);
                strcpy(studentInformation.studentContactNum, tempInformation.studentContactNum);
                temp.write(reinterpret_cast<char*>(&studentInformation), sizeof(studentInformation));
                cout << "\n\n\t\t\tUpdated successfully!\n\n";
            }
            else if (choice == 5)
            {
                cout << "\n\t\t\tEnter Student's CGPA to Update: ";
                cin >> tempInformation.studentCGPA;
                studentInformation.studentCGPA = tempInformation.studentCGPA;
                temp.write(reinterpret_cast<char*>(&studentInformation), sizeof(studentInformation));
                cout << "\n\n\t\t\tUpdated successfully!\n\n";
            }
            else
            {
                cout << "\n\t\t\tInvalid Option.";
                temp.write(reinterpret_cast<char*>(&studentInformation), sizeof(studentInformation));
            }
        }
        else
        {
            temp.write(reinterpret_cast<char*>(&studentInformation), sizeof(studentInformation));
        }
    }
    fileOne.close();
    temp.close();
    remove("studentInfo.bin");
    rename("temp.bin", "studentInfo.bin");
    if (flag == 0)
    {
        cout << "\n\t\t\tStudent Id is not found";
    }
    cout << "\n\n\t\t\tEnter any keys to continue.......";
    cin.ignore();
    cin.get();
}

void deleteInfo()
{
    ifstream fileOne("studentInfo.bin", ios::binary);
    ofstream temp("temp.bin", ios::binary);
    Student studentInformation, tempInformation;
    int choice, flag = 0;
    if (!fileOne || !temp)
    {
        std::cout << "\n\t\t\tError !\n";
    }
    system("cls");
    cout << "\t\t\t\t====== Delete Student Information ======\n";
    cout << "\n\t\t\tEnter Student's ID : ";
    cin.ignore();
    cin.getline(tempInformation.studentId, 15);
    while (fileOne.read(reinterpret_cast<char*>(&studentInformation), sizeof(studentInformation)))
    {
        if (strcmp(studentInformation.studentId, tempInformation.studentId) == 0)
        {
            flag++;
            cout << "\n\t\t\tAre you sure to delete ??\n\t\t\t\t1.Yes\n\t\t\t\t2.Back\n\t\t\t\tEnter Your Option : ";
            cin >> choice;

            if (choice == 1) {
                cout << "\n\n\t\t\tInformation has been deleted successfully!\n\n";
            } else if (choice == 2) {
                temp.write(reinterpret_cast<char*>(&studentInformation), sizeof(studentInformation));
            } else {
                cout << "\n\t\t\tInvalid Option";
                temp.write(reinterpret_cast<char*>(&studentInformation), sizeof(studentInformation));
            }
        } else {
            temp.write(reinterpret_cast<char*>(&studentInformation), sizeof(studentInformation));
        }
    }
    fileOne.close();
    temp.close();
    remove("studentInfo.bin");
    rename("temp.bin", "studentInfo.bin");
    if (flag == 0) {
        cout << "\n\t\t\tStudent Id is not found";
    }
    cout << "\n\n\t\t\tEnter any keys to continue.......";
    cin.ignore();
    cin.get();
}

void searchInfo() {
    ifstream fileOne("studentInfo.bin", ios::binary);
    Student studentInformation;
    int choice, flag = 0;
    char studentID[20], studentDept[10];
    if (!fileOne) {
        cout << "\n\t\t\tError !\n";
        return;
    }
    cout << "\t\t\t\t====== Search Student Information ======\n";
    cout << "\n\t\t\tChoose your option :\n\t\t\t1.Search by Student ID\n\t\t\t2.Search by Student Dept.";
    cout << "\n\n\t\t\tEnter Your Option : ";
    cin >> choice;
    if (choice == 1) {
        cout << "\t\t\t\t====== Search Student Information ======\n";
        cout << "\n\n\t\t\tEnter Student ID : ";
        cin.ignore();
        cin.getline(studentID, sizeof(studentID));
        while (fileOne.read(reinterpret_cast<char*>(&studentInformation), sizeof(studentInformation))) {
            if (strcmp(studentInformation.studentId, studentID) == 0) {
                flag++;
                cout << "\n\t\t\tStudent Name : " << studentInformation.studentName << "\n\t\t\tStudent ID : " << studentInformation.studentId << "\n\t\t\tStudent Dept. : " << studentInformation.studentDept << "\n\t\t\tStudent Address : " << studentInformation.studentAddress << "\n\t\t\tStudent Contact No. : " << studentInformation.studentContactNum << "\n\t\t\tStudent CGPA : " << studentInformation.studentCGPA << endl;
            }
        }
        if (flag == 0) {
            cout << "\n\t\t\tStudent Id is not found";
        }
    } else if (choice == 2) {
        cout << "\t\t\t\t====== Search Student Information ======\n";
        cout << "\n\n\t\t\tEnter Student Dept. : ";
        cin.ignore();
        cin.getline(studentDept, sizeof(studentDept));
        cout << " Name           ID          Dept          Address         Contact            CGPA"<<endl;
        cout << "----------------------------------------------------------------------------------------"<<endl;
        while (fileOne.read(reinterpret_cast<char*>(&studentInformation), sizeof(studentInformation))) {
            if (stricmp(studentInformation.studentDept, studentDept) == 0) {
                flag++;
                cout<<" "<<studentInformation.studentName<<"          "<<studentInformation.studentId<<"          "<<studentInformation.studentDept<<"             "<<studentInformation.studentAddress<<"           "<<studentInformation.studentContactNum<<"          "<<studentInformation.studentCGPA<<endl;
            }
        }
        if (flag == 0) {
            cout << "\n\t\t\tStudent Id is not found";
        }
    } else {
        cout << "\n\t\t\tInvalid Option";
    }
    fileOne.close();
    cout << "\n\n\n\t\t\tEnter any keys to continue.......";
    cin.ignore();
     cin.get();
}

