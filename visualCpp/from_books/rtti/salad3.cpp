#include <iostream>
#include <typeinfo>
using namespace std;

//some definitions

typedef enum {
	WHOLE,
	SHAREDDED,
	GRATED,
	SLICED,
	CHOPPED
} FoodState;

//upper part of the inheritance tree
class Food {
public:
	Food(const FoodState = WHOLE);
	//each food should give the state
	virtual FoodState GetState() const;
	virtual void SetState(const FoodState);
private:
	FoodState theFoodState;
};

Food::Food(const FoodState newState) {
	SetState(newState);
}

FoodState Food::GetState() const {
	return theFoodState;
}

void Food::SetState(const FoodState newState) {
	theFoodState = newState;
}

ostream& operator<<(ostream& outstrm, Food& theFood) {
	switch (theFood.GetState()) {
	case WHOLE:
		outstrm << "Whole";
		break;
	case SHAREDDED:
		outstrm << "Shredded";
		break;
	case GRATED:
		outstrm << "Grated";
		break;
	case SLICED:
		outstrm << "Sliced";
		break;
	case CHOPPED:
		outstrm << "Chopped";
		break;
	default:
		outstrm << "Bad state !";
	}
	return outstrm;
}

//individual types
class Apple : public Food {
public:
	void Chop() {
		SetState(CHOPPED);
	}
	void Slice() {
		SetState(SLICED);
	}
};

class Cheese : public Food {
public:
	void Grate() {
		SetState(GRATED);
	}
};

class Lettuce : public Food {
public:
	void Shred() {
		SetState(SHAREDDED);
	}
};

//processing of one single ingredient
void ProcessIngredient(Food* pIngredient) {
	if (typeid(*pIngredient) == typeid(Apple)) {
		((Apple*)pIngredient)->Chop();
		return;
	}
	if (typeid(*pIngredient) == typeid(Lettuce)) {
		((Lettuce*)pIngredient)->Shred();
		return;
	}
	if (typeid(*pIngredient) == typeid(Cheese)) {
		((Cheese *)pIngredient)->Grate();
		return;
	}
}

int main() {
	Lettuce MyLettuce;
	Apple MyApple;
	Cheese MyCheese;
	ProcessIngredient(&MyLettuce);
	ProcessIngredient(&MyApple);
	ProcessIngredient(&MyCheese);

	cout << "The "<<typeid(MyLettuce).name()<<" is ";
	cout << MyLettuce << endl;
	cout << "The "<<typeid(MyApple).name()<<" is ";
	cout << MyApple << endl;
	cout << "The "<<typeid(MyCheese).name()<<" is ";
	cout << MyCheese << endl;
}