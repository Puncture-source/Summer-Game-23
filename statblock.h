#pragma once
#include <cstdint>
typedef std::uint16_t statType;


class statBlock {
        statType strength; // 0xFF
    statType intellect; // 0xFF
public:
    // default constructor
    statBlock(){
        strength = (statType)0u; 
        intellect = (statType)0u;
        }

    // input constructor
    explicit statBlock(statType s, statType i){
        strength = s; 
        intellect = i;
        }

//get strength
    statType getStrength(){
        return strength;
    }

// get intellect
    statType getIntellect(){
        return intellect;
    }

protected:
    void increaseStats(statType s, statType i){
        strength +=s;
        intellect +=i;

    }
};