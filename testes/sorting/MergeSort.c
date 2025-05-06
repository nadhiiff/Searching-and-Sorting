// Kompleksitas waktu = O(nlogn)
//    Best case = sudah terurut dari depan ke belakang
//    worst case = terurut terbalik dari besar ke kecil
#include <stdio.h>

// Fungsi untuk menggabungkan dua sub-array yang sudah terurut
void merge(int arr[], int left, int mid, int right)
{
    // Ukuran dua sub-array
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Membuat array sementara untuk dua sub-array
    int leftArr[n1], rightArr[n2];

    // Salin data ke dalam array sementara
    for (int i = 0; i < n1; i++)
    {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        rightArr[j] = arr[mid + 1 + j];
    }

    // Gabungkan dua array sementara ke dalam array asli
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Salin elemen yang tersisa, jika ada
    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Fungsi utama untuk melakukan merge sort
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        // Temukan titik tengah
        int mid = left + (right - left) / 2;

        // Urutkan bagian kiri dan kanan secara rekursif
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Gabungkan kedua bagian yang sudah terurut
        merge(arr, left, mid, right);
    }
}

int main()
{
    int data[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(data) / sizeof(data[0]);

    printf("Array sebelum diurutkan:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");

    mergeSort(data, 0, size - 1);

    printf("Array setelah diurutkan:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}
