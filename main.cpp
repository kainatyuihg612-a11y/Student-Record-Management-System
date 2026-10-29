#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Student class to handle individual student data
class Student {
private:
    int rollNumber;
    string name;
    string studentClass;
    float attendancePercentage;

public:
    // Constructor to initialize data
    Student(int r, string n, string c, float a) {
        rollNumber = r;
        name = n;
        studentClass = c;
        attendancePercentage = a;
    }

    // Getter functions to display data
    int getRollNumber() { return rollNumber; }
    string getName() { return name; }
    string getStudentClass() { return studentClass; }
    float getAttendance() { return attendancePercentage; }

    // Function to display single student details
    void displayStudent() {
        cout << "\n-----------------------------------" << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Name:        " << name << endl;
        cout << "Class:       " << studentClass << endl;
        cout << "Attendance:  " << attendancePercentage << "%" << endl;
        cout << "-----------------------------------" << endl;
    }
};

// School Management System Class
class SchoolManagement {
private:
    vector<Student> students;

public:
    // 1. Function to add a new student
    void addStudent() {
        int roll;
        string name, sClass;
        float att;

        cout << "\nEnter Roll Number: ";
        cin >> roll;
        cin.ignore(); // To clear the input buffer
        cout << "Enter Student Name: ";
        getline(cin, name);
        cout << "Enter Class: ";
        getline(cin, sClass);
        cout << "Enter Attendance Percentage: ";
        cin >> att;

        // Creating student object and adding to vector list
        Student newStudent(roll, name, sClass, att);
        students.push_back(newStudent);
        cout << "\n[Success] Student record added successfully!" << endl;
    }

    // 2. Function to display all student records
    void viewAllStudents() {
        if (students.empty()) {
            cout << "\n[Info] No student records available." << endl;
            return;
        }

        cout << "\n====== ALL STUDENT RECORDS ======" << endl;
        for (int i = 0; i < students.size(); i++) {
            students[i].displayStudent();
        }
    }

    // 3. Function to search student by roll number
    void searchStudent() {
        if (students.empty()) {
            cout << "\n[Info] System is empty. No record to search." << endl;
            return;
        }

        int roll;
        cout << "\nEnter Roll Number to search: ";
        cin >> roll;

        for (int i = 0; i < students.size(); i++) {
            if (students[i].getRollNumber() == roll) {
                cout << "\n[Match Found] Here are the details:";
                students[i].displayStudent();
                return;
            }
        }
        cout << "\n[Error] Student with Roll Number " << roll << " not found." << endl;
    }
};

int main() {
    SchoolManagement system;
    int choice;

    while (true) {
        cout << "\n=========================================" << endl;
        cout << "   SCHOOL RECORD MANAGEMENT SYSTEM (C++)   " << endl;
        cout << "=========================================" << endl;
        cout << "1. Add New Student Record" << endl;
        cout << "2. View All Student Records" << endl;
        cout << "3. Search Student by Roll Number" << endl;
        cout << "4. Exit System" << endl;
        cout << "Current Semester: 3rd (ADP Computer Science)" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                system.addStudent();
                break;
            case 2:
                system.viewAllStudents();
                break;
            case 3:
                system.searchStudent();
                break;
            case 4:
                cout << "\nThank you for using the School Management System. Goodbye!" << endl;
                return 0;
            default:
                cout << "\n[Invalid Choice] Please enter a number between 1 and 4." << endl;
        }
    }
    return 0;
}
