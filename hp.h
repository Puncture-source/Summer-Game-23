#pragma once
#include <cstdint>

typedef std::uint16_t hpType;

class hp {
public:

//sets max hp (like from level up)
//return true if set correctly 
    bool setMaxHP(hpType newMaxHP){
        if (newMaxHP <1){
            return false;
        }
        maxHP = newMaxHP;
        if (currentHP > maxHP){
            currentHP = maxHP;
        }
    return true;
}

// allows access to private max hp info

    hpType getMaxHP(){
        return maxHP;
    }
    

// see current health
hpType getCurrentHP() {
    return currentHP;
}

//Ran when health loss occurs
    void takeDamage(hpType damage){
        if (damage > currentHP){
        currentHP = 0;
        return;
        }

    currentHP -= damage;
    }


//runs when player gains health
    void heal(hpType heal){
        if (heal + currentHP > maxHP){
            currentHP = maxHP;
            return;
        }
        currentHP += heal;
        return;
    }
    


//constructor for no input
    hp(){
        currentHP =1;
        maxHP = 1;
    }

// constructor with input
hp(hpType cHP, hpType mHP){
    if(cHP>mHP){ //might need to fix this later, might cause issues
        currentHP = mHP;
        maxHP = mHP;
        return;
    }
    currentHP = cHP;
    maxHP = mHP;
}    

private:
    hpType shield;
    hpType currentHP;
    hpType maxHP;    
};