#pragma once
template <class T>
class RailroadCar {
public:
	//constructori and destructori
	RailroadCar(int NewCarNumber, T& NewContents);
	~RailroadCar();
	
	void ShowContents();
	T* Unload();
private:
	T* pContents;
	int CarNumber;
};
