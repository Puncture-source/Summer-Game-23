#pragma once
#include <cstdint>

typedef std::uint16_t wellType;

class pointWell {
public:

//sets max hp (like from level up)
//return true if set correctly 
    bool setMax(wellType newMax){
        if (newMax <1){
            return false;
        }
        max = newMax;
        if (current > max){
            current = max;
        }
    return true;
}

// allows access to private max hp info

    wellType getMax(){
        return max;
    }
    

// see current health
wellType getCurrent() {
    return current;
}

//Ran when health loss occurs
    void reduce(wellType damage){
        if (damage > current){
        current = 0;
        return;
        }

    current -= damage;
    }


//runs when player gains health
    void increase(wellType heal){
        if (heal + current > max){
            current = max;
            return;
        }
        current += heal;
        return;
    }
    


//constructor for no input
    pointWell(){
        current =1;
        max = 1;
        shield = (wellType)0;
    }

// constructor with input
pointWell(wellType curr, wellType maxx){
    shield = (wellType)0;
    if(curr>maxx){ //might need to fix this later, might cause issues
        current = maxx;
        max = maxx;
 
        return;
    }
    current = curr;
    max = maxx;
}    

private:
    wellType shield;
    wellType current;
    wellType max;    
};