#include <stdio.h>

// Funkcja minColIdx (dostosowana do szukania w konkretnej kolumnie)
int minColIdx(int n, int m, int target_col, int tab[n][m]) {
    // Zabezpieczenie przed podaniem nieprawid³owego indeksu kolumny
    if (target_col < 0 || target_col >= m) {
        printf("Blad: Nieprawidlowy indeks kolumny.\n");
        return -1;
    }

    int min_val = tab[0][target_col];
    int min_row_idx = 0;

    // Przeszukujemy tylko wskazan¹ kolumnê (od góry do do³u)
    for (int i = 1; i < n; i++) {
        if (tab[i][target_col] < min_val) {
            // Znaleziono mniejsz¹ wartoœæ, aktualizujemy minimum i indeks wiersza
            min_val = tab[i][target_col];
            min_row_idx = i;
        }
        // Uwaga: W przypadku równoœci (tab[i][target_col] == min_val)
        // celowo nie zmieniamy zapisanego min_row_idx.
        // Poniewa¿ pêtla idzie od wiersza 0 w dó³, pierwsze znalezisko
        // automatycznie ma najmniejszy mo¿liwy indeks.
    }

    // Zwracamy indeks wiersza, w którym jest najmniejszy element
    return min_row_idx;
}

int main() {
    // Przypadek testowy
    int n = 4; // liczba wierszy
    int m = 3; // liczba kolumn
    int badana_kolumna = 1; // Szukamy w kolumnie o indeksie 1 (œrodkowa kolumna)

    // Inicjalizacja dwuwymiarowej tablicy
    int tablica[4][3] = {
        {9, 5, 2},
        {1, 8, 3},
        {4, 2, 7},  // Najmniejszy element w kolumnie 1 to '2' (indeks wiersza 2)
        {6, 2, 5}   // Tu równie¿ jest '2', ale ma wiêkszy indeks wiersza (3)
    };

    int wynik = minColIdx(n, m, badana_kolumna, tablica);

    printf("Przeszukujemy kolumne o indeksie %d.\n", badana_kolumna);

    if (wynik != -1) {
        printf("Najmniejszy element (o wartosci %d) znajduje sie w wierszu o indeksie: %d\n",
               tablica[wynik][badana_kolumna], wynik);
    }

    return 0;
}
