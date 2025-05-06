/*Buat program ATM sederhana dengan fitur: cek saldo, tarik tunai, dan setor tunai.
Gunakan fungsi untuk mengecek saldo dan melakukan perhitungan setelah transaksi.
Gunakan prosedur untuk menampilkan menu dan hasil transaksi.
Simpan saldo sebagai variabel global atau parameter yang diperbarui dalam setiap transaksi.*/
#include <stdio.h>

float saldo = 500000; // Saldo awal

// Fungsi untuk mengecek saldo
float cek_saldo()
{
    return saldo;
}

// Fungsi untuk melakukan tarik tunai
int tarik_tunai(float jumlah)
{
    if (jumlah <= saldo)
    {
        saldo -= jumlah;
        return 1; // Transaksi berhasil
    }
    return 0; // Transaksi gagal (saldo tidak cukup)
}

// Fungsi untuk melakukan setor tunai
void setor_tunai(float jumlah)
{
    saldo += jumlah;
}

// Prosedur untuk menampilkan menu
void tampilkan_menu()
{
    printf("\n=== Menu ATM ===\n");
    printf("1. Cek Saldo\n");
    printf("2. Tarik Tunai\n");
    printf("3. Setor Tunai\n");
    printf("4. Keluar\n");
    printf("================\n");
}

// Prosedur untuk menampilkan hasil transaksi
void tampilkan_hasil_transaksi(int pilihan, float jumlah)
{
    if (pilihan == 1)
    {
        printf("Saldo Anda saat ini: Rp %.2f\n", cek_saldo());
    }
    else if (pilihan == 2)
    {
        if (tarik_tunai(jumlah))
        {
            printf("Tarik tunai berhasil! Saldo Anda sekarang: Rp %.2f\n", cek_saldo());
        }
        else
        {
            printf("Saldo tidak cukup untuk tarik tunai!\n");
        }
    }
    else if (pilihan == 3)
    {
        setor_tunai(jumlah);
        printf("Setor tunai berhasil! Saldo Anda sekarang: Rp %.2f\n", cek_saldo());
    }
}

// Program utama
int main()
{
    int pilihan;
    float jumlah;
    while (1)
    {
        tampilkan_menu();
        printf("Pilih menu (1/2/3/4): ");
        scanf("%d", &pilihan);

        if (pilihan == 1)
        {
            tampilkan_hasil_transaksi(1, 0);
        }
        else if (pilihan == 2)
        {
            printf("Masukkan jumlah yang ingin ditarik: Rp ");
            scanf("%f", &jumlah);
            tampilkan_hasil_transaksi(2, jumlah);
        }
        else if (pilihan == 3)
        {
            printf("Masukkan jumlah yang ingin disetor: Rp ");
            scanf("%f", &jumlah);
            tampilkan_hasil_transaksi(3, jumlah);
        }
        else if (pilihan == 4)
        {
            printf("Terima kasih telah menggunakan ATM kami!\n");
            break;
        }
        else
        {
            printf("Pilihan tidak valid! Silakan coba lagi.\n");
        }
    }
    return 0;
}
