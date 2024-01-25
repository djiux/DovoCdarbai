#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const char duomenu_failas [] = "Duomenys.txt";
const char rezultatu_failas [] = "Rezultatai.txt";

int main()
{
    int n;
    double suma = 0,
    b;

    setlocale(LC_ALL, "Lithuanian");
    ifstream df(duomenu_failas);
    if (!df)
    {
        cout << "Failas neatidarytas" << endl;

        return -1;
    }
    else
    {
        df >> n;

        for (int i = 0; i < n; i++)
        {
            df >> b;
            suma += b;
        }
        ofstream rf (rezultatu_failas);
        rf << fixed << setprecision(2) << suma;
        rf.close();

        return 0;
    }
}
