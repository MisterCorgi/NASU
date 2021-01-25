#include <SDL2/SDL.h>

int main(int argc, char *argv[])
{
    const int WIDTH = 400;
    const int HEIGHT = 400;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("NASU Window",
        0, 0, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

    /* Game loop */
    bool quit = false;
    while (! quit) {
        /* Event handling */
        SDL_Event ev;
        while (SDL_PollEvent(&ev)) {
            switch (ev.type) {
                case SDL_QUIT: {
                    quit = true;
                } break;
                case SDL_KEYDOWN: {
                    switch (ev.key.keysym.sym) {
                        case SDLK_ESCAPE: {
                            quit = true;
                        } break;
                    }
                } break;
            }
        }

        /* Clear screen with black */
        SDL_Surface *canvas = SDL_GetWindowSurface(window);
        SDL_FillRect(canvas, NULL, 0x000000);
        SDL_UpdateWindowSurface(window);

        /* Muh 60 FPS */
        SDL_Delay(17);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
