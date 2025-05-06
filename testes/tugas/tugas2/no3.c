/*Misalkan karyawan PT “ABC” digaji berdasarkan jumlah jam kerjanya selama seminggu.Upah per jam misalkan Rp 2000.
 Bila jumlah jam kerja lebih besar dari 48 jam, makasisanya dianggap sebagai jam lembur.
 Upah lembur misalkan RP 3000/jam. Tulislah algoritma (flowchart, pseudocode atau notasi kalimat deskriptif)
 yang membaca jumlah jam kerja seorang karyawan selama seminggu lalu menentukan upah mingguaannya! */
#include <stdio.h>
int main()
{
    int jam_kerja;
    int upah_per_jam = 2000;
    int upah_lembur_per_jam = 3000;
    int upah_mingguan;
    // Input jumlah jam kerja
    printf("Masukkan jumlah jam kerja selama seminggu: ");
    scanf("%d", &jam_kerja);
    // Menentukan upah mingguan
    if (jam_kerja <= 48)
    {
        upah_mingguan = jam_kerja * upah_per_jam;
    }
    else
    {
        int upah_normal = 48 * upah_per_jam;
        int jam_lembur = jam_kerja - 48;
        int upah_lembur = jam_lembur * upah_lembur_per_jam;
        upah_mingguan = upah_normal + upah_lembur;
    }
    printf("Upah Mingguan: Rp %d\n", upah_mingguan);
    return 0;
}
