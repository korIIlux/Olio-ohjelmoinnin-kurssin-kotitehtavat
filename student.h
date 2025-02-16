#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    Student(string name, int age)
    {
        Name = name;
        Age = age;
    }

    void setAge(int age)
    {
        Age = age;
    }

    void setName(string name)
    {
        Name = name;
    }

    string getName() const
    {
        return Name;
    }

    int getAge() const
    {
        return Age;
    }

    void printStudentInfo() const
    {
        cout << "Opiskelijan nimi: " << Name << ", Ika: " << Age << endl;
    }

private:
    string Name;
    int Age;
};

#endif

