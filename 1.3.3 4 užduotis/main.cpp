#include <iostream>
#include <time.h>

using namespace std;

// Funkcija, kuri sugeneruoja kiek� atsitiktini� skai�i� tarp minimumo ir maksimumo
void generuotiAtsitiktinius(int kiek, int minimumas, int maksimumas) {
    srand(time(NULL)); // sukuria seed, kuris bus naudojamas atsitiktinio skaiciaus generavimui
    // Sugeneruojame ir i�vedame atsitiktinius skai�ius
    for (int i = 0; i < kiek; ++i) {
        int atsitiktinis = rand() % maksimumas + minimumas;
        cout << atsitiktinis;

        // Atskiriamas kableliu, jei dar ne paskutinis skai�ius
        if (i < kiek - 1) {
            cout << ", ";
        }
    }

    cout << endl;
}

int main() {

    // I�kvie�iame funkcij� su nurodytais parametrais
    generuotiAtsitiktinius(6, 2, 89);

    return 0;
}
