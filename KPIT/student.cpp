#include<iostream>
using namespace std;

class company{ 
    public:
    string cname;
    string role;
    int salary;

    company() {
        cname = "NULL";
        role = "NULL";
        salary = 0;
    }

    company(string name,string role,int sal) {
        this->cname = name;
        this->role = role;
        this->salary = sal;
    }

};

class student : public company {

    public:
    string name;
    int roll_no;

    student(string s,int ro) {
        name = s;
        roll_no = ro;
    }

    student(string s,string comp,string rol,int roll_n,int sal) {
        
        name = s;
        cname = comp;
        role = rol;
        roll_no = roll_n;
        salary = sal;
    }

    void print() {
        cout << name <<" " << cname <<" "<<role << " " << roll_no << " " <<salary << endl;
    }
};
