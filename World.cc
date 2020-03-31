#include<iostream>
#include"RandomNum.h"
#include"World.h"
#include"Creature.h"
#include"Goat.h"
#include"Grass.h"

using namespace std;

World::World(int passes, int seed):theSeed(seed),randomOfWorld(RandomNum(seed)){
	todayis = 0;
	thePasses = passes;
	creatureNum=seed+0;
	for(int i=0;i<MapColumn;i++){
		for(int j=0;j<MapRow;j++){
			map[i][j] = NULL;
		}
	}
	//initialize Goats & Grass
	for(int i=0;i<15;i++){
		Creature* tmp;
		int newx;
		int newy;
		int test=0;
		do{
			newx = randomOfWorld.getRandomNum(0,MapColumn-1);
			newy = randomOfWorld.getRandomNum(0,MapRow-1);
		}while(map[newx][newy]!=NULL);

		increaseCreatureNum();
		if(i<5){
			tmp = new Goat(newx,newy,*this);
		}
		else
			tmp = new Grass(newx,newy,*this);

		setCreature(newx,newy,&tmp);
	}
}

World::~World(){
	for(int i=0;i<MapColumn;i++){
		delete[] map[i];
	}
}

int 
World::getTodayIs() const{
	return todayis; 
}

int
World::getSeed() const{
	return theSeed;
}

int
World::getCreatureNum() const{
	// not only current Num alive on the map, it's (seed + total Num )
	// Just to be randomly.
	return creatureNum;
}

Creature*
World::getCreature(int col,int row) const{
	return map[col][row];
}

void
World::setTodayIs(int today){
	todayis = today;
}

void
World::setCreatureNum(int num){
	creatureNum+=num;
}

void
World::setCreature(int col,int row,Creature** newCreature){
	map[col][row] = *newCreature;

}

void
World::deleteCreature(int col,int row){
	// delete the memory of a Creature & set to NULL at map[col][row].
	Creature* tmp = map[col][row];
	map[col][row] = NULL;
	delete tmp;
}

void
World::setNull(int col,int row){
	map[col][row] = NULL;
}

void
World::increaseTodayIs(){
	++todayis;
}

void
World::increaseCreatureNum(){
	creatureNum+=randomOfWorld.getRandomNum(10,100);
}

void
World::print() const{
	cout<<StandardStartColumn;

	for(int ii=0;ii<MapColumn;ii++){
		cout<<ii%10;
		for(int jj=0;jj<MapRow;jj++){
			if(map[ii][jj]==NULL)
				cout<<"  ";
			else{
				switch(map[ii][jj]->whatCreature()){
					case goat:
						cout<<" X";
						break;
					case grass:
						cout<<" I";
						break;
					default:
						break;
				}
			}
		}
		cout<<endl;
	}
	cout<<StandardEndColumn;
}

void
World::mainLoop(int internval){

	for(int i=1;i<=thePasses;i++){
		++todayis;
		for(int ii=0;ii<MapColumn;ii++){
			for(int jj=0;jj<MapRow;jj++){
				if((map[ii][jj] != NULL) && (map[ii][jj]->getTodayIs())!=todayis){
					if(map[ii][jj]->act()==die){
						deleteCreature(ii,jj);
					}
				}
			}
		}

		if((i-1)%internval==0){
			print();
		}
	}
	
}
