/*Tulislah algoritma (dalam notasi pseudo-code dan kalimat deskriptif) untuk memperoleh informasi
nomor telepon berdasarkan data Alamat rumah (nama jalan dan nomornya) kepada nomor penerangan local (108)
 PT Telkom. Algoritmanya harus menjelaskan proses bila (a) nomor 108 sibuk,
 (b) Alamat yang diberikan penelepon belum mempunyai sambungan telepon.
 Setelah algoritmanya selesai, lakukan penulisan syntax pemrogramannya.*/

#include <stdio.h>
#include <string.h>
int main()
{
    char alamat[100];
    int nomor_sibuk = 0;
    int alamat_terdaftar = 1;
    char nomor_telepon[15] = "021-12345678"; // Contoh nomor telepon
    // Pengguna menghubungi nomor 108
    printf("Penelepon menghubungi nomor 108...\n");
    // Jika nomor 108 sibuk
    if (nomor_sibuk == 1)
    {
        printf("Nomor 108 sedang sibuk, coba lagi setelah beberapa menit.\n");
        printf("Tunggu 5 menit...\n");
    }
    else
    {
        // Jika nomor 108 tidak sibuk
        printf("Nomor 108 tidak sibuk. Masukkan alamat rumah: ");
        fgets(alamat, sizeof(alamat), stdin); // Input alamat  alamat[strcspn(alamat, "\n")] = 0; // Menghapus newline di akhir input
        // Cek apakah alamat terdaftar
        if (alamat_terdaftar == 0)
        {
            printf("Alamat yang Anda berikan belum memiliki sambungan telepon.\n");
        }
        else
        {
            // Jika alamat terdaftar, cari nomor telepon dan tampilkan  printf("Nomor telepon untuk alamat %s adalah: %s\n", alamat, nomor_telepon);
        }
    }
    printf("Sambungan diputus\n");
    printf("Selesai\n");

    return 0;
}
