#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

class Student {
public:
    void setIDAndName(int id, string name) {
        this->id = id;
        this->name = name;
    }
    int getID(void) {
        return id;
    }
    string getName(void) {
        return name;
    }
    void setStatus(char status) {
        this->status = status;
    }
    char getStatus(void) {
        return status;
    }
private:
    int id;
    string name;
    char status; // 'A' for absent, 'P' for present, and 'L' for late
};

void removeStudent(vector<Student> &student) {
    vector<Student>::iterator removeStudent;
    int selectedStudent;
    cout << "Please type the number associated with the student you would like to remove" << endl;
    for(int i = 0; i < student.size(); i++) {
        cout << "Student(" << i << ") " << student.at(i).getName() << endl;
    }
    cout << "\nStudent: ";
    cin >> selectedStudent;
    removeStudent = student.begin() + selectedStudent;
    student.erase(removeStudent);
    // return student;
}

void addStudent(vector<Student> &students) {
    Student student;
    string name;
    int age;
    int grade;
    int id;
    char status;

    cout << "Enter student name: ";
    cin >> name;
    cout << "Enter student id: ";
    cin >> id;
    student.setIDAndName(id, name);
    //TODO: Input validation
    cout << "Enter student status: ((P)resent, (L)ate, (A)bsent), or (E)xcused) ";
    cin >> status;
    student.setStatus(toupper(status));

    students.push_back(student);
}

void printClass(vector<Student> students) {
    string fullStatus;

    for(int i = 0; i < students.size(); i++) {
        cout << students[i].getName() << " (" << students[i].getID() << ")" << ": ";
        
        if(students[i].getStatus() == 'P') {
            fullStatus = "Present";
        } 
        else if(students[i].getStatus() == 'L') {
            fullStatus = "Late";
        } 
        else if(students[i].getStatus() == 'A') {
            fullStatus = "Absent";
        }
        else if(students[i].getStatus() == 'E') {
            fullStatus = "Excused";
        }

        cout << fullStatus << endl;
    }
}

void takeAttendence(vector<Student> &students) {
    char status;
    
    for (int i = 0; i < students.size(); i++) {
        cout << students[i].getName() << " (" << students[i].getID() << ")" << ": ";
        cout << "Enter student status: ((P)resent, (L)ate, (A)bsent), or (E)xcused) ";
        cin >> status;
        students[i].setStatus(toupper(status));
    }
}

int main(void) {
    vector<Student> students;
    int choice;
    bool quit = false;

    while (!quit) {
        cout << "1. Add student" << endl;
        cout << "2. Remove student" << endl;
        cout << "3. Print student list" << endl;
        cout << "4. Take attendance" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                removeStudent(students);
                break;
            case 3:
                printClass(students);
                break;
            case 4:
                takeAttendence(students);
                break;
            case 5:
                quit = true;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    }

    return 0;
}

