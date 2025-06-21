#include <iostream>
using namespace std;

int N = 0;

void wyswietl(int tablica[20][2]){

    for(int i = 0; i<N; i++){
        cout<<tablica[i][0]<<" -> "<<tablica[i][1] << "\n";
    }
}
void dodaj(int tablica[20][2], int start, int end) {
    tablica[N][0] = start;
    tablica[N][1] = end;

    N++;

    tablica[N][0] = end;
    tablica[N][1] = start;

    N++;
}

int main()
{
    int tablica[20][2];

    dodaj(tablica, 1, 2);
    dodaj(tablica, 2, 3);
    dodaj(tablica, 3, 5);
    wyswietl(tablica);

    return 0;
}