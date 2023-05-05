#include<fstream>
#include<string>
#include<iostream>
#include <stdlib.h>
#include <vector>
#include <iomanip>

using namespace std;

class Employee {
    protected:

        // Initialize dynamic strings for Employee info
        string* name;
        string* location;
        string* jobPosition;

    public:

        // Set Constructor iinformation to be a new string of each info
        Employee() {
        name = new string;
        location = new string;
        jobPosition = new string;
        }

        // Deconstruco=tor to be called
        ~Employee() {
        delete name;
        delete location;
        delete jobPosition;
        }

        void input();
        void output();

        string* getName() {return name;}
        string* getLocation() {return location;}
        string* getJobPosition() {return jobPosition;}

        
        void destroy() {
        delete name;
        delete location;
        delete jobPosition;
        name = nullptr;
        location = nullptr;
        jobPosition = nullptr;
        }
};

void Employee::input() {
    cout << "Enter name: ";
    cin >> *name;

    bool validLocation = false;
    while (!validLocation) {
        cout << "Enter location (Adelaide, Melbourne, Sydney): ";
        cin >> *location;
        if (*location == "Adelaide" || *location == "Melbourne" || *location == "Sydney") {
            validLocation = true;
        } else {
            cout << "Invalid location. Please enter Adelaide, Melbourne, or Sydney." << endl;
        }
    }

    bool validJobPosition = false;
    while (!validJobPosition) {
        cout << "Enter job position (Programmer, Engineer, Consultant): ";
        cin >> *jobPosition;
        if (*jobPosition == "Programmer" || *jobPosition == "Engineer" || *jobPosition == "Consultant") {
            validJobPosition = true;
            cout << "" << endl;
        } else {
            cout << "Invalid job position. Please enter Programmer, Engineer, or Consultant." << endl;
        }
    }
}

void Employee::output() {
    cout << "Name: " << *name << endl;
    cout << "Location: " << *location << endl;
    cout << "Job Position: " << *jobPosition << endl;
}


//-----------------------------------------------------------------------------------//
// CLASS 2

class BaseSalary : public Employee {
    protected:
        double baseSalary;

    public:
        BaseSalary() : Employee() {
            baseSalary = 0;
        }

        double getBaseSalary() {return baseSalary;}


        void setLocationMultiplier();
        void setBaseSalary();
        void calculateBaseSalary();
        void printEmployeeInfo();
};

void BaseSalary::setLocationMultiplier(){

    if (*getLocation() == "Adelaide") {
        baseSalary *= 0.8;
    } else if (*getLocation() == "Melbourne") {
        baseSalary *= 1.2;
    } else if (*getLocation() == "Sydney") {
        baseSalary *= 1.0;
    }
}

void BaseSalary::setBaseSalary(){

    if (*getJobPosition() == "Programmer") {
        baseSalary = 1500;
    } else if (*getJobPosition() == "Engineer") {
        baseSalary = 1800;
    } else if (*getJobPosition() == "Consultant") {
        baseSalary = 1700;
    }

}

void BaseSalary::calculateBaseSalary(){
    setBaseSalary();
    setLocationMultiplier();
}

void BaseSalary::printEmployeeInfo(){

    cout << "" << endl;
    cout << "Name: " << *getName() << endl;
    cout << "Location: " << *getLocation() << endl;
    cout << "Job Position: " << *getJobPosition() << endl;
    cout << "Base Salary: $" << fixed << setprecision(2) << baseSalary << endl;
    cout << "" << endl;

}
