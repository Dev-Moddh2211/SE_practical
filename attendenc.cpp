#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
private:
    int rollNo;
    string name;
    bool isPresent;

public:
    Student(int r, string n) {
        rollNo = r;
        name = n;
        isPresent = false;
    }

    void markPresent() {
        isPresent = true;
    }

    void markAbsent() {
        isPresent = false;
    }

    int getRollNo() const {
        return rollNo;
    }

    string getName() const {
        return name;
    }

    bool getAttendance() const {
        return isPresent;
    }

    void display() const {
        cout << "Roll No: " << rollNo
             << ", Name: " << name
             << ", Attendance: " << (isPresent ? "Present" : "Absent") << endl;
    }
};

class AttendanceSystem {
private:
    vector<Student> students;

public:
    void addStudent(int roll, const string& name) {
        students.emplace_back(roll, name);
        cout << "Student added successfully!\n";
    }

    void markAttendance(int roll, bool present) {
        for (auto& student : students) {
            if (student.getRollNo() == roll) {
                if (present)
                    student.markPresent();
                else
                    student.markAbsent();
                cout << "Attendance marked for Roll No " << roll << ".\n";
                return;
            }
        }
        cout << "Student with Roll No " << roll << " not found.\n";
    }

    void displayAttendance() const {
        cout << "\n--- Attendance Records ---\n";
        for (const auto& student : students) {
            student.display();
        }
    }
};

// Main driver
int main() {
    AttendanceSystem system;
    int choice;

    while (true) {
        cout << "\n===== Attendance Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Mark Attendance\n";
        cout << "3. Display Attendance\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int roll;
            string name;
            cout << "Enter Roll No: ";
            cin >> roll;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            system.addStudent(roll, name);
        }
        else if (choice == 2) {
            int roll, status;
            cout << "Enter Roll No to mark attendance: ";
            cin >> roll;
            cout << "Enter 1 for Present, 0 for Absent: ";
            cin >> status;
            system.markAttendance(roll, status == 1);
        }
        else if (choice == 3) {
            system.displayAttendance();
        }
        else if (choice == 4) {
            cout << "Exiting the program.\n";
            break;
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
