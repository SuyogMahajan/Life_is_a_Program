#include<iostream>
#include"student.cpp"
using namespace std;

int main() {

    student s1("Suyog" ,"KPIT" ,"Software Dev" ,122 ,600000);
    student s2("Ankit" ,"KPIT" ,"Software Dev" ,122 ,600000);
    student s3("Sneha" ,"KPIT" ,"Software Dev" ,122 ,600000);
    
    s1.print();
    s2.print();
    s3.print();

    return 0;
}