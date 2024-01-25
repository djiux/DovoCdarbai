#include <iostream>

using namespace std;

// Funkcija skirta sumai
int suma(int a, int b) {
    int result = a + b;
    cout << a << " + " << b << " = " << result << endl;
    return result;
}

// Funkcija skirta skirtumui
int skirtumas(int a, int b) {
    int result = a - b;
    cout << a << " - " << b << " = " << result << endl;
    return result;
}

// Funkcija skirta sandaugai
int sandauga(int a, int b) {
    int result = a * b;
    cout << a << " * " << b << " = " << result << endl;
    return result;
}

// Funkcija skirta dalmeniui
int dalyba(int a, int b) {
    if (b == 0) {
        cout << "Dalyba iğ nulio negalima!" << endl;
        return 0;
    }
    else{
        int result = a/b;
        cout << a << " / " << b << " = " << result << endl;

    return result;
    }
}

int main() {
    // Pavyzdşiai kvieèiant funkcijas su skirtingais skaièiais
    suma(5, 7);
    skirtumas(10, 3);
    sandauga(4, 6);
    dalyba(8, 2);

    return 0;
}
