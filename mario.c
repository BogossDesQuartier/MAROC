#include <SDL2/SDL.h>
#include <stdbool.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define GRAVITY 0.5f
#define JUMP_FORCE -10.0f
#define SPEED 5

typedef struct {
    float x, y;
    float w, h;
    float velX, velY;
    bool isOnGround;
} Player;

void handleEvents(SDL_Event *event, bool *running, Player *player) {
    while (SDL_PollEvent(event)) {
        if (event->type == SDL_QUIT) {
            *running = false;
        }
        if (event->type == SDL_KEYDOWN) {
            switch (event->key.keysym.sym) {
                case SDLK_LEFT:
                    player->velX = -SPEED;
                    break;
                case SDLK_RIGHT:
                    player->velX = SPEED;
                    break;
                case SDLK_SPACE:
                    if (player->isOnGround) {
                        player->velY = JUMP_FORCE;
                        player->isOnGround = false;
                    }
                    break;
            }
        }
        if (event->type == SDL_KEYUP) {
            switch (event->key.keysym.sym) {
                case SDLK_LEFT:
                case SDLK_RIGHT:
                    player->velX = 0;
                    break;
            }
        }
    }
}

void updatePlayer(Player *player) {
    player->y += player->velY;
    player->x += player->velX;

    // Appliquer la gravité
    player->velY += GRAVITY;

    // Collision avec le sol
    if (player->y + player->h >= SCREEN_HEIGHT) {
        player->y = SCREEN_HEIGHT - player->h;
        player->isOnGround = true;
        player->velY = 0;
    }

    // Empêcher de sortir de l'écran
    if (player->x < 0) player->x = 0;
    if (player->x + player->w > SCREEN_WIDTH) player->x = SCREEN_WIDTH - player->w;
}

void renderPlayer(SDL_Renderer *renderer, Player *player) {
    SDL_Rect rect = { (int)player->x, (int)player->y, (int)player->w, (int)player->h };
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Rouge
    SDL_RenderFillRect(renderer, &rect);
}

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Erreur d'initialisation de SDL: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Mario 2D",
                                          SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          SCREEN_WIDTH, SCREEN_HEIGHT,
                                          SDL_WINDOW_SHOWN);
    if (!window) {
        printf("Erreur de création de la fenêtre: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Erreur de création du renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    bool running = true;
    SDL_Event event;

    Player player = { SCREEN_WIDTH / 2, SCREEN_HEIGHT - 100, 50, 50, 0, 0, true };

    while (running) {
        handleEvents(&event, &running, &player);
        updatePlayer(&player);

        SDL_SetRenderDrawColor(renderer, 135, 206, 250, 255); // Bleu ciel
        SDL_RenderClear(renderer);

        renderPlayer(renderer, &player);

        SDL_RenderPresent(renderer);
        SDL_Delay(16); // ~60 FPS
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
