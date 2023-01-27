#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int **a;
    int *dizi, no1, no2, enbuyuk;
    int i, j, sayac=0, satir;
    srand(time(NULL));

    a = (int **)calloc(10, sizeof(int *));

    for (i = 0; i < 10; i++)
    {
        a[i] = (int *)calloc(10, sizeof(int));
    }

    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            a[i][j] = rand() % 2;
            printf("%3d",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    dizi = (int *)calloc(10, sizeof(int));

    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            if(a[j][i] == 1)
            {
                sayac++;
            }
        }

        dizi[i] = sayac;

        printf("%d.sutun--%d tane 1\n", i+1, sayac);

        sayac = 0;
    }

    enbuyuk = dizi[0];

    for(i=0; i<10; i++)
    {
        if(dizi[i] > enbuyuk)
        {
            enbuyuk = dizi[i];
            no1 = i+1;
        }
    }

    enbuyuk = dizi[0];

    for(i=0; i<10; i++)
    {
        if(dizi[i] > enbuyuk && i != no1 - 1)
        {
            enbuyuk = dizi[i];
            no2 = i+1;
        }
    }
    printf("\nEn cok 1 sayisinin oldugu 2 sutunun numarasi: %d ve %d'dir.",no1,no2);

    for(i=0; i < 10; i++)
    {
        if(a[no1 - 1][i] == 1 && a[no2 - 1][i] == 1)
        {
            printf("%d. satirda ikisinde 1\n", i+1);
        }
    }

    for (i = 0; i < 10; i++)
    {
        free(a[i]);
    }

    free(a);
    free(dizi);

    return 0;
}
