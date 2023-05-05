#include <iostream>
#include <string>
#include "payslip.h"

using namespace std;

int main() {
    
    TaxedSalary e; // create object e of TaxedSalary

    e.input(); // get user input
    e.calculateBaseSalary(); // Calculate base salary
    e.calculateTax(); // Calculate tax informaiton
    e.output(); // Output informaiton Based on class object is created from

    return 0;

}










