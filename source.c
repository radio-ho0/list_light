/* source.c
 *
 * @author 
 * 
 * date: 2013/11/25
 * Changelog:
 *
 */
#include <stdlib.h>
#include <at89x52.h>
#include "round.h"
struct round* display;

struct round* tmp;


void delay(void)
{
    int j;
    for( j = 0; j < 50000; ++j)
        ;

}

void main(void)
{
    int light =   0xfe;
    int i;                                          // TODO: for(int i ....
    tmp = display;
    display = (struct round *)malloc( sizeof( struct round  ));
    display -> value = light;
   for ( i = 0; i < ele_num; i++, light <<= 1) {
       tmp = (tmp -> next) = (struct round *)malloc( sizeof( struct round ) * 1 );
       tmp -> value = light;
       tmp -> next = display;
   }
   for(;;){
       P0 = display -> value;
       display = display -> next;
       delay(); /// just for quick build
}

}
