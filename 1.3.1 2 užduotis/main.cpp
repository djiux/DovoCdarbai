#include <iostream>
#include <fstream>

const char failas[] = "skaiciu_seka.txt";

using namespace std;

// Function to generate a number sequence and write it to a file
void generuotiIrIrasymas(int dydis) {
    ofstream fl(failas);

    if (!fl) {
        cout << "Klaida atidarant failà!" << endl;
        return;
    }

    // Generate a number sequence and write it to the file
    for (int i = 1; i <= dydis; ++i) {
        fl << i << " ";
    }

    fl.close();
}

// Function to read a number sequence from a file and print it to the screen
void skaitytiIrIsvedimas() {
    ifstream fl(failas);

    if (!fl) {
        cout << "Klaida atidarant failà!" << endl;
        return;
    }

    int skaicius;

    // Read the number sequence from the file and print it to the screen
    while (fl >> skaicius) {
        cout << skaicius << "  ";
    }

    fl.close();
}

int main() {
    // Generate and write a number sequence to the file
    generuotiIrIrasymas(10);

    // Read the number sequence from the file and print it to the screen
    skaitytiIrIsvedimas();

    return 0;
}
