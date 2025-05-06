// kompleksitas waktu = O(n^2)
//   Best case = sudah terurut dari depan ke belakang
//   worst case = terurut terbalik dari besar ke kecil
#include <stdio.h>

// Fungsi untuk melakukan selection sort
void selectionSort(int arr[], int n)
{
    int i, j, minIdx, temp;

    // Loop untuk setiap elemen dalam array
    for (i = 0; i < n - 1; i++)
    {
        minIdx = i; // Asumsi elemen pertama adalah yang terkecil

        // Cari elemen terkecil di sisa array
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j; // Update indeks terkecil
            }
        }

        // Tukar elemen terkecil dengan elemen yang ada di posisi i
        if (minIdx != i)
        {
            temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
}

int main()
{
    int data[] = {64, 25, 12, 22, 11};
    int size = sizeof(data) / sizeof(data[0]);

    printf("Array sebelum diurutkan:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");

    selectionSort(data, size);

    printf("Array setelah diurutkan:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}
