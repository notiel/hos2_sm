#include "health.h"
#include "Ability.h"

void Flash(unsigned int R, unsigned int G, unsigned int B, unsigned int Timeout);
void Vibro(unsigned int Timeout);
void SendShining();
void State_Save(unsigned int State);
void Ability_Save(unsigned int Ability);
void PlayerType_Save(unsigned int Type);
void HP_Save(unsigned int HP);
void MaxHP_Save(unsigned int MaxHP);
void DangerTime_Save(unsigned int Time); 
void ChargeTime_Save(unsigned int Time);


void DangerTime_Update(Health* me, unsigned int Time);
void HP_Update(Health* me, int HP);
void MaxHP_Update(Health* me, unsigned int MaxHP);
void Player_Died(Health* me);
void ShowHP(Health* me);
void ChargeTime_Update(Ability *me, unsigned int Time);
void Reset(Health* me);
void IndicateDamage(Health* me);
