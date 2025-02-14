#include <graphics.h>
#include <conio.h>
#include <iostream>

using namespace std;

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x = 200, y = 200; // Posisi awal kotak
    int size = 50;        // Ukuran kotak

    while (true) {
        cleardevice();  // Bersihkan layar sebelum menggambar ulang
        
        rectangle(x, y, x + size, y + size); // Gambar kotak
        delay(50);  // Jeda agar animasi lebih halus

        // Cek input keyboard
        if (kbhit()) {
            char key = getch(); // Baca tombol yang ditekan

            // Update posisi berdasarkan tombol panah
            if (key == 27) break; // ESC untuk keluar
            else if (key == 72) y -= 10; // Panah atas
            else if (key == 80) y += 10; // Panah bawah
            else if (key == 75) x -= 10; // Panah kiri
            else if (key == 77) x += 10; // Panah kanan
        }
    }

    closegraph(); // Tutup mode grafik
    return 0;
}
