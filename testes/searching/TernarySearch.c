// Kompleksitas waktu = O (logn)
// Best case = target ada di mid1 atau mid2
// Worst case = target ada di ujung atau tidak ada
#include <stdio.h>

// Fungsi ternarySearch mencari target dalam array terurut
int ternarySearch(int arr[], int left, int right, int target)
{
    if (left > right)
    {
        return -1; // Basis rekursi: elemen tidak ditemukan
    }

    // Hitung dua titik pembagi
    int mid1 = left + (right - left) / 3;
    int mid2 = right - (right - left) / 3;

    // Cek apakah target ada di salah satu titik
    if (arr[mid1] == target)
    {
        return mid1;
    }
    if (arr[mid2] == target)
    {
        return mid2;
    }

    // Jika target lebih kecil dari mid1, cari di bagian kiri
    if (target < arr[mid1])
    {
        return ternarySearch(arr, left, mid1 - 1, target);
    }
    // Jika target di antara mid1 dan mid2, cari di tengah
    else if (target > arr[mid1] && target < arr[mid2])
    {
        return ternarySearch(arr, mid1 + 1, mid2 - 1, target);
    }
    // Jika target lebih besar dari mid2, cari di bagian kanan
    else
    {
        return ternarySearch(arr, mid2 + 1, right, target);
    }
}

int main()
{
    int data[] = {2, 5, 8, 12, 16, 23, 38, 56, 72};
    int size = sizeof(data) / sizeof(data[0]);
    int target = 23;

    int result = ternarySearch(data, 0, size - 1, target);

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
