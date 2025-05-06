/*Tulislah algoritma yang membaca sebuah bilangan bulat,
lalu menentukan apakah bilangan tersebut positif, negative atau nol.
Ilustrasi algoritma menggunakan flowchart, dan buat syntax pemrogramannya! */

#include <stdio.h>
int main()
{
    int x;
    // Input bilangan
    printf("Masukkan bilangan bulat: ");
    scanf("%d", &x);

    // Menentukan apakah bilangan positif, negatif, atau nol
    if (x > 0)
    {
        printf("Bilangan Positif (+)\n");
    }
    else if (x < 0)
    {
        printf("Bilangan Negatif (-)\n");
    }
    else
    {
        printf("Bilangan sama dengan 0\n");
    }

    printf("Selesai\n");

    return 0;
}
