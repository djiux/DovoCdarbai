#include <iostream>
#include <fstream>

using namespace std;

const int MAX_VAIRUOTOJAI = 3;
const int MAX_DIENOS = 10;

struct Vairuotojas {
    int nuvaziuotiKilometrai[MAX_DIENOS];
    int uzsakymai[MAX_DIENOS];
};

void skaitytiDuomenis(Vairuotojas vairuotojai[], int &kiekDienų) {
    ifstream failas("duomenys.txt");
    failas >> kiekDienų;

    for (int i = 0; i < MAX_VAIRUOTOJAI; i++) {
        for (int j = 0; j < kiekDienų; j++) {
            failas >> vairuotojai[i].nuvaziuotiKilometrai[j];
            failas >> vairuotojai[i].uzsakymai[j];
        }
    }

    failas.close();
}

double vidutiniskaiKilometraiPerDiena(Vairuotojas vairuotojas, int kiekDienų) {
    double suma = 0;
    for (int i = 0; i < kiekDienų; i++) {
        suma += vairuotojas.nuvaziuotiKilometrai[i];
    }
    return suma / kiekDienų;
}

double vidutiniskaiUzsakymaiPerDiena(Vairuotojas vairuotojas, int kiekDienų) {
    double suma = 0;
    for (int i = 0; i < kiekDienų; i++) {
        suma += vairuotojas.uzsakymai[i];
    }
    return suma / kiekDienų;
}

int visoUzsakymai(Vairuotojas vairuotojas, int kiekDienų) {
    int suma = 0;
    for (int i = 0; i < kiekDienų; i++) {
        suma += vairuotojas.uzsakymai[i];
    }
    return suma;
}

int main() {
    Vairuotojas vairuotojai[MAX_VAIRUOTOJAI];
    int kiekDienų;

    skaitytiDuomenis(vairuotojai, kiekDienų);

    cout << "Pradiniai duomenys:" << endl;
    for (int i = 0; i < MAX_VAIRUOTOJAI; i++) {
        cout << "Vairuotojas " << i + 1 << ":" << endl;
        for (int j = 0; j < kiekDienų; j++) {
            cout << "Diena " << j + 1 << ": " << vairuotojai[i].nuvaziuotiKilometrai[j] << " km, "
                 << vairuotojai[i].uzsakymai[j] << " uzsakymai" << endl;
        }
    }

    cout << "\nRezultatai:" << endl;

    // Vidutiniskai nuvaziuoti kilometrai per diena kiekvienam vairuotojui
    for (int i = 0; i < MAX_VAIRUOTOJAI; i++) {
        cout << "Vairuotojas " << i + 1 << " vidutiniskai nuvažiuoja " << vidutiniskaiKilometraiPerDiena(vairuotojai[i], kiekDienų) << " km per diena" << endl;
    }

    // Vidutiniskai atlikti uzsakymai per diena kiekvienam vairuotojui
    for (int i = 0; i < MAX_VAIRUOTOJAI; i++) {
        cout << "Vairuotojas " << i + 1 << " vidutiniskai atlieka " << vidutiniskaiUzsakymaiPerDiena(vairuotojai[i], kiekDienų) << " uzsakymus per diena" << endl;
    }

    // Iš viso uzsakymų (reisų) kiekvienam vairuotojui
    for (int i = 0; i < MAX_VAIRUOTOJAI; i++) {
        cout << "Vairuotojas " << i + 1 << " is viso atliko " << visoUzsakymai(vairuotojai[i], kiekDienų) << " uzsakymus" << endl;
    }

    // Vidutiniskai nuvažiuoti kilometrai per diena visiems vairuotojams
    double visiVidutiniaiKilometrai = 0;
    for (int i = 0; i < MAX_VAIRUOTOJAI; i++) {
        visiVidutiniaiKilometrai += vidutiniskaiKilometraiPerDiena(vairuotojai[i], kiekDienų);
    }
    visiVidutiniaiKilometrai /= MAX_VAIRUOTOJAI;
    cout << "Visi vairuotojai vidutiniskai nuvažiuoja " << visiVidutiniaiKilometrai << " km per diena" << endl;

    // Iš viso uzsakymų (reisų) visiems vairuotojams
    int visiUzsakymai = 0;
    for (int i = 0; i < MAX_VAIRUOTOJAI; i++) {
        visiUzsakymai += visoUzsakymai(vairuotojai[i], kiekDienų);
    }
    cout << "Visi vairuotojai is viso atliko " << visiUzsakymai << " uzsakymus" << endl;

    // Kuris vairuotojas vidutiniskai nuvažiuoja daugiausiai kilometrų per dieną
    double maxVidutiniaiKilometrai = 0;
    int maxVairuotojas = 0;
    for (int i = 0; i < MAX_VAIRUOTOJAI; i++) {
        double vidutiniaiKilometrai = vidutiniskaiKilometraiPerDiena(vairuotojai[i], kiekDienų);
        if (vidutiniaiKilometrai > maxVidutiniaiKilometrai) {
            maxVidutiniaiKilometrai = vidutiniaiKilometrai;
            maxVairuotojas = i + 1;
        }
    }
    cout << "Vairuotojas " << maxVairuotojas << " vidutiniskai nuvažiuoja daugiausiai kilometrų per dieną" << endl;

    return 0;
}
