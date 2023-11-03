#pragma once
#include "pointWell.h"
#include "statblock.h"
#include "levelSystem.h"
class jackal : public hp, public statBlock, public levelSystem {
//jackal constructor    

public:
    static const hpType baseHP = (hpType)5u;
    static const statType baseStrength = (statType)3u;
    static const statType baseIntellect = (statType)3u;

    static const hpType growthHP = (hpType)5u;
    static const statType growthStrength = (statType)3u;
    static const statType growthIntellect = (statType)3u;

    
    jackal() : hp(baseHP,baseHP) , statBlock(baseStrength, baseIntellect){}


private:
    void levelUp() override{
        setMaxHP(growthHP +getMaxHP());
        increaseStats(growthStrength, growthIntellect);
    }
};