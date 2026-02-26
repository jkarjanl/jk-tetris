#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool running;
} App;

bool init(App *app) {

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "SDL_Init failed: %s\n", SDL_GetError());
        return false;
    }

    app->window = SDL_CreateWindow(
        "jk-tetris",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        800, 600,
        SDL_WINDOW_SHOWN
    );

    if (!app->window) {
        printf("CreateWindow Error: %s\n", SDL_GetError());
        return false;
    }

    app->renderer = SDL_CreateRenderer(app->window, -1, SDL_RENDERER_ACCELERATED);
    if (!app->renderer) {
        printf("CreateRenderer Error: %s\n", SDL_GetError());
        return false;
    }

    app->running = true;

    return true;
}

void run(App *app) {

    SDL_Event event;

    while (app->running) {

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                app->running = false;
            }
        }

        SDL_SetRenderDrawColor(app->renderer, 0, 0, 0, 255);
        SDL_RenderClear(app->renderer);

        SDL_RenderPresent(app->renderer);
    }
}

void cleanup(App *app) {
    SDL_DestroyRenderer(app->renderer);
    SDL_DestroyWindow(app->window);
    SDL_Quit();
}

int main(void) {

    App app;

    if (!init(&app)) {
        return 1;
    }

    run(&app);
    cleanup(&app);

    return 0;
}
