#include <iostream>
#include "SDL.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480





int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) == -1) {
        printf("SDL_Init failed: %s\n", SDL_GetError());
    }
    else {
        printf("SDL_Init successful! \n");

        SDL_Window* window=NULL;
       
        SDL_Surface* screenSurface = NULL;
       
        SDL_Rect dest;
        dest.x = SCREEN_WIDTH-200;
        dest.y = SCREEN_HEIGHT-200;



        window = SDL_CreateWindow("XADOPU4", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (!window) {
            printf("Boy next window \n");
        }
        else {
            screenSurface = SDL_GetWindowSurface(window);

            SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 144, 127, 169));
            SDL_UpdateWindowSurface(window);
            SDL_Surface* myImage = SDL_LoadBMP("Kot9pa_alpha.bmp");

            if (myImage == NULL){
                printf("Pic download failed \n");
            }
            else {
                SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 0, 255, 0));
                SDL_BlitSurface(myImage, NULL, screenSurface, &dest);
                printf("Kot9pa Ha Mecte \n");
                SDL_UpdateWindowSurface(window);

                printf("Completed! \n");
            }
           
                SDL_Delay(13000);


                //Clearing memory
                SDL_DestroyWindow(window);
                SDL_Quit();
           
        }
    }
    return 1;
}


