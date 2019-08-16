/*$file${.::ability.h} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/*
* Model: Ability.qm
* File:  ${.::ability.h}
*
* This code has been generated by QM 4.5.1 (https://www.state-machine.com/qm).
* DO NOT EDIT THIS FILE MANUALLY. All your changes will be lost.
*
* This program is open source software: you can redistribute it and/or
* modify it under the terms of the GNU General Public License as published
* by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
* or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
* for more details.
*/
/*$endhead${.::ability.h} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
#ifndef ability_h
#define ability_h
#ifdef __cplusplus
extern "C" {
#endif
#include "qhsm.h"    /* include own framework tagunil version */

//Start of h code from diagram
#define NONE 0
#define MUTANT_READY 1
#define MUTANT_CHARGING 2
#define DISABLED 3
#define CHARGE_TO_S 30
//End of h code from diagram


/*$declare${SMs::Ability} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/*${SMs::Ability} ..........................................................*/
typedef struct {
/* protected: */
    QHsm super;

/* public: */
    unsigned int ChargeTime;
    QStateHandler StartState;
} Ability;

/* protected: */
QState Ability_initial(Ability * const me, QEvt const * const e);
QState Ability_global(Ability * const me, QEvt const * const e);
QState Ability_ability(Ability * const me, QEvt const * const e);
QState Ability_none(Ability * const me, QEvt const * const e);
QState Ability_disabled(Ability * const me, QEvt const * const e);
QState Ability_mutant(Ability * const me, QEvt const * const e);
QState Ability_ready(Ability * const me, QEvt const * const e);
QState Ability_charging(Ability * const me, QEvt const * const e);

#ifdef DESKTOP
QState Ability_final(Ability * const me, QEvt const * const e);
#endif /* def DESKTOP */

/*$enddecl${SMs::Ability} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/

static Ability ability; /* the only instance of the Ability class */



typedef struct abilityQEvt {
    QEvt super;
} abilityQEvt;

extern QHsm * const the_ability; /* opaque pointer to the ability HSM */

/*$declare${SMs::Ability_ctor} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/*${SMs::Ability_ctor} .....................................................*/
void Ability_ctor(unsigned int State, unsigned int ChargeTime);
/*$enddecl${SMs::Ability_ctor} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
#ifdef __cplusplus
}
#endif
#endif /* ability_h */
