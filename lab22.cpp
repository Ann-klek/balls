#include "SDL.h"
#include <iostream>

using namespace std;
const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;

void Ball() {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = SDL_CreateWindow("Animation",
        100, 100,
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    int x0 = SCREEN_WIDTH / 2, y0 = SCREEN_HEIGHT / 2;
    int x01 = SCREEN_WIDTH / 2, y01 = SCREEN_HEIGHT / 2;
    int x02 = SCREEN_WIDTH / 2, y02 = SCREEN_HEIGHT / 2;
    int x03 = SCREEN_WIDTH / 2, y03 = SCREEN_HEIGHT / 2;
    int x04 = SCREEN_WIDTH / 2, y04 = SCREEN_HEIGHT / 2;
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
    SDL_RenderClear(renderer);
    double u = 3.14 / 180 * 0;
    srand(time(NULL));
    int del_x = rand() % 10 - 5;
    int del_y = rand() % 10 - 5;
    int del_x2 = rand() % 10 - 5;
    int del_y2 = rand() % 10 - 5;
    int del_x3 = rand() % 10 - 5;
    int del_y3 = rand() % 10 - 5;
    int del_x4 = rand() % 10 - 5;
    int del_y4 = rand() % 10 - 5;
    int del_x5 = rand() % 10 - 5;
    int del_y5 = rand() % 10 - 5;
    while (true) {
        int x1 = int(x0 + cos(u) * 0);
        int y1 = int(y0 - sin(u) * 0);
        int x11 = int(x01 + cos(u) * 0);
        int y11 = int(y01 - sin(u) * 0);
        int x12 = int(x02 + cos(u) * 0);
        int y12 = int(y02 - sin(u) * 0);
        int x13 = int(x03 + cos(u) * 0);
        int y13 = int(y03 - sin(u) * 0);
        int x14 = int(x04 + cos(u) * 0);
        int y14 = int(y04 - sin(u) * 0);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        for (int r = 0; r <= 10; r++) {
            for (int i = 1; i <= 360; i++) {
                double u = 3.14 / 180 * i;
                int x2 = int(x0 + cos(u) * r);
                int y2 = int(y0 - sin(u) * r);
                int x21 = int(x01 + cos(u) * r);
                int y21 = int(y01 - sin(u) * r);
                int x22 = int(x02 + cos(u) * r);
                int y22 = int(y02 - sin(u) * r);
                int x23 = int(x03 + cos(u) * r);
                int y23 = int(y03 - sin(u) * r);
                int x24 = int(x04 + cos(u) * r);
                int y24 = int(y04 - sin(u) * r);
                SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
                SDL_RenderDrawLine(renderer, x11, y11, x21, y21);
                SDL_RenderDrawLine(renderer, x12, y12, x22, y22);
                SDL_RenderDrawLine(renderer, x13, y13, x23, y23);
                SDL_RenderDrawLine(renderer, x14, y14, x24, y24);
                x1 = x2;
                y1 = y2;
                x11 = x21;
                y11 = y21;
                x12 = x22;
                y12 = y22;
                x13 = x23;
                y13 = y23;
                x14 = x24;
                y14 = y24;
            }

        }
        SDL_Delay(10);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
        if (x0 <= 10 || x0 >= SCREEN_WIDTH - 10) del_x *= -1;
        if (y0 <= 10 || y0 >= SCREEN_WIDTH - 10) del_y *= -1;
        x0 += del_x;
        y0 += del_y;
        if (x01 <= 10 || x01 >= SCREEN_WIDTH - 10) del_x2 *= -1;
        if (y01 <= 10 || y01 >= SCREEN_WIDTH - 10) del_y2 *= -1;
        x01 += del_x2;
        y01 += del_y2;
        if (x02 <= 10 || x02 >= SCREEN_WIDTH - 10) del_x3 *= -1;
        if (y02 <= 10 || y02 >= SCREEN_WIDTH - 10) del_y3 *= -1;
        x02 += del_x3;
        y02 += del_y3;
        if (x03 <= 10 || x03 >= SCREEN_WIDTH - 10) del_x4 *= -1;
        if (y03 <= 10 || y03 >= SCREEN_WIDTH - 10) del_y4 *= -1;
        x03 += del_x4;
        y03 += del_y4;
        if (x04 <= 10 || x04 >= SCREEN_WIDTH - 10) del_x5 *= -1;
        if (y04 <= 10 || y04 >= SCREEN_WIDTH - 10) del_y5 *= -1;
        x04 += del_x5;
        y04 += del_y5;
        SDL_Delay(0);
    }
    SDL_Event e;
    bool quit = false;
    while (quit == false) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) quit = true;
        }
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main(int argc, char** argv) {
    Ball();
    return 0;
}