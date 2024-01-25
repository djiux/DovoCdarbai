#include <iostream>
#include <string>

using namespace std;

// Funkcija apskliaudþia duotà þodá dviem brûkðniukais ið kiekvieno ðono
string apskliaustiZodi(string zodis) {
    return "-- " + zodis + " --";
}

int main() {
    // Iðvedame rezultatà kviesdami funkcijà su kiekvienu þodþiu
    cout << apskliaustiZodi("pomidoras") << endl;
    cout << apskliaustiZodi("obuolys") << endl;
    cout << apskliaustiZodi("stalas") << endl;
    cout << apskliaustiZodi("kompaktiskas") << endl;
    cout << apskliaustiZodi("programavimas") << endl;

    return 0;
}
