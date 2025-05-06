// kompleksitas waktu = O(logn)
// best case = nilaii yang dicari ada di tengah
// worst case = nilai yand dicari ada di ujung kanan atau kiri atau tidak ada
#include <stdio.h>

// Fungsi untuk mencari nilai terkecil dari dua bilangan
int min(int a, int b);

int main()
{
    // Array yang sudah terurut untuk pencarian
    int arr[] = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100};

    // Menghitung panjang array
    int n = sizeof(arr) / sizeof(arr[0]);
    int x; // Variabel untuk menyimpan nilai yang dicari

    // Menampilkan array ke pengguna
    printf("Array: 10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100\n");

    // Meminta input nilai yang ingin dicari
    printf("Masukkan nilai yang ingin dicari: ");
    scanf("%d", &x);

    // Memanggil fungsi Fibonacci Search
    int result = fibonacciSearch(arr, n, x);

    // Menampilkan hasil pencarian
    if (result == -1)
    {
        printf("Elemen %d tidak ditemukan\n", x);
    }
    else
    {
        printf("Elemen %d ditemukan pada indeks %d\n", x, result);
    }

    return 0;
}

// Fungsi Fibonacci Search untuk mencari nilai dalam array terurut
int fibonacciSearch(int arr[], int n, int x)
{
    // Inisialisasi bilangan Fibonacci
    int fibMMm2 = 0;              // Fibonacci(m-2)
    int fibMMm1 = 1;              // Fibonacci(m-1)
    int fibM = fibMMm2 + fibMMm1; // Fibonacci(m)

    // Mencari bilangan Fibonacci terkecil yang >= panjang array
    while (fibM < n)
    {
        fibMMm2 = fibMMm1;        // Update fib(m-2)
        fibMMm1 = fibM;           // Update fib(m-1)
        fibM = fibMMm2 + fibMMm1; // Hitung fib(m) baru
    }

    // Penanda area yang sudah dieliminasi
    int offset = -1;

    // Proses pencarian utama
    while (fibM > 1)
    {
        // Menghitung indeks yang akan diperiksa
        int i = min(offset + fibMMm2, n - 1);

        if (arr[i] < x)
        {
            // Jika nilai di indeks lebih kecil, cari di bagian kanan
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i; // Geser offset ke kanan
        }
        else if (arr[i] > x)
        {
            // Jika nilai di indeks lebih besar, cari di bagian kiri
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
        else
        {
            // Jika nilai ditemukan persis
            return i;
        }
    }

    // Pengecekan elemen terakhir
    if (fibMMm1 && arr[offset + 1] == x)
    {
        return offset + 1;
    }

    // Jika nilai tidak ditemukan
    return -1;
}

// Implementasi fungsi min
int min(int a, int b)
{
    // Mengembalikan nilai yang lebih kecil
    return (a <= b) ? a : b;
}
