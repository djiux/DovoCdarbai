#include <iostream>
#include <string>

using namespace std;

// Funkcija apskliaud�ia duot� �od� dviem br�k�niukais i� kiekvieno �ono
string apskliaustiZodi(string zodis) {
    return "-- " + zodis + " --";
}

int main() {
    // I�vedame rezultat� kviesdami funkcij� su kiekvienu �od�iu
    cout << apskliaustiZodi("pomidoras") << endl;
    cout << apskliaustiZodi("obuolys") << endl;
    cout << apskliaustiZodi("stalas") << endl;
    cout << apskliaustiZodi("kompaktiskas") << endl;
    cout << apskliaustiZodi("programavimas") << endl;

    return 0;
}
