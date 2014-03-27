#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

//Screen attributes
const int SCREEN_WIDTH = 540;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

//The surfaces
SDL_Surface *image = NULL;
SDL_Surface *screen = NULL;
SDL_Surface *cohetio = NULL;
SDL_Surface *cohe[5];
SDL_Surface *aster[4];

SDL_Event *event;


SDL_Surface *load_image( std::string filename )
{
    return IMG_Load(filename.c_str());
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination )
{
    //Rectangle to hold the offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit the surface
    SDL_BlitSurface( source, NULL, destination, &offset );
}

bool init()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return false;
    }

    //Set the window caption
    SDL_WM_SetCaption( "PNG test", NULL );

    //If everything initialized fine
    return true;
}

void clean_up()
{
    //Free the surface
    SDL_FreeSurface( image );
    SDL_FreeSurface( cohe[0] );
    SDL_FreeSurface( cohe[1] );
    SDL_FreeSurface( cohe[2] );
    SDL_FreeSurface( cohe[3] );
    SDL_FreeSurface( cohe[4] );
    SDL_FreeSurface( aster[0] );
    SDL_FreeSurface( aster[1] );
    SDL_FreeSurface( aster[2] );
    SDL_FreeSurface( aster[3] );
    //Quit SDL
    SDL_Quit();
}


int main( int argc, char* args[] )
{

    //Initialize
    if( init() == false )
    {
        return 1;
    }

    bool cohete=true, arriba=true;

    SDL_Surface* images[4];
    image = load_image("vida.png");
    cohetio = load_image("cohete.png");

    cohe[0]= load_image( "cohe1.png" );
    cohe[1]= load_image( "cohe2.png" );
    cohe[2]= load_image( "cohe3.png" );
    cohe[3]= load_image( "cohe4.png" );
    cohe[4]= load_image( "cohe5.png" );

    aster[0]= load_image( "aster1.png" );
    aster[1]= load_image( "aster2.png" );
    aster[2]= load_image( "aster3.png" );
    aster[3]= load_image( "aster4.png" );



    int a=-5;
    int b=50;

    int navecarril = 3;
    int navecursor = 228;


    int a2=0;
    int b2=0;
    bool cont = true;
    int x=0;
    int ci = 0;
    int ai = 0;
    int asterfre=500;
    int ciclo=0;

    int tempo;
    while(cont)
    {
        int ys = rand()%401;
        ciclo++;
        //If there was a problem in loading the image
        if( cohetio == NULL )
        {
            return 1;
        }

        SDL_Event event;
        //While there's events to handle
        while( SDL_PollEvent( &event ) )
        {

            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
//                quit = true;
                cont = false;
            }
        }

        Uint8 *keystates = SDL_GetKeyState( NULL );


        if(keystates[SDLK_UP])
        {
            if(navecarril >= 2 && tempo > 10)
            {
                navecarril--;
                tempo = 0;
            }

        }
        if(keystates[SDLK_DOWN] && tempo > 10)
        {
            if(navecarril <= 4)
            {
                navecarril++;
                tempo = 0;
            }

        }
        int posi[5];
        posi[0]=36;
        posi[1]=132;
        posi[2]=228;
        posi[3]=324;
        posi[4]=420;



        switch(navecarril)
        {
            case 1: navecursor = 36; break;
            case 2: navecursor = 132; break;
            case 3: navecursor = 228; break;
            case 4: navecursor = 324; break;
            case 5: navecursor = 420; break;
        }


        a2=a2-5;


        //Apply the surface to the screen
        if(a2<-540)
        {
           a2=0;
        }

        if(ci > 4)
        {
            ci = 0;
        }
        if(ai>3)
        {
            ai=0;
        }


        apply_surface(a2,b2, image,screen);
        apply_surface( a, navecursor, cohe[ci], screen );
        apply_surface(asterfre, ys, aster[ai], screen);




        //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }

        //Wait 2 seconds
        SDL_Delay( 20 );
        ci++;
        ai++;
        tempo++;
        x++;
        asterfre--;

    }
    //Free the surface and quit SDL
    clean_up();

    return 0;
}
