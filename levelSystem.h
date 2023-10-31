#pragma once
#include <cstdint>

typedef std::uint64_t expType;
typedef std::uint16_t levelType;

class levelSystem{

    public:

        void distFromGod(expType c){
            distanceFromGod = c;
        }

        void startingLevel(expType l){
            levelStart = l;
        }

        levelSystem(){
            currentLevel = 1u;
            currentExp = 0u;
            distanceFromGod = 3u;
            expToLevel = distanceFromGod+currentLevel; // clean this up later, this is an artifact of a late change
        }


        void gainExp(expType gainedExp){
            currentExp += gainedExp;
            while(check_if_level()){};
        }


levelType getCurrentLevel(){
    return currentLevel;
}

expType getCurrentExp(){
    return currentExp;
}

expType getExpToLevel(){
    return expToLevel;
}

virtual void levelUp()=0;


    protected: 
    
        levelType currentLevel;
        expType currentExp;
        expType levelStart;
        levelType distanceFromGod;
        expType expToLevel;

        bool check_if_level(){
            if(currentExp >= expToLevel){
                currentExp = 0;
                expToLevel = distanceFromGod+currentLevel;
                currentLevel++;
                levelUp();
                return true;
            }
            return false;
        }

};