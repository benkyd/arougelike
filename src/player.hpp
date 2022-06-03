#pragma once

#include <olcPixelGameEngine.h>

class Player
{
public:
	Player();

private:
	olc::vi2d mCollider;
	olc::vf2d mPosition;
	olc::vf2d mVelocity;

};


