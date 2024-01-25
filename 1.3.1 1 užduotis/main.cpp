#include <iostream>
#include <fstream>
#include <string>

const char duomenu_failas[] = "Duomenys.txt";


using namespace std;

void zodziai_su_bruksniais();


int main() {
    ifstream df(duomenu_failas);

    if (!df) {
        cout << "Nepavyko atidaryti failo: " << endl;
        return-1;
    }

    string zodis;
    while (df >> zodis) {
        cout << "-" << zodis << endl;
    }

    df.close();
}
