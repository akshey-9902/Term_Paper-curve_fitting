#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int main()
{
    int d;
    int nv, ng;
    cout << "Enter the dimension of the system:\n";
    cin >> d;
    cout << "enter the no of value data points:\n";
    cin >> nv;
    cout << "enter the no of gradient data points:\n";
    cin >> ng;

    double xv[nv][d], xg[ng][d];
    double fv[nv];
    double ev[nv];
    if (nv != 0)
    {
        cout << "enter the value of value data points(fv):\n";
        for (int i = 1; i <= nv; i++)
        {

            cin >> fv[i - 1];
        }
        cout << "enter the error  of value data points:\n";
        for (int i = 1; i <= nv; i++)
            cin >> ev[i - 1];
    }
    double fg[ng][d];
    double eg[ng][d];
    if (ng != 0)
    {
        cout << "enter the value of gradient data points(xg,fg):\n";
        for (int i = 1; i <= ng; i++)
        {
            for (int j = 0; i < d; j++)
                cin >> xg[i - 1][j];
            for (int j = 0; i < d; j++)
                cin >> fg[i - 1][j];
        }

        cout << "enter the error  of gradient data points:\n";
        for (int i = 1; i <= ng; i++)
            for (int j = 0; i < d; j++)
                cin >> eg[i - 1][j];
    }
    double avg = 0;
    for (int i = 1; i <= nv; i++)
        avg += fv[i - 1];
    avg /= nv;
    double avg2 = 0;
    for (int i = 1; i <= nv; i++)
        avg2 += pow(fv[i - 1] - avg, 2);
    avg2 /= nv - 1;
    avg2 = pow(avg2, 0.5);
    cout << "the value of Beta is=" << avg2;
    return 0;
}
