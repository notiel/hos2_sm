/* Additional entities for convenience
*/
#ifndef service_h
#define service_h

#ifdef __cplusplus
extern "C" {
#endif

#define     ARRAY_SIZE(foo) (sizeof(foo)/sizeof(foo[0]))

#include <stdint.h>


/* Keystroke-signal aliases to use with printf */
typedef struct KeyStroke_ {
   uint8_t          Com;      // Command
   char const      *Alias;    // Sting name for command
   uint8_t          Key;      // Keyboard symbol
} KeyStroke;

extern const KeyStroke KeyStrokes[];    // Definition moved to C file, otherwise
                                        // won't compile


unsigned int KeyNumber();

#ifdef __cplusplus
}
#endif
#endif
