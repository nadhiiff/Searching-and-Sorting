// Kompleksitas waktu = O(n)
//     Best case = sudah terurut dari depan ke belakang
//     worst case = array sangat teracak
#include <stdio.h>

// Fungsi untuk mendapatkan digit yang sedang diperiksa (dari posisi tertentu)
int getDigit(int num, int digitPlace)
{
    return (num / digitPlace) % 10;
}

// Fungsi untuk melakukan counting sort berdasarkan digit tertentu
void countingSort(int arr[], int n, int digitPlace)
{
    int output[n];       // Array output untuk menyimpan hasil pengurutan
    int count[10] = {0}; // Array untuk menghitung frekuensi digit (0-9)

    // Hitung frekuensi digit yang ada di posisi tertentu
    for (int i = 0; i < n; i++)
    {
        int digit = getDigit(arr[i], digitPlace);
        count[digit]++;
    }

    // Ubah count[] menjadi posisi elemen yang benar
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // Bangun output[] dengan elemen-elemen yang terurut
    for (int i = n - 1; i >= 0; i--)
    {
        int digit = getDigit(arr[i], digitPlace);
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Salin output[] ke arr[], sehingga arr[] menjadi terurut berdasarkan digit tersebut
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

// Fungsi utama untuk melakukan radix sort
void radixSort(int arr[], int n)
{
    // Cari angka terbesar di array untuk mengetahui jumlah digit yang diperlukan
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    // Lakukan counting sort untuk setiap digit mulai dari tempat paling rendah (1an)
    for (int digitPlace = 1; max / digitPlace > 0; digitPlace *= 10)
    {
        countingSort(arr, n, digitPlace);
    }
}

int main()
{
    int data[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int size = sizeof(data) / sizeof(data[0]);

    printf("Array sebelum diurutkan:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");

    radixSort(data, size);

    printf("Array setelah diurutkan:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}
