#include <stdio.h>

int elemanlar[10][2];

int bas = -1;
int kuyruk = -1;
int liste = 0;

void sonaEkle(int veri) {
    int suanki = liste;
    liste = elemanlar[suanki][0];

    elemanlar[suanki][0] = -1;
    elemanlar[suanki][1] = veri;

    if (bas == -1)
    {
        bas = suanki;
    }
    else
    {
        elemanlar[kuyruk][0] = suanki;
    }
    kuyruk = suanki;
}

void arayaEkle(int indeks, int veri) {

    int suanki = bas;
    int i;

    for (i = 0; i < indeks - 1; i++)
    {
        suanki = elemanlar[suanki][0];
    }

    int yeniEleman = liste;
    liste = elemanlar[yeniEleman][0];

    elemanlar[yeniEleman][0] = elemanlar[suanki][0];
    elemanlar[yeniEleman][1] = veri;

    elemanlar[suanki][0] = yeniEleman;

    if (kuyruk == suanki)
    {
        kuyruk = yeniEleman;
    }
}

void sil(int veri) {
    int suanki = bas;
    int onceki = -1;

    while (elemanlar[suanki][1] != veri)
    {
        onceki = suanki;
        suanki = elemanlar[suanki][0];
    }
    if (onceki == -1)
    {
        bas = elemanlar[suanki][0];
    }
    else
    {
        elemanlar[onceki][0] = elemanlar[suanki][0];
    }
    if (kuyruk == suanki)
    {
        kuyruk = onceki;
    }

    elemanlar[suanki][0] = liste;
    liste = suanki;
}

void listeyiYazdir() {
    int suanki = bas;
    while (suanki != -1)
    {
        printf("%d ", elemanlar[suanki][1]);
        suanki = elemanlar[suanki][0];
    }
    printf("\n");
}

int main() {
    int i;
    for (i = 0; i < 10 - 1; i++)
    {
        elemanlar[i][0] = i + 1;
    }
    elemanlar[10 - 1][0] = -1;

    sonaEkle(1);
    sonaEkle(2);
    sonaEkle(3);
    sonaEkle(4);
    sonaEkle(5);
    sonaEkle(6);
    sonaEkle(8);
    sonaEkle(9);
    sonaEkle(10);
    listeyiYazdir();

    arayaEkle(6, 7);
    listeyiYazdir();

    sil(8);
    listeyiYazdir();

    return 0;
};
