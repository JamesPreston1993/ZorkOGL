#pragma once
#include <string>
#include <vector>
class Stage
{
public:
	Stage(void);
	Stage(std::string name);
	~Stage(void);
	std::string getName();
	std::string getBackground();
	bool isCompleted();
private:
	std::string name;
	std::string background;
	bool complete;
	//vector <InventoryItem> items;
};

