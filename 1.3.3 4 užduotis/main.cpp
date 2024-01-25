#include <iostream>
#include <time.h>

using namespace std;

// Funkcija, kuri sugeneruoja kieká atsitiktiniø skaièiø tarp minimumo ir maksimumo
void generuotiAtsitiktinius(int kiek, int minimumas, int maksimumas) {
    srand(time(NULL)); // sukuria seed, kuris bus naudojamas atsitiktinio skaiciaus generavimui
    // Sugeneruojame ir iðvedame atsitiktinius skaièius
    for (int i = 0; i < kiek; ++i) {
        int atsitiktinis = rand() % maksimumas + minimumas;
        cout << atsitiktinis;

        // Atskiriamas kableliu, jei dar ne paskutinis skaièius
        if (i < kiek - 1) {
            cout << ", ";
        }
    }

    cout << endl;
}

int main() {

    // Iðkvieèiame funkcijà su nurodytais parametrais
    generuotiAtsitiktinius(6, 2, 89);

    return 0;
}
