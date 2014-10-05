#include "Stage.h"


Stage::Stage(void)
{
}

Stage::Stage(std::string name)
{
	this->name = name;
	// Example only
	if(name == "Main Hall")
	{
		background = "images/stone.bmp";
	}
}

Stage::~Stage(void)
{
}
