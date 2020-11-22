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
	Apple * pApple = dynamic_cast<Apple *>(pIngredient);
	if (pApple) {
		pApple->Chop();
		return;
	}
	Lettuce *pLettuce = dynamic_cast<Lettuce *>(pIngredient);
	if (pLettuce) {
		pLettuce->Shred();
		return;
	}
	Cheese* pCheese = dynamic_cast<Cheese *>(pIngredient);
	if (pCheese) {
		pCheese->Grate();
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

	cout << "The lettuce is ";
	cout << MyLettuce << endl;
	cout << "The Apple is ";
	cout << MyApple << endl;
	cout << "The Cheese is ";
	cout << MyCheese << endl;
}