#include <stdio.h>
#include <SDL2/SDL.h>

int main(int argc, char *argv[]) {
    SDL_Window *window; // ventana
    SDL_Renderer *renderer; // renderizador
    SDL_Rect rect; // rectángulo
    int x = 0; // posición x del rectángulo
    int y = 0; // posición y del rectángulo
    int speed = 10; // velocidad del rectángulo

    //inicializa SDL
    SDL_Init(SDL_INIT_VIDEO);

    // crea la ventana
    window = SDL_CreateWindow("Mi aplicación", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);

    //renderizador
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    //rectángulo
    rect.x = x;
    rect.y = y;
    rect.w = 50;
    rect.h = 50;

    //bucle principal
    while (1) {
        //eventos
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                goto end;
            }
        }

        //mueve el rectángulo
        x += speed;
        if (x > 640 - rect.w) {
            x = 640 - rect.w;
            speed = -10;
        } else if (x < 0) {
            x = 0;
            speed = 10;
        }
        rect.x = x;

        //dibuja el rectángulo
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &rect);

        //muestra el renderizador
        SDL_RenderPresent(renderer);

        //espera un poco
        SDL_Delay(10);
    }

    end:
    //destruye el renderizador
    SDL_DestroyRenderer(renderer);

    //destruye la ventana
    SDL_DestroyWindow(window);

    //cierra SDL
    SDL_Quit();

    return 0;
}

gcc main.c -o programa -lSDL2

./programa