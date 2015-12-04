//Author: Chunguang Li
#include <iostream>
#include <cmath>
using namespace std;

// Using Simpson and Trapezoidal rules to integrate a equation

class Integration
{

 private:
    double A; //area under the curve
    double xmin, xmax; //limits of integration
    int numberOfPoints;
    double (*f)(double x); //function to be integrated

 public:
    Integration( double (*F)(double x), double a, double b, int n)
    {
        f=F;
        xmin=a;
        xmax=b;
        numberOfPoints=n;
    }
    double Trapezoidal();
    double Simpson();
 };

double Integration::Trapezoidal()
 {
    double dx=(xmax-xmin)/double(numberOfPoints);
    double sum=0.0;
    double x=xmin+dx;
    for(int i=1; i< numberOfPoints; i++)
    {
        sum+=(*f)(x);
        x+=dx;
    }
        A=(*f)(xmin)+(*f)(xmax)+2.0*sum;
        A*=dx/double(2.0);
        return A;
    }

double Integration::Simpson()
 {
    double dx=(xmax-xmin)/double(numberOfPoints);
    double sum1=0, sum2=0.0;
    double x=xmin+dx;
    for(int i=1; i< numberOfPoints; i++)
    {
        if(i%2!=0)
        sum1+=(*f)(x);
        else
        sum2+=(*f)(x);
        x+=dx;
    }
    A=(*f)(xmin)+(*f)(xmax)+4.0*sum1+2.0*sum2;
    A*=dx/double(3.0);
    return A;
 }

//Different equations, can be changed as needed

 double FUNA(double x)
 {
    return exp(-x)*sin(x)*sin(x);
 }

 double FUNB(double x)
 {
    return 1.0/((1+x*x)*(1+x*x/2.0));
 }

 double FUNC(double x)
 {
    return x*exp(-x);
 }

 double FUND(double x)
 {
    return exp(-x*x/2.0);
 }


int main()
{
    double a, b, c;
    cout<<"Please enter 3 number:"<<endl;
    cin>>a>>b>>c;

    Integration IA(FUNA,a,b,c), IB(FUNB,a,b,c), IC(FUNC,a,b,c),ID(FUND,a,b,c);
    cout << "IA. " << IA.Simpson() << endl;
    cout << "IB. " << IB.Simpson() << endl;
    cout << "IC. " << IC.Simpson() << endl;
    cout << "ID. " << (ID.Simpson()/sqrt(2.0*3.14159)) << endl;

    Integration TA(FUNA,a,b,c), TB(FUNB,a,b,c), TC(FUNC,a,b,c),TD(FUND,a,b,c);
    cout << "TA. " << TA.Trapezoidal() << endl;
    cout << "TB. " << TB.Trapezoidal() << endl;
    cout << "TC. " << TC.Trapezoidal() << endl;
    cout << "TD. " << (TD.Trapezoidal()/sqrt(2.0*3.14159)) << endl;

    return 0;
}

