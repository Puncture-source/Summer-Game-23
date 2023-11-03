#pragma once
#include <cstdint>
typedef std::uint16_t statType;


class statBlock {
        statType strength; // 0xFF
    statType intellect; // 0xFF
    statType agility; // 0xFF
    statType resistance; // 0xFF
    statType armour; // 0xFF

public:

    // constructor
    explicit statBlock(statType s=(statType)0u, statType i=(statType)0u, statType a=(statType)0u, statType r =(statType)0u, statType arm = (statType)0u){
        strength = s; 
        intellect = i;
        agility = a;
        resistance = r;
        armour = arm;
        }

//get strength
    statType getStrength(){
        return strength;
    }

    statType getAgility(){
        return agility;
    }
    statType getResistance(){
        return resistance;
    }
// get intellect
    statType getIntellect(){
        return intellect;
    }
    statType getArmour(){
        return armour;
    }

protected:
    void increaseStats(statType s, statType i ,statType a, statType r, statType arm){
        strength +=s;
        intellect +=i;
        agility +=i;
        resistance +=i;
        armour +=arm;

    }
};