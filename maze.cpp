#include <graphics.h>
#include <conio.h>
#include <iostream>

using namespace std;

// Ukuran labirin
const int ROWS = 10;
const int COLS = 10;
const int CELL_SIZE = 50; // Ukuran kotak

// Representasi labirin dengan array 2D
int maze[ROWS][COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 1, 1, 1, 0, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

// Posisi awal pemain
int playerX = 1, playerY = 1;

// Fungsi menggambar labirin
void drawMaze() {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            int x = col * CELL_SIZE;
            int y = row * CELL_SIZE;

            if (maze[row][col] == 1) { // Dinding
                setfillstyle(SOLID_FILL, BLUE);
                bar(x, y, x + CELL_SIZE, y + CELL_SIZE);
            } else { // Jalan
                setfillstyle(SOLID_FILL, BLACK);
                bar(x, y, x + CELL_SIZE, y + CELL_SIZE);
            }
        }
    }
}

// Fungsi menggambar pemain
void drawPlayer() {
    int x = playerX * CELL_SIZE;
    int y = playerY * CELL_SIZE;
    setfillstyle(SOLID_FILL, RED);
    fillellipse(x + CELL_SIZE / 2, y + CELL_SIZE / 2, CELL_SIZE / 3, CELL_SIZE / 3);
}

int main() {
    // Inisialisasi grafik
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    while (true) {
        cleardevice(); // Bersihkan layar

        drawMaze();    // Gambar labirin
        drawPlayer();  // Gambar pemain

        delay(100); // Jeda animasi

        // Cek input keyboard
        if (kbhit()) {
            char key = getch();
            int newX = playerX, newY = playerY;

            if (key == 27) break;        // ESC untuk keluar
            else if (key == 72) newY--;  // Panah atas
            else if (key == 80) newY++;  // Panah bawah
            else if (key == 75) newX--;  // Panah kiri
            else if (key == 77) newX++;  // Panah kanan

            // Cek apakah bisa bergerak (bukan dinding)
            if (maze[newY][newX] == 0) {
                playerX = newX;
                playerY = newY;
            }
        }
    }

    closegraph();
    return 0;
}
