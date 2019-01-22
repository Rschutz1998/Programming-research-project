#pragma once
#include "GameObject.h"

class Player {

private:
	static int currentBlockIndex;
	static bool canSwitch;

public:
	static void Update();
	static BlockTypeEnum GetCurrentBlockType();
};
