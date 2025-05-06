// kompleksitas waktu = O(n)
// best case = nilai yang dicari ada di array paing awal
// worst case = nilai yang dicari ada di array paling akhir atau tidak ada
#include <stdio.h>

// Fungsi linearSearch mencari target dalam array
int linearSearch(int arr[], int n, int target)
{
    // Lakukan iterasi dari indeks 0 sampai n-1
    for (int i = 0; i < n; i++)
    {
        // Jika elemen saat ini sama dengan target, return indeks
        if (arr[i] == target)
        {
            return i;
        }
    }
    // Jika target tidak ditemukan, return -1
    return -1;
}

int main()
{
    // Contoh array (tidak harus terurut)
    int data[] = {7, 2, 19, 4, 8, 5, 12};
    int size = sizeof(data) / sizeof(data[0]); // Menghitung jumlah elemen
    int target = 8;

    // Memanggil fungsi linearSearch
    int result = linearSearch(data, size, target);

    // Menampilkan hasil
    if (result != -1)
    {
        printf("Elemen ditemukan di indeks: %d\n", result);
    }
    else
    {
        printf("Elemen tidak ditemukan dalam array.\n");
    }

    return 0;
}
