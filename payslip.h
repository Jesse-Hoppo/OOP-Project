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

        // Deconstrucor deallocate memory
        ~Employee() {
        delete name;
        delete location;
        delete jobPosition;
        }

        void input(); // Defined Function for employee info input
        virtual void output(); // Defined function for employee info ouput

        string* getName() {return name;} // function to access Employee name
        string* getLocation() {return location;} // function to access Employee location
        string* getJobPosition() {return jobPosition;} // function to access Employee jobPosition

        
        void destroy() { // function to forecfully remove allocated memory 
        delete name;
        delete location;
        delete jobPosition;
        name = nullptr;
        location = nullptr;
        jobPosition = nullptr;
        }
};

void Employee::input() {  // function to get all user input for Employee details

    // Get input from user and set to the Employees name
    cout << "Enter name: ";
    cin >> *name;

    bool validLocation = false; // set variable of bool to false
    while (!validLocation) { // loop until bool value is changed to true
        cout << "Enter location (Adelaide, Melbourne, Sydney): ";
        cin >> *location; // take user input and dynamically change location
        if (*location == "Adelaide" || *location == "Melbourne" || *location == "Sydney") { // if location matches one of the three options change bool and break loop
            validLocation = true;
        } else { // Otherwise provide user infromaiton to the error and loop until valid location entered
            cout << "Invalid location. Please enter Adelaide, Melbourne, or Sydney." << endl;
        }
    }

    //Exact same as valid locaiton above but for job position
    bool validJobPosition = false;
    while (!validJobPosition) {
        cout << "Enter job position (Programmer, Engineer, Consultant): ";
        cin >> *jobPosition;
        if (*jobPosition == "Programmer" || *jobPosition == "Engineer" || *jobPosition == "Consultant") {
            cout << "" << endl;
            validJobPosition = true;
        } else {
            cout << "Invalid job position. Please enter Programmer, Engineer, or Consultant." << endl;
        }
    }
}

void Employee::output() { // function to output all Employee information if needed
    cout << "Name: " << *name << endl;
    cout << "Location: " << *location << endl;
    cout << "Job Position: " << *jobPosition << endl;
}


//-----------------------------------------------------------------------------------//
// CLASS 2 //

class BaseSalary : public Employee {
    protected:
        double baseSalary; //initalized a base salary

    public:
        BaseSalary() : Employee() { // Set constructer for base salary
            baseSalary = 0;
        }

        double getBaseSalary() {return baseSalary;} // function to access baseSalary

        void setLocationMultiplier(); // defined function 
        void setBaseSalary(); // defined function
        void calculateBaseSalary(); //defined function
        virtual void output(); // defined function
};

void BaseSalary::setLocationMultiplier(){ // Function to take an Employees locaiton and multiply their base salary dependant on their location

    if (*getLocation() == "Adelaide") { // Set adelaide to 0.8 times base
        baseSalary *= 0.8;
    } else if (*getLocation() == "Melbourne") { // Set melbourne to 1.2 times base
        baseSalary *= 1.2;
    } else if (*getLocation() == "Sydney") { // Set sydnet to be 1.0 times base
        baseSalary *= 1.0;
    }
}

void BaseSalary::setBaseSalary(){ // Function to set a base salary for an Employee Based on their job position

    if (*getJobPosition() == "Programmer") { // Set a Programmers base weekly salary to be $1500
        baseSalary = 1500;
    } else if (*getJobPosition() == "Engineer") { // Set a Engineers base weekly salary to be $1800
        baseSalary = 1800;
    } else if (*getJobPosition() == "Consultant") { // Set a Consultants base weekly salary to be $1700
        baseSalary = 1700;
    }

}

void BaseSalary::calculateBaseSalary(){ // Function to calcualte an Employees base salary
    setBaseSalary();
    setLocationMultiplier();
}

void BaseSalary::output(){ // Function to print all Employee inofrmation to user
    
    cout << "" << endl;
    cout << "Name: " << *getName() << endl;
    cout << "Location: " << *getLocation() << endl;
    cout << "Job Position: " << *getJobPosition() << endl; 

    cout << "Base Salary: $" << fixed << setprecision(2) << baseSalary << endl;
    cout << "" << endl;

}


//-----------------------------------------------------------------------------------//
// CLASS 3 //

class TaxedSalary : public BaseSalary {
    protected:
        double taxAmount;
        double taxRate;
        double taxSalary;

    public:
        TaxedSalary(){
        taxAmount = 0;
        taxRate = 0;
        taxSalary = 0;
        }

        void calculateTax();   
        void output();
        double getTaxSalary() {return taxSalary;}
        double getTaxAmount() {return taxAmount;}
        double getTaxRate() {return taxRate;}



};

void TaxedSalary::calculateTax(){

    double annualSalary = baseSalary * 52;
    
    if (annualSalary <= 18200) {
        taxAmount = 0;
    } else if (annualSalary <= 45000 ) {
        taxAmount = (annualSalary - 18200) * 0.19;
    } else if (annualSalary <= 120000) {
        taxAmount = 5092 + (annualSalary - 45000) * 0.325;
    } else if (annualSalary <= 180000) {
        taxAmount = 29467 + (annualSalary - 120000) * 0.37;
    }

    taxSalary = (annualSalary - taxAmount) / 52;
    taxRate = (taxAmount / annualSalary) * 100;
    taxAmount = baseSalary - taxSalary;

}

void TaxedSalary::output(){

    cout << "Employee Information: " << endl;
    cout << "" << endl;
    cout << "Name: " << *getName() << endl;
    cout << "Location: " << *getLocation() << endl;
    cout << "Job Position: " << *getJobPosition() << endl;
    cout << "Base Salary: " << baseSalary << endl;
    cout << "Tax Amount: " << taxAmount << endl;
    cout << "Tax Rate: " << taxRate << "%" << endl;
    cout << "Salary After Tax " << taxSalary << endl;
    cout << "" << endl;



}