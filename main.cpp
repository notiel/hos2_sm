#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>
#include <string>

#include "service.h"
#include "eventHandlers.h"
#include "qhsm.h"
#include "health.h"
#include "ability.h"
#include "player_type.h"

#define DESKTOP

/*..........................................................................*/

int main() {
    uint8_t     i;                                      // Universal counter
    uint32_t    seconds=0;
    printf("Heart Of Storm State Machines\n");
    #ifdef DEBUG_SM
        printf("DEBUG_SM enabled\n\r");
    #endif
    #ifdef DESKTOP
        printf("Desktop version\n\r");
    #endif
    for (i = 0; i < KeyNumber()-1; i++)      // Excluding ESC
        printf("%18s - '%c'\n\r", KeyStrokes[i].Alias, KeyStrokes[i].Key);
    printf("Press ESC to quit...\n");

      /* instantiate the HSM and trigger the initial transition */
    Player_type_ctor(DEAD, health);
    printf("3\n");
    Health_ctor(DEAD, 30, 30, 0);
    printf("1\n");
	Ability_ctor(0, NONE);
	 printf("2\n");
	QMSM_INIT(the_player_type, (QEvt *)0);
	printf("4\n");
	QMSM_INIT(the_ability, (QEvt *)0);
	printf("5\n");
	QMSM_INIT(the_health, (QEvt *)0);
    printf("6\n");

  //SIMPLE_DISPATCH(the_health, RESET);
    QEvt e;
    uint8_t c;
  //e.sig = PILL_LOCAL_SIG;
  //QMSM_DISPATCH(the_player_type, &e);
    for (;;) {
           static int tickCtr = 1;
           std::string msg;
           usleep(100000);

           if (kbhit()) {
               c = (uint8_t)_getch();     /* read one character from the console */
               printf("%c: ", c);
               //for (i = 0; i < ARRAY_SIZE(KeyStrokes);i++) {
               for (i = 0; i < (TERMINATE_SIG - Q_USER_SIG); i++) {
                   if (c ==    KeyStrokes[i].Key) {
                       e.sig = KeyStrokes[i].Com;
                       msg = c;
                       break;
                   }
               }
           }
           else if (--tickCtr == 0) { /* time for the tick? */
                tickCtr = 10;
                e.sig = TIME_TICK_1S_SIG;
                msg = "TICK";
                seconds++;
                printf("Time: %ds. ", seconds);
           }
		   if (msg.length()) {
            /* dispatch the event into the state machine */
                QState r;
             //   QEvt e;
			    healthQEvt HOS_e;
                if (e.sig == DMG_RCVD_SIG) {
                    HOS_e.super = e;
                    HOS_e.value = 5;
                    r = QMSM_DISPATCH(the_health,  (QEvt *)&HOS_e);
                    r = QMSM_DISPATCH(the_player_type,  (QEvt *)&HOS_e);
                    r = QMSM_DISPATCH(the_ability,  (QEvt *)&HOS_e);
                } else {
			        r = QMSM_DISPATCH(the_ability,  &e);
			        r = QMSM_DISPATCH(the_player_type,  &e);
			        r = QMSM_DISPATCH(the_health,  &e);
                }

           #ifdef DEBUG
               printf("returned: %u\n\r", r);
            #endif
   
           }
    }
    return 0;
}
/*..........................................................................*/
void Q_onAssert(char const * const file, int line) {
    fprintf(stderr, "Assertion failed in %s, line %d", file, line);
    _exit(-1);
}
