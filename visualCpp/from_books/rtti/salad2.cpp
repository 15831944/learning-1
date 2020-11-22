#include <iostream>
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
public :
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
//intermediary group
class SaladIngredient : public Food {
public:
	virtual void ProcessIngredient() = 0;
};

//individual types
class Apple : public SaladIngredient {
public:
	void ProcessIngredient() {
		SetState(CHOPPED);
	}
};

class Cheese : public SaladIngredient {
public:
	void ProcessIngredient() {
		SetState(GRATED);
	}
};

class Lettuce : public SaladIngredient {
public:
	void ProcessIngredient() {
		SetState(SHAREDDED);
	}
};

int main() {
	Lettuce MyLettuce;
	Apple MyApple;
	Cheese MyCheese;
	MyLettuce.ProcessIngredient();
	MyApple.ProcessIngredient();
	MyCheese.ProcessIngredient();

	cout << "The lettuce is ";
	cout << MyLettuce << endl;
	cout << "The Apple is ";
	cout << MyApple << endl;
	cout << "The Cheese is ";
	cout << MyCheese << endl;
}