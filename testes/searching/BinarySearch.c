// Kompleksiatas waktu = O(logn)
// Best case = nilai yang dicari ada di tengah
// Worst case = nilai yang dicari ada di ujung
#include <stdio.h>

// Fungsi binarySearch menerima array terurut, ukuran array, dan nilai yang dicari
int binarySearch(int arr[], int n, int target)
{
    int left = 0;
    int right = n - 1;

    // Selama bagian yang dicari masih valid (left <= right)
    while (left <= right)
    {
        // Hitung indeks tengah
        int mid = left + (right - left) / 2;

        // Jika elemen di tengah sama dengan target, return indeks
        if (arr[mid] == target)
        {
            return mid;
        }
        // Jika elemen di tengah lebih kecil dari target, cari di sebelah kanan
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        // Jika elemen di tengah lebih besar dari target, cari di sebelah kiri
        else
        {
            right = mid - 1;
        }
    }

    // Jika tidak ditemukan, return -1
    return -1;
}

int main()
{
    // Contoh array yang sudah terurut
    int data[] = {3, 6, 8, 12, 15, 18, 21, 24, 30};
    int size = sizeof(data) / sizeof(data[0]); // Menghitung jumlah elemen array
    int target = 15;

    // Memanggil fungsi binarySearch
    int result = binarySearch(data, size, target);

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
