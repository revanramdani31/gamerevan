#include <graphics.h>
#include <conio.h>
#include <iostream>

using namespace std;

int main() {
    // Inisialisasi mode grafik
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x = 50, y = 200;  // Posisi awal kotak
    int size = 50;        // Ukuran kotak

    for (int i = 0; i < 300; i += 5) {
        cleardevice();  // Bersihkan layar sebelum menggambar ulang

        // Gambar kotak
        rectangle(x + i, y, x + size + i, y + size);

        delay(50);  // Jeda animasi
    }

    getch();      // Tunggu input sebelum keluar
    closegraph(); // Tutup mode grafik
    return 0;
}
