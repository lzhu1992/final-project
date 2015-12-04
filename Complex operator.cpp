//Author:Chunguang Li
#include <iostream>
using namespace std;

/*I did some Complex number operators according to what we have learned.
This can be used exclusively or be a part of our project as a header file.
*/

class Complex
{
private:
    double real;
    double imag;

public:
    Complex(){real=0;imag=0;}
    Complex(double r,double i){real=r;imag=i;}
    Complex operator +(Complex &c2);
    Complex operator -(Complex &c2);
    Complex operator *(Complex &c2);
    Complex operator /(Complex &c2);
    void display();
};

//Complex addition
Complex Complex ::operator+(Complex &c2)
{
    Complex c;
    c.real=real + c2.real;
    c.imag=imag+c2.imag;
    return c;
}

//Complex subtraction
Complex Complex ::operator-(Complex &c2)
{
    Complex c;
    c.real=real-c2.real;
    c.imag=imag-c2.imag;
    return c;
}

//Complex multiplication
Complex Complex ::operator*(Complex &c2)
{
    Complex c;
    c.real=real*c2.real-imag*c2.imag;
    c.imag=imag*c2.real+real*c2.imag;
    return c;
}

//Complex division
Complex Complex ::operator/(Complex &c2)
{
    Complex c;
    c.real=(real*c2.real+imag*c2.imag)/(c2.real*c2.real+c2.imag*c2.imag);
    c.imag=(imag*c2.real+real*c2.imag)/(c2.real*c2.real+c2.imag*c2.imag);
    return c;
}

//show result
void Complex ::display()
{
    cout<<"("<<real<<","<<imag<<"i)"<<endl;
}

int main()
{
    double a, b, c, d;
    cout<< "Enter a, b, c, d:"<<endl;
    cin>>a>>b>>c>>d;
    Complex c1(a,b),c2(c,d),c3;
    c3=c1+c2;
    cout<<"c1+c2=";
    c3.display();
    c3=c1-c2;
    cout<<"c1-c2=";
    c3.display();
    c3=c1*c2;
    cout<<"c1*c2=";
    c3.display();
    c3=c1/c2;
    cout<<"c1/c2=";
    c3.display();
    return 0;
}

