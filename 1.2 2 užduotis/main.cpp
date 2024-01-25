#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const char duomenu_failas [] = "Duomenys.txt";
const char rezultatu_failas [] = "Rezultatai.txt";

int main()
{
    int k, m, n;
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
        df >> k >> m >> n;
        suma = k+k+m+k+m+m;
        df.close();

        ofstream rf (rezultatu_failas);
        rf << suma;
        rf.close();

        return 0;
    }
}



