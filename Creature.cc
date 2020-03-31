#include<iostream>
#include"Creature.h"
#include"World.h"

using namespace std;

Creature::Creature(){
	age = 0;
	todayis = -1;
}

Creature::Creature(int newx, int newy){
	x = newx; y = newy;
	age = 0;
	todayis = -1;
}

Creature::~Creature(){
}

int
Creature::getAge() const{
	return age;
}

int
Creature::getTodayIs() const{
	return todayis;
}

int
Creature::getX() const{
	return x;
}

int
Creature::getY() const{
	return y;
}

void
Creature::setAge(int newage){
	age = newage;
}

void
Creature::setTodayIs(int today){
	todayis = today;
}

void
Creature::setX(int newx){
	x = newx;
}

void
Creature::setY(int newy){
	y = newy;
}

void
Creature::increaseAge(){
	++age;
}

void
Creature::increaseTodayIs(){
	if(todayis>=0)
		++todayis;
	else
		cout<<"You are not born yet!\n";
}

LiveOrDie
Creature::act(){
	//this is a virtual function
}

bool
Creature::haveBaby(){
	//this is a virtal function
}

type
Creature::whatCreature(){
	//
}
