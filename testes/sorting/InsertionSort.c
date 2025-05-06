// kompleksitas waktu = O(n^2)
//   Best case = sudah terurut dari depan ke belakang
//   worst case = terurut terbalik dari besar ke kecil
#include <stdio.h>

// Fungsi untuk melakukan insertion sort
void insertionSort(int arr[], int n)
{
    int i, j, key;

    // Mulai dari elemen kedua (indeks 1), karena elemen pertama sudah dianggap terurut
    for (i = 1; i < n; i++)
    {
        key = arr[i]; // Elemen yang akan dipasang di posisi yang benar
        j = i - 1;

        // Geser elemen yang lebih besar ke kanan untuk memberi ruang bagi elemen 'key'
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j]; // Geser elemen ke kanan
            j = j - 1;
        }

        // Tempatkan 'key' di posisi yang benar
        arr[j + 1] = key;
    }
}

int main()
{
    int data[] = {12, 11, 13, 5, 6};
    int size = sizeof(data) / sizeof(data[0]);

    printf("Array sebelum diurutkan:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");

    insertionSort(data, size);

    printf("Array setelah diurutkan:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}
