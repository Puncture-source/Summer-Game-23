#pragma once
#include "hp.h"
#include "statblock.h"
class zealot : public hp, public statBlock {
//zealot constructor    

public:
    static const hpType startingHP = (hpType)7u;
    static const statType baseStrength = (statType)5u;
    static const statType baseIntellect = (statType)1u;
    
    zealot() : hp(startingHP,startingHP) , statBlock(baseStrength, baseIntellect){}


private:
};