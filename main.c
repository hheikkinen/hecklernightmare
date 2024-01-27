#include <gb/gb.h>
#include <stdint.h>
#include <gbdk/font.h>
#include "textboxmap.h"

int joypadCurrent = 0, joypadPrevious = 0;

int phase = 0;
int screen = -1;

unsigned char empty[] =
{
  0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,
};

void main(void)
{
    SHOW_BKG;
    //SHOW_SPRITES;
    //SPRITES_8x8;
    SHOW_WIN;
    
    DISPLAY_ON;
    
    font_t min_font;

    font_init();
    min_font = font_load(font_min);
    font_set(min_font);

    //set_sprite_data(0, circlesprite8x8_TILE_COUNT, circlesprite8x8_tiles);
    //set_sprite_tile(0, 0);

    //set_bkg_data(0, 7, backgroundtiles);
    //set_bkg_tiles(0, 0, 40, 18, backgroundmap);

    // Loop forever
    while(1) {

        joypadPrevious = joypadCurrent;
        joypadCurrent = joypad();

        switch (screen)
        {
            case -1:
                set_win_tiles(5, 8, 10, 2, splashscreen);
                if(joypadCurrent & J_START)
                {
                    set_win_tiles(5, 8, 10, 2, empty);
                    screen++;
                }
            break;
            case 0:
                set_win_tiles(0, 1, 20, 4, test_bubble);
                if(joypadCurrent & J_A)
                {
                    screen++;
                }
                break;
            case 1:
                break;

            case 2:

                break;

            case 3:
                
                break;
            
            case 4:
                
                break;
            
            default:
                break;
        }

		// Done processing, yield CPU and wait for start of next frame
        vsync();
    }
}