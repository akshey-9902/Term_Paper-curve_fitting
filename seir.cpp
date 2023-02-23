#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
double t_incubation = 5.1, t_infection = 3.3, R0 = 2.4, N = 33517, u = 0.1;
double e[365];
double s[365];
double i[365];
double r[365];
double A = 1 / t_incubation, G = 1 / t_infection, B = R0 * G;

double fs(double s, double e, double i, double r)
{
    return (u - 1) * B * s * i;
}
double fe(double s, double e, double i, double r)
{
    return (1 - u) * B * s * i - A * e;
}
double fi(double s, double e, double i, double r)
{
    return A * e - G * i;
}
double fr(double s, double e, double i, double r)
{
    return G * i;
}
int main()
{
    e[0] = 1.0 / N;
    i[0] = 0.0;
    r[0] = 0.0;
    s[0] = 1 - e[0] - i[0] - r[0];
    int h = 2;
    double ks1, ks2, kr1, kr2, ke1, ke2, ki1, ki2, sm, em, im, rm;
    for (int k = 0; k < 365 - h; k += h)
    {
        ks1 = fs(s[k], e[k], i[k], r[k]);
        ke1 = fe(s[k], e[k], i[k], r[k]);
        ki1 = fi(s[k], e[k], i[k], r[k]);
        kr1 = fr(s[k], e[k], i[k], r[k]);
        sm = s[k] + h * ks1;
        em = s[k] + h * ke1;
        im = s[k] + h * ki1;
        rm = s[k] + h * kr1;
        ks2 = fs(sm, em, im, rm);
        ke2 = fe(sm, em, im, rm);
        ki2 = fi(sm, em, im, rm);
        kr2 = fr(sm, em, im, rm);
        s[k + h] = s[k] + h / 2 * (ks1 + ks1);
        e[k + h] = e[k] + h / 2 * (ke1 + ke1);
        i[k + h] = i[k] + h / 2 * (ki1 + ki1);
        r[k + h] = r[k] + h / 2 * (kr1 + kr1);
    }
    cout << "Day  s  \n";
    for (int k = 0; k < 365 - h; k += h)
    {
        cout << k << "  " << s[k] << "\n";
    }
    cout << "Day  e  \n";
    for (int k = 0; k < 365 - h; k += h)
    {
        cout << k << "  " << e[k] << "\n";
    }
    cout << "Day  i  \n";
    for (int k = 0; k < 365 - h; k += h)
    {
        cout << k << "  " << i[k] << "\n";
    }
    cout << "Day  r  \n";
    for (int k = 0; k < 365 - h; k += h)
    {
        cout << k << "  " << r[k] << "\n";
    }

    return 0;
}
