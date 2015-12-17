//Author: Chunguang Li
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float a, b, c, disc, x1, x2, p, q;
    cout << "input a, b, c:";
    cin >> a >> b >> c;

    //consider about the case if any coefficient is 0

    if(a==0)
        if(b==0)
            if(c==0)
                cout << "It is trivial." << endl;
            else
                cout << "It is impossible." << endl;
            else
            {
                cout << "It has one solution:" << endl;
                cout << "x=" << -c/b << endl;
            }

       // using discriminant to check the root number

        else
        {
            disc=b*b-4*a*c;
            if (disc>=0)
                if(disc>0)
                {
                    cout << "It has two real solution:" <<endl;
                    x1=(-b+sqrt(disc)/(2*a));
                    x2=(-b-sqrt(disc)/(2*a));
                    cout << "x1="<<x1<<", x2="<<x2<<endl;
                }
            else
            {
                cout<< "It has two same real solution:"<<endl;
                cout<< "x1=x2="<<-b/(2*a)<<endl;
            }
        else
        {
            cout<< "It has two complex solution:"<<endl;
            p=-b/(2*a);
            q=sqrt(-disc)/(2*a);
            cout<<"x1="<<p<<"+"<<q<<"i, x2="<<p<<"-"<<q<<"i"<<endl;
        }

        }
        return 0;
}
