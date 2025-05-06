/*Implementasikan fungsi rekursif untuk menghitung faktorial. 
Implementasikan fungsi rekursif untuk menghitung bilangan 
Fibonacci ke-n. Gunakan prosedur untuk menampilkan hasil perhitungan.*/

#include <iostream> 
using namespace std; 

// Fungsi rekursif untuk menghitung faktorial
int faktorial(int n) { 
    if (n == 0 || n == 1) 
        return 1; 
    return n * faktorial(n - 1); 
} 

// Fungsi rekursif untuk menghitung bilangan Fibonacci ke-n
int fibonacci(int n) { 
    if (n == 0) 
        return 0; 
    if (n == 1) 
        return 1; 
    return fibonacci(n - 1) + fibonacci(n - 2); 
} 

// Prosedur untuk menampilkan menu
void tampilkan_menu() { 
    cout << "\nMenu:\n";
    cout << "1. Hitung Faktorial\n"; 
    cout << "2. Hitung Fibonacci\n"; 
    cout << "3. Keluar\n"; 
} 

// Prosedur untuk menampilkan hasil
void tampilkan_hasil(int pilihan, int n) { 
    if (pilihan == 1) { 
        cout << "Faktorial dari " << n << " adalah " << faktorial(n) << endl;  
    } else if (pilihan == 2) { 
        cout << "Bilangan Fibonacci ke-" << n << " adalah " << fibonacci(n) << endl; 
    } 
}

int main() { 
    int pilihan, n; 
  
    do { 
        tampilkan_menu(); 
        cout << "Pilih opsi: "; 
        cin >> pilihan; 
  
        if (pilihan == 1 || pilihan == 2) { 
            cout << "Masukkan nilai n: ";
            cin >> n; 
            tampilkan_hasil(pilihan, n); 
        } else if (pilihan == 3) { 
            cout << "Keluar dari program.\n";  
        } else { 
            cout << "Pilihan tidak valid, coba lagi.\n";  
        } 
    } while (pilihan != 3); 
  
    return 0; 
}
