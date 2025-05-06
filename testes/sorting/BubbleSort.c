// Kompleksitas waktu = O(n^2)
// Best case = sudah terurut dari depan ke belakang
// worst case = terurut terbalik dari besar ke kecil
#include <stdio.h>

void bubbleSort(int arr[], int n)
{
    int i, j;
    int temp;
    int swapped;

    for (i = 0; i < n - 1; i++)
    {
        swapped = 0;

        for (j = 0; j < n - i - 1; j++)
        {
            // Tukar langsung tanpa fungsi swap
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }

        // Optimisasi: berhenti jika sudah terurut
        if (!swapped)
            break;
    }
}

int main()
{
    int data[] = {64, 25, 12, 22, 11};
    int size = sizeof(data) / sizeof(data[0]);

    printf("Sebelum diurutkan:\n");
    for (int i = 0; i < size; i++)
        printf("%d ", data[i]);
    printf("\n");

    bubbleSort(data, size);

    printf("Setelah diurutkan:\n");
    for (int i = 0; i < size; i++)
        printf("%d ", data[i]);
    printf("\n");

    return 0;
}
