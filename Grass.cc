#include<iostream>
#include"RandomNum.h"
#include"World.h"
#include"Creature.h"
#include"Grass.h"

Grass::Grass(int _x, int _y, World& world):Creature(_x,_y),theWorld(world),dir(RandomNum(world.getCreatureNum())){
	setTodayIs(theWorld.getTodayIs());
	setAge(0);
}

Grass::~Grass(){
}

LiveOrDie
Grass::act(){
	increaseTodayIs();
	increaseAge();

	if(getAge()>=GrassLife){
		return die;
	}
	else{
		if(haveBaby()){// only grass do is have baby
			int dirx=0, diry=0;
			int babyDir = dir.getRandomNum(up,right);
			switch(babyDir){
				case up:
					if((getX()-1)<0)
						return live;
					else
						dirx = -1;
					break;
				case down:
					if((getX()+1)>=MapColumn)
						return live;
					else
						dirx = 1;
					break;
				case left:
					if((getY()-1)<0)
						return live;
					else
						diry = -1;
					break;
				case right:
					if((getY()+1)>=MapRow)
						return live;
					else
						diry = 1;
					break;
				default:
					break;
			}

			int babyx = getX()+dirx, babyy = getY()+diry;

			if(theWorld.getCreature(babyx, babyy)==NULL){
				theWorld.increaseCreatureNum();
				Creature* tmp = new Grass(babyx,babyy,theWorld);
				theWorld.setCreature(babyx,babyy,&tmp);
			}
		}
		return live;
	}


}

inline bool
Grass::haveBaby(){
	if(getAge()>=GrassStartBaby && getAge()<=GrassEndBaby)
		return true;
	else
		return false;
}

inline type
Grass::whatCreature(){
	return grass;
}
