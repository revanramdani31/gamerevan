#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define WIDTH 640
#define HEIGHT 480

// Posisi Mario
int marioX = 100;
int marioY = 400;
int obstacleX = 600;
int score = 0;

// Menggambar latar belakang dan karakter
void draw() {
    cleardevice();

    // Garis bawah (tanah)
    line(0, 420, WIDTH, 420);

    // Mario (kotak kecil sebagai pengganti sprite)
    setfillstyle(SOLID_FILL, RED);
    bar(marioX, marioY, marioX + 20, marioY + 20);

    // Rintangan (pipa atau musuh)
    setfillstyle(SOLID_FILL, GREEN);
    bar(obstacleX, 400, obstacleX + 30, 420);

    // Skor
    setcolor(WHITE);
    char scoreText[20];
    sprintf(scoreText, "Score: %d", score);
    outtextxy(10, 10, scoreText);
}

// Memperbarui posisi Mario dan rintangan
void update() {
    obstacleX -= 5; // Rintangan bergerak ke kiri

    // Jika rintangan lewat, reset dan tambahkan skor
    if (obstacleX < 0) {
        obstacleX = WIDTH;
        score++;
    }

    // Cek tabrakan
    if (marioX + 20 >= obstacleX && marioX <= obstacleX + 30 && marioY + 20 >= 400) {
        outtextxy(WIDTH / 2 - 50, HEIGHT / 2, "GAME OVER!");
        delay(3000);
        closegraph();
        exit(0);
    }
}

// Kontrol Mario
void input() {
    if (kbhit()) {
        char ch = getch();
        if (ch == 'a' && marioX > 10) {
            marioX -= 20; // Gerak kiri
        } else if (ch == 'd' && marioX < WIDTH - 30) {
            marioX += 20; // Gerak kanan
        } else if (ch == 'w' && marioY == 400) {
            // Melompat
            for (int i = 0; i < 50; i++) {
                marioY -= 2;
                draw();
                delay(5);
            }
            for (int i = 0; i < 50; i++) {
                marioY += 2;
                draw();
                delay(5);
            }
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    while (1) {
        draw();    // Gambar arena
        input();   // Ambil input
        update();  // Perbarui logika
        delay(30); // Kontrol kecepatan
    }

    closegraph();
    return 0;
}
