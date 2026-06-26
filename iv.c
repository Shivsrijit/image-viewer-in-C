#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* pwindow = SDL_CreateWindow(
        "Simple Image Viewer", SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, 640, 480, 0);
    
    SDL_Surface *psurface = SDL_GetWindowSurface(pwindow);

    //getting colors in unit32 format (this is proper pixel format that we can use )
    Uint8 r, g, b ; 
    r = 0xFF; 
    b = 0xFF ; 
    g = 0 ; 
    Uint32 color = SDL_MapRGB(psurface->format, r, g, b) ;

    //fill rectangle in full area (NULL represents full area )
    SDL_FillRect(psurface, NULL , color) ;
    SDL_UpdateWindowSurface(pwindow); //to tell the graphics memory that the color has changed
    SDL_Delay(3000);
    SDL_DestroyWindow(pwindow);
    SDL_Quit();    
    return 0;
} 