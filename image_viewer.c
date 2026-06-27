#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

    //reading ppm file in binary format 
    FILE *in = fopen("input.ppm", "rb");
    if (!in) { fprintf(stderr, "cannot open file\n"); return 1; }

    //reading header data 
    // FILE *in = stdin; 
    char *pthroway = calloc(1000, sizeof(char));
    //read first line (specifier P3/p6)
    fgets(pthroway, 1000, in);
    //read second line (comment)
    //uncomment this line if your file has a comment , or remove the comment
    // fgets(pthroway,1000, in) ;    
    //read third line (dimensions: width / height )
    char *pdimensions = calloc(1000, sizeof(char)) ;
    fgets(pdimensions, 1000, in) ;
    //read fourth line (max color value)
    fgets(pthroway, 1000, in) ;
    free(pthroway);
    
    int width = -1; 
    int height = -1;
    sscanf(pdimensions, "%d %d\n", &width, &height) ;
    free(pdimensions) ;

    printf(" width : %d, height : %d ", width, height);

    SDL_Init(SDL_INIT_VIDEO);

    //creating window of given width and height 
    SDL_Window* pwindow = SDL_CreateWindow(
        "Simple Image Viewer", SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, width, height, 0);
    
    //getting surface from that window
    SDL_Surface *psurface = SDL_GetWindowSurface(pwindow);

    //getting colors in unit32 format (this is proper pixel format that we can use )
    // Uint8 r, g, b ; 
    // r = 0xFF; 
    // b = 0xFF ; 
    // g = 0 ; 
    // Uint32 color = SDL_MapRGB(psurface->format, r, g, b) ;

    //fill rectangle in full area (NULL represents full area )
    // SDL_FillRect(psurface, NULL , color) ;
    

    /* reading binary data here*/

    // instead of using NULL we would use the pixel color values 
    SDL_Rect pixel = (SDL_Rect){0,0,1,1};
    //looping over full window and putting colors to the pixel 
    for(int y = 0 ; y < height ; y++){
        for(int x = 0 ; x < width ; x++){
            Uint8 r,g,b ; 
            r = (Uint8)fgetc(in);
            g = (Uint8)fgetc(in);
            b = (Uint8)fgetc(in);
            Uint32 color = SDL_MapRGB(psurface->format, r,g,b) ;
            pixel.x = x ;
            pixel.y = y ;
            SDL_FillRect(psurface, &pixel, color ) ;
        }
    }
    
    SDL_UpdateWindowSurface(pwindow); //to tell the graphics memory that the color has changed
    
    // SDL_Delay(3000);
    // we will use SDL event loop, to close or open viewer
    int appRunning = 1 ; 
    while(appRunning)
    {
        SDL_Event event ;
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                appRunning = 0 ; 
            }
        }
        SDL_Delay(100) ;
    }
    SDL_DestroyWindow(pwindow);
    SDL_Quit();    
    return 0;
} 