#pragma once
#include"RandomNum.h"
#include"Creature.h"

const int MapRow = 35;
const int MapColumn = 20;
const char StandardStartColumn[] = "  0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 \n";
const char StandardEndColumn[] = "------------------------------------------------------------------------\n";

class World{
	
	public:
		World(int passes=1,int seed=0);
		~World();

		int getTodayIs() const;
		int getSeed() const;
		int getCreatureNum() const;
		Creature* getCreature(int col,int row) const;

		void setTodayIs(int today);
		void setCreatureNum(int num);
		void setCreature(int col,int row,Creature** newCreature);
		void deleteCreature(int col,int row);
		void setNull(int col,int row);

		void increaseTodayIs();
		void increaseCreatureNum();
		void print() const;
		void mainLoop(int internval);

	private:
		int todayis;
		int theSeed;
		int thePasses;
		int creatureNum;
		RandomNum randomOfWorld;
		Creature* map[MapColumn][MapRow];
};
