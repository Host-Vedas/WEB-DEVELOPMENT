#include <iostream>
#include <graphics.h>
#include <cmath>

// Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Function to draw a pixel on the screen
void setPixel(SDL_Renderer* renderer, int x, int y) {
    SDL_RenderDrawPoint(renderer, x, y);
}

// Function to draw a circle
void drawCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius) {
    // Mid-point circle drawing algorithm
    int x = radius;
    int y = 0;
    int radiusError = 1 - x;

    while (x >= y) {
        setPixel(renderer, x + centerX, y + centerY);
        setPixel(renderer, y + centerX, x + centerY);
        setPixel(renderer, -x + centerX, y + centerY);
        setPixel(renderer, -y + centerX, x + centerY);
        setPixel(renderer, -x + centerX, -y + centerY);
        setPixel(renderer, -y + centerX, -x + centerY);
        setPixel(renderer, x + centerX, -y + centerY);
        setPixel(renderer, y + centerX, -x + centerY);

        y++;

        if (radiusError < 0)
            radiusError += 2 * y + 1;
        else {
            x--;
            radiusError += 2 * (y - x + 1);
        }
    }
}

int main() {
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create window
    window = SDL_CreateWindow("Circle Drawing", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Set renderer color
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    // Clear the renderer
    SDL_RenderClear(renderer);

    // Set drawing color to black
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    // Draw circle
    drawCircle(renderer, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 100);

    // Update screen
    SDL_RenderPresent(renderer);

    // Wait for user to close the window
    bool quit = false;
    SDL_Event e;
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }
    }

    // Cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

