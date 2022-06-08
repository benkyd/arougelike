#include <iostream>

#define OLC_PGE_APPLICATION
#include <olcPixelGameEngine.h>

#include "main.hpp"
#include "dungeon.hpp"

class Game : public olc::PixelGameEngine
{
public:
    Game()
        : mDungeon(new Dungeon(this))
    {
        sAppName = "Arogus";
    }

    ~Game()
    {
        delete mDungeon;
    }

    bool OnUserCreate() override
    {
        return true;
    }

    bool OnUserUpdate( float fElapsedFrameTime ) override
    {
//        Clear(olc::BLACK);
//
//        if (GetKey(olc::Key::A).bHeld) mCameraPosition.x = mCameraPosition.x + 5;
//        if (GetKey(olc::Key::D).bHeld) mCameraPosition.x = mCameraPosition.x - 5;
//        if (GetKey(olc::Key::W).bHeld) mCameraPosition.y = mCameraPosition.y + 5;
//        if (GetKey(olc::Key::S).bHeld) mCameraPosition.y = mCameraPosition.y - 5;
        mDungeon->Move( this );
        mDungeon->Update();
        mDungeon->Draw();

        return true;
    }

    bool OnUserDestroy() override
    {
        return true;
    }

private:
    Dungeon* mDungeon;
};


int main(int argc, char** argv)
{
    Game aRogueLike;

    aRogueLike.Construct( 980, 720, 1, 1, false, false );
    aRogueLike.Start();

    return 0;
}
