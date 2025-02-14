#include <graphics.h>
#include <conio.h>

int main() {
    // Inisialisasi mode grafik
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Gambar lingkaran di tengah layar
    circle(340, 240, 50);

    // Tahan layar agar tidak langsung tertutup
    getch();
    
    // Tutup mode grafik
    closegraph();
    return 0;
}
