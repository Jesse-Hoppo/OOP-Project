#include<fstream>
#include<string>
#include<iostream>
using namespace std;

#ifndef PAYSLIP_H
#define PAYSLIP_H

class Employee {
    protected:
        string name;
        string location;
        string job_postion;
        int YOE;
        
    public:
    Employee( string s_name, string s_location, string s_job_postion, int s_YOE) {
        name = s_name;
        location = s_location;
        job_postion = s_job_postion;
        YOE = s_YOE;

    }

};
#endif