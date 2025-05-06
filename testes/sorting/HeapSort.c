// Kompleksitas waktu = O(nlogn)
//  Best case = sudah terurut dari depan ke belakang
//  worst case = terurut terbalik dari besar ke kecil
#include <stdio.h>

// Fungsi untuk melakukan heapify (menjaga sifat heap pada pohon)
void heapify(int arr[], int n, int i)
{
    int largest = i;       // Asumsikan akar adalah yang terbesar
    int left = 2 * i + 1;  // Indeks anak kiri
    int right = 2 * i + 2; // Indeks anak kanan

    // Jika anak kiri lebih besar dari akar
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    // Jika anak kanan lebih besar dari akar atau anak kiri
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    // Jika akar tidak terbesar, tukar dengan anak terbesar dan lakukan heapify pada sub-tree
    if (largest != i)
    {
        // Tukar arr[i] dengan arr[largest]
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Lakukan heapify rekursif pada sub-tree
        heapify(arr, n, largest);
    }
}

// Fungsi utama untuk mengurutkan array menggunakan Heap Sort
void heapSort(int arr[], int n)
{
    // Membangun heap (membangun max heap dari bawah ke atas)
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // Mengambil elemen terbesar (akar) dari heap dan tempatkan di posisi akhir array
    for (int i = n - 1; i > 0; i--)
    {
        // Tukar elemen pertama (akar) dengan elemen terakhir
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Lakukan heapify pada heap yang telah diperkecil
        heapify(arr, i, 0);
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

    heapSort(data, size);

    printf("Array setelah diurutkan:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}
