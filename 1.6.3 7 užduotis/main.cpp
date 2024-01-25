//Prijungiame bibliotekas
#include <iostream>  // Ávedimo ir iðvedimo operacijoms
#include <fstream>   // Failø ávedimui ir iðvedimui

// Naudotojui nereikia rûpintis std:: prieð funkcijas ifstream ofstream cout endl df rf
using namespace std;

int main() { //Pagrindinë funkcija
    // Atidaryti duomenø failà ávedimui ir rezultatø failà iðvedimui
    ifstream df("duomenys.txt");   // Ávesties failas
    ofstream rf("rezultatai.txt"); // Rezultatø failas

    // Patikriname, ar pavyko atidaryti ávesties failà
    if (!df) {
        cout << "Nepavyko atidaryti failo!" << endl;
        return 1;
    }

    // Turima informacija
    int treniruociuSkaicius;
    df >> treniruociuSkaicius;//Nuskaitome duomenis ið failo

    // Masyvas, kuriame saugosime taðkø kieká kiekvienoje treniruotëje
    int taskai[100]; // Pavyzdinës ribos

    // Nuskaitome duomenis ið failo
    for (int i = 0; i < treniruociuSkaicius; i++) {
        df >> taskai[i];
    }

    // Apskaièiuojame vidutiniðkai ámetamus taðkus
    double vidurkis = 0;
    for (int i = 0; i < treniruociuSkaicius; i++) {
        vidurkis += taskai[i];
    }
    vidurkis /= treniruociuSkaicius;

    // Iðvedame pradinius duomenis á rezultatø failà
    rf << "Krepðininko treniruoèiø taðkø kiekis: ";
    for (int i = 0; i < treniruociuSkaicius; i++) {
        rf << taskai[i] << " ";
    }
    rf << endl;

    // Iðvedame gautus atsakymus á rezultatø failà
    rf << "Krepðininko vidutiniðkai ámeta taðkø per treniruotæ: " << vidurkis << endl;

    // Turime komandos vidurká (galimà ið duomenø failo arba ávesti ranka)
    int komandosVidurkis;
    df >> komandosVidurkis;

    rf << "Komandos vidurkis: " << komandosVidurkis << endl;

    // Palyginimas su komandos vidurkiu ir iðvedimas á rezultatø failà
    if (vidurkis > komandosVidurkis) {
        rf << "Krepðininkui sekasi geriau nei komandai." << endl;
    } else if (vidurkis < komandosVidurkis) {
        rf << "Krepðininkui sekasi blogiau nei komandai." << endl;
    } else {
        rf << "Krepðininko ir komandos vidurkiai vienodi." << endl;
    }

    // Uþdarome failus
    df.close();
    rf.close();

    return 0;
}
