/*#include <stdio.h>
#include <stdlib.h>

int main()
{
    srand(time(0));
    int arr[10][10];

    int bir_sayilari[10];

    int max_sutun_1 = 0;
    int max_sutun_2 = 0;

    int max_index_1 = 0;
    int max_index_2 = 0;

    int denk_gelis = 0;
    int bir_sayisi = 0;

    for(int i = 0;i<10;i++) {
        for(int j = 0;j<10;j++) {
            arr[i][j] = rand()%2;
        }
    }

    for(int i = 0;i<10;i++) {
        bir_sayisi = 0;
        for(int j = 0;j<10;j++) {
            if(arr[j][i]==1) {
                bir_sayisi++;
            }
        }
        bir_sayilari[i] = bir_sayisi;
    }

    for(int i = 0;i<10;i++) {
        for(int j = 0;j<10;j++) {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("-------------------\n");

    for(int i = 0;i<10;i++) {
        printf("%d ",bir_sayilari[i]);
    }

    for(int i = 0;i<10;i++) {
        if(bir_sayilari[i]>=max_sutun_1) {
            max_index_1 = i;
            max_sutun_1 = bir_sayilari[i];
        }
    }

    for(int i = 0;i<10;i++) {
        if(i!=max_index_1) {
            if(bir_sayilari[i]>=max_sutun_2) {
                max_index_2 = i;
                max_sutun_2 = bir_sayilari[i];
            }
        }
    }

    printf("\n\n%d ve %d 1'in en fazla bulunma sayilari",max_sutun_1,max_sutun_2);
    printf("\n\n%d ve %d 1'in en fazla bulundugu sutunlarin indexleri\n",max_index_1,max_index_2);

    for(int i = 0;i<10;i++) {
        if(arr[i][max_index_1]==1 && arr[i][max_index_2]==1) {
            denk_gelis++;
            printf("\n%d. satirda denk gelmis\n",i+1);
        }
    }
    printf("\n\n%d kez denk gelmis.\n\n\n",denk_gelis);

    return 0;
}*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    srand(time(0));

    int **arr = (int **)calloc(10,sizeof(int *));
    int *bir_sayilari = (int *)calloc(10,sizeof(int));
    int *sutuns = (int *)calloc(2,sizeof(int));
    int *indexes = (int *)calloc(2,sizeof(int));
    int *denklik = (int *)calloc(2,sizeof(int));

    for(int i = 0;i<10;i++) {
        arr[i] = (int *)malloc(10 * sizeof(int));
    }

    for(int i = 0;i<2;i++){
        sutuns[i] = i;
        indexes[i] = i;
    }


    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++)   {
            *(*(arr + i) + j) = rand()%2;
        }
    }

    for(int i = 0;i<10;i++) {
        denklik[1] = 0;
        for(int j = 0;j<10;j++) {
            if(arr[j][i]==1) {
                denklik[1]++;
            }
        }
        bir_sayilari[i] = denklik[1];
    }

    for(int i = 0;i<10;i++) {
        for(int j = 0;j<10;j++) {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("-------------------\n");

    for(int i = 0;i<10;i++) {
        printf("%d ",bir_sayilari[i]);
    }

    for(int i = 0;i<10;i++) {
        if(bir_sayilari[i]>=sutuns[0]) {
            indexes[0] = i;
            sutuns[0] = bir_sayilari[i];
        }
    }

    for(int i = 0;i<10;i++) {
        if(i!=indexes[0]) {
            if(bir_sayilari[i]>=sutuns[1]) {
                indexes[1] = i;
                sutuns[1] = bir_sayilari[i];
            }
        }
    }

    printf("\n\n%d ve %d 1'in en fazla bulunma sayilari",sutuns[0],sutuns[1]);
    printf("\n\n%d ve %d 1'in en fazla bulundugu sutunlarin indexleri\n",indexes[0],indexes[1]);

    for(int i = 0;i<10;i++) {
        if(arr[i][indexes[0]]==1 && arr[i][indexes[1]]==1) {
            denklik[0]++;
            printf("\n%d. satirda denk gelmis\n",i+1);
        }
    }
    printf("\n\n%d kez denk gelmis.\n\n\n",denklik[0]);

    free(arr);
    free(bir_sayilari);
    free(sutuns);
    free(indexes);
    free(denklik);


    return 0;
}

