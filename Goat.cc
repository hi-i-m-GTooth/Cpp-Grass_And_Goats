#include<iostream>
#include"RandomNum.h"
#include"World.h"
#include"Creature.h"
#include"Goat.h"
#include"Grass.h"

Goat::Goat(int _x, int _y, World& world):Creature(_x,_y),theWorld(world),move(RandomNum(world.getCreatureNum())){
	setTodayIs(theWorld.getTodayIs());
	setAge(0);
	foodPoints = 20;
}

Goat::~Goat(){
}

int
Goat::getFoodPints() const{
	return foodPoints;
}

void
Goat::increaseFoodPoints(int points){
	foodPoints+=points;
}

void
Goat::decreaseFoodPoints(int points){
	foodPoints-=points;
}

void
Goat::moveTo(int newx, int newy){
	//set a cell to NULL & this goat to new cell
	theWorld.setNull(getX(),getY());

	this->setX(newx); this->setY(newy);
	Creature* tmp = this;
	theWorld.setCreature(newx,newy,&tmp);
}

LiveOrDie
Goat::act(){
	increaseAge();
	increaseTodayIs();

	if(getAge()>=GoatLife)
		return die;
	else{
		int movex=0 ,movey=0;
		int moveThisPass = (move.getRandomNum(0,100))%4;

		decreaseFoodPoints(WalkConsumePoint);
		
		switch(moveThisPass){
			case up:
				if((getX()-1)<0) //illegal cell
					return live;
				else
					movex = -1;
				break;
			case down:
				if((getX()+1)>=MapColumn) //illegal cell
					return live;
				else
					movex = 1;
				break;
			case left:
				if((getY()-1)<0) //illegal cell
					return live;
				else
					movey = -1;
				break;
			case right:
				if((getY()+1)>=MapRow) //illegal cell
					return live;
				else
					movey = 1;
				break;
			default:
				break;
		}

		int newx=getX()+movex, newy=getY()+movey;

		if((theWorld.getCreature(newx,newy)!=NULL)&&(theWorld.getCreature(newx,newy)->whatCreature()==grass)){
			//deal with grass
			increaseFoodPoints(GrassPoint);
			theWorld.deleteCreature(newx,newy);
		}

		if(haveBaby()){
			//have baby
			theWorld.increaseCreatureNum();
			Creature* tmp = new Goat(newx,newy,theWorld);
			theWorld.setCreature(newx,newy,&tmp);
		}
		else{
			// move
			moveTo(newx,newy);
		}

		if(foodPoints<=0)
			return die;
		else
			return live;
	}

}

bool
Goat::haveBaby(){
	if(getAge()>=GoatStartBaby && getAge()<=GoatEndBaby)
		return true;
	else
		return false;
}

type
Goat::whatCreature(){
	return goat;
}
