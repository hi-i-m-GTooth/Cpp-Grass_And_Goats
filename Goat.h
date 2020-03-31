#include"RandomNum.h"
#include"World.h"
#include"Creature.h"


class Goat: public Creature{

	public:
		Goat(int _x, int _y, World& world);
		~Goat();

		int getFoodPints() const;

		void increaseFoodPoints(int points);
		void decreaseFoodPoints(int points);
		void moveTo(int newx, int newy);
		virtual LiveOrDie act();
		virtual bool haveBaby();
		virtual type whatCreature();

	private:
		int foodPoints;
		RandomNum move;
		World& theWorld;

};
