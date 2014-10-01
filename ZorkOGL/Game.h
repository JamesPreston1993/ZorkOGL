#pragma once
class Game
{
public:
	Game(void);
	virtual ~Game(void);
	virtual void run();

private:
	bool isRunning;	
};

