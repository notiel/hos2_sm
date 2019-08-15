#include "service.h"
#include "health.h"

const KeyStroke KeyStrokes[]= {
{    SHINE_RCVD_SIG,                 "SHINE_RCVD",                 's'},
{    CENTRAL_BUTTON_PRESSED_SIG,     "CENTRAL_BUTTON_PRESSED",     'b'},
{    TIME_TICK_1S_SIG,               "TIME_TICK_1S",               's'},
{    TIME_TICK_1M_SIG,               "TIME_TICK_1M",               'm'},
{    DMG_RCVD_SIG,                   "DMG_RCVD",                   'd'},
{    PILL_HEAL_SIG,                  "PILL_HEAL",                  'h'},
{    PILL_RESET_SIG,                 "PILL_RESET",                 'r'},
{    PILL_TAILOR_SIG,                "PILL_TAILOR",                't'},
{    PILL_STALKER_SIG,               "PILL_STALKER",               'p'},
{    PILL_LOCAL_SIG,                 "PILL_LOCAL",                 'l'},
{    FIRST_BUTTON_PRESSED_SIG,       "FIRST_BUTTON_PRESSED",       'f'},
{    SHINE_SIG,                      "SHINE",                      'h'},
{    PILL_MUTANT_SIG,                "PILL_MUTANT",                'u'},
{    SHINE_ORDER_SIG,                "SHINE_ORDER",                'o'},
{    TERMINATE_SIG,               "TERMINATE",                 0x1B   }

};

unsigned int KeyNumber() {
	return sizeof(KeyStrokes)/sizeof(KeyStrokes[0]);
}
