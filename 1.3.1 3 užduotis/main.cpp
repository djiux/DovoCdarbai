#include <iostream>
#include <fstream>
#include <time.h>

const char duomenu_failas[] = "zodziai.txt";
const char rezultatu_failas[] = "skaicius.txt";

using namespace std;

void atsitiktinis_zodis ()
{
    setlocale(LC_ALL, "Lithuanian");
    ifstream df(duomenu_failas);

     if (!df) {
        cout << "Nepavyko atidaryti failo." << endl;
        return;
     }

     string zodis;
     int zodziu_skaicius = 0;

     while(df >> zodis){
        zodziu_skaicius++;
        if(rand() % zodziu_skaicius == 0){
            cout << "Atsitiktinai isrinktas zodis yra " << zodis << endl;
        }
     }
     df.close();
}
void atsitiktinis_skaicius ()
{
    srand(time(NULL));
    int v1 = rand() % 100;

    ofstream rf(rezultatu_failas);
    rf << v1;
    rf.close();

    cout << "Atsitiktinis skaicius: " << v1 << endl;

}
void metodu_vykdytojas()
{
    atsitiktinis_zodis();
    atsitiktinis_skaicius();

}
int main(){

    metodu_vykdytojas();
    return 0;
}
