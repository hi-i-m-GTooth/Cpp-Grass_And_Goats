#pragma once
//Goat basic
const int GoatLife = 70;
const int GoatStartBaby = 50;
const int GoatEndBaby = 55;

//Grass basic
const int GrassLife = 6;
const int GrassStartBaby = 3;
const int GrassEndBaby = 5;

//Point related
const int GrassPoint = 5;
const int WalkConsumePoint = 1;

enum Direction { up , down , left , right };
enum type { goat , grass };
enum LiveOrDie { die , live };

class Creature{

	public:
		Creature();
		Creature(int newx, int newy);
		~Creature();

		int getAge() const;
		int getTodayIs() const;
		int getX() const;
		int getY() const;
		
		void setAge(int newage);
		void setTodayIs(int today);
		void setX(int newx);
		void setY(int newy);

		void increaseAge();
		void increaseTodayIs();
		virtual LiveOrDie act()=0;
		virtual bool haveBaby()=0;
		virtual type whatCreature()=0;

	private:
		int x,y;
		int age;
		int todayis;
};
