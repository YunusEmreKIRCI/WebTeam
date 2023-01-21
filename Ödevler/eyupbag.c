#include <stdio.h> // Bu kütüphaneyi dahil etmelisiniz
#include <string.h> // Bu kütüphaneyi de dahil etmelisiniz

int main()
{
    // Kullanýcýdan bir cümle almak için bir karakter dizisi oluþturuyoruz
    char sentence[256];

    // Kullanýcýdan cümleyi almak için printf() fonksiyonunu kullanýyoruz
    printf("Lütfen bir cümle girin: ");

    // Kullanýcýdan girilen cümleyi almak için scanf() fonksiyonunu kullanýyoruz
    scanf("%[^\n]s", sentence);

    // Alýnan cümleyi ekrana yazdýrmak için printf() fonksiyonunu kullanýyoruz
    printf("Girdiðiniz cümle: %s\n", sentence);

    // Alýnan cümleyi söylemek için strlen() fonksiyonunu kullanýyoruz
    for (int i = 0; i < strlen(sentence); i++)
    {
        // Her karakteri tek tek ekrana yazdýrmak için printf() fonksiyonunu kullanýyoruz
        printf("%c", sentence[i]);

        // Her karakter arasýnda bir süre beklemek için usleep() fonksiyonunu kullanýyoruz
        usleep(100000); // 100000 microsecond = 0.1 second
    }

    // Bir satýr sonu eklemek için printf() fonksiyonunu kullanýyoruz
    printf("\n");

    return 0;
}
