#include <graphics.h>
#include <conio.h>

void drawBrick(int x, int y) {
    setfillstyle(SOLID_FILL, BROWN);
    bar(x, y, x + 40, y + 40);
    setcolor(WHITE);
    rectangle(x, y, x + 40, y + 40);
}

void drawGround(int width, int height) {
    setfillstyle(SOLID_FILL, GREEN);
    bar(0, height - 50, width, height);
}

void drawMario(int x, int y) {
    setfillstyle(SOLID_FILL, RED);
    fillellipse(x, y, 10, 10); // Head
    setfillstyle(SOLID_FILL, BLUE);
    bar(x - 8, y + 10, x + 8, y + 30); // Body
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int width = getmaxx();
    int height = getmaxy();

    cleardevice();
    drawGround(width, height);

    // Draw bricks
    for (int i = 100; i <= 300; i += 50) {
        drawBrick(i, height - 150);
    }

    // Draw Mario
    drawMario(50, height - 60);

    getch();
    closegraph();
    return 0;
}
