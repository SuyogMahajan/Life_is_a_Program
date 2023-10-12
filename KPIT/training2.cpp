#include<iostream>
using namespace std;

class Base{
    public:
    void virtual add() {
        cout <<"base add" << endl;
    }
    void sub() {
        cout <<"base sub stract" << endl;
    }
};

class Deriv: public Base {
    public:
    void add(){
        cout <<"derived add" << endl;
    }

    void sub() {
        cout <<"deriv subb" << endl;
    }
};

int main() {

// Deriv *d = new Deriv();
// d->add();
// Base b = *d;

Base *b = new Base();
Deriv d;
b = &d;

b->add();
b->sub();

// b.add();
return 0;
}