#include <iostream>
#include <fstream>
using namespace std;

const char duomenu_failas [] = "Duomenys.txt";
const char rezultatu_failas [] = "Rezultatai.txt";

int main() {
    int x1, x2;
    int l=0;
    setlocale(LC_ALL, "Lithuanian");
    ifstream df(duomenu_failas);
    if (!df) {
        cout << "Failas neatidarytas." << endl;
        return -1;
    }
    else
    {
    df >> x1 >> x2;

     ofstream rf (rezultatu_failas);

    rf << "**********" << endl;

    for (int i = x1; i <= x2; i++) {
        for (int j = x1; j <= x2; j++) {

            if (i-j>0 && i%j==0 && l <4)
            {
            rf << i << " + " << j << " = " << i + j << endl;
            rf << i << " - " << j << " = " << i - j << endl;
            rf << i << " * " << j << " = " << i * j << endl;
            rf << i << " / " << j << " = " << i / j << endl;
            rf << "**********" << endl;
            l++;
            }
        }
    }

}
    cout << "Užduotys áraðytos á rezultatø failà rezultatai.txt" << endl;

    return 0;
}
