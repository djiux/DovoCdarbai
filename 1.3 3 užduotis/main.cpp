#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const char duomenu_failas[] = "temperaturos.txt";
const char rezultatu_failas[] = "vidutines.txt";


int main() {
    int n;
    string miestas;
    double temp;

    setlocale(LC_ALL, "Lithuanian");
    ifstream df("temperaturos.txt");
    ofstream rf("vidutines.txt");

    if (!df) {
        cout << "Nepavyko atidaryti duomenø failo." << endl;
        return -1;
    }
    else{

    df >> n;

    for (int i = 0; i < n; i++) {
        double temp_suma = 0.0;

        for (int j = 0; j < 7; j++) {
            df >> temp;
            temp_suma += temp;

        }
        double vidut_temp = temp_suma / 7.0;
        rf << (i + 1) << " " << fixed << setprecision(3) << vidut_temp << endl;
    }
    rf.close();
    df.close();
    return 0;
    }
}
