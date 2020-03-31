#include"RandomNum.h"
#include"World.h"

class Grass: public Creature{

	public:
		Grass(int _x, int _y, World& world);
		~Grass();

		virtual LiveOrDie act();
		virtual bool haveBaby();
		virtual type whatCreature();

	private:
		RandomNum dir;
		World& theWorld;

};
