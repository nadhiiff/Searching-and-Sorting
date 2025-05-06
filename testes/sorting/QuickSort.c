// Kompleksitas waktu = O(nlogn)

#include <stdio.h>

// Fungsi untuk melakukan partition pada array
int partition(int arr[], int low, int high)
{
    // Pilih elemen terakhir sebagai pivot
    int pivot = arr[high];
    int i = low - 1; // Indeks elemen yang lebih kecil dari pivot

    // Loop untuk membandingkan elemen dengan pivot
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++; // Increment indeks elemen kecil
            // Tukar arr[i] dengan arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Tukar elemen pivot dengan elemen setelah indeks i
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    // Kembalikan indeks pivot yang baru
    return (i + 1);
}

// Fungsi utama untuk melakukan quick sort
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // Partitioning index
        int pi = partition(arr, low, high);

        // Urutkan bagian kiri dan kanan dari pivot
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int data[] = {10, 80, 30, 90, 40, 50, 70};
    int size = sizeof(data) / sizeof(data[0]);

    printf("Array sebelum diurutkan:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");

    quickSort(data, 0, size - 1);

    printf("Array setelah diurutkan:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}
