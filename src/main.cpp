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
        // fOffsetX = -ScreenWidth() / 2;
        // fOffsetY = -ScreenHeight() / 2;
        return true;
    }

    bool OnUserUpdate( float fElapsedFrameTime ) override
    {
        Clear(olc::BLACK);

        if (GetKey(olc::Key::A).bHeld) mCameraPosition.x = mCameraPosition.x + 10;
        if (GetKey(olc::Key::D).bHeld) mCameraPosition.x = mCameraPosition.x - 10;
        if (GetKey(olc::Key::W).bHeld) mCameraPosition.y = mCameraPosition.y + 10;
        if (GetKey(olc::Key::S).bHeld) mCameraPosition.y = mCameraPosition.y - 10;

        mDungeon->Update();
        mDungeon->Draw(&mCameraPosition);

        return true;
    }

    bool OnUserDestroy() override
    {
        return true;
    }

private:
    Dungeon* mDungeon;

    olc::vf2d mCameraPosition = {0.0f, 0.0f};

    // void WorldToScreen(float fWorldX, float fWorldY, int &nScreenX, int &nScreenY)
    // {
    //     nScreenX = (int)(fWorldX) - fOffsetX;
    //     nScreenY = (int)(fWorldY) - fOffsetY;
    // }

    // void ScreenToWorld(int nScreenX, int nScreenY, float &fWorldX, float &fWorldY)
    // {
    //     fWorldX = (float)(nScreenX) + fOffsetX;
    //     fWorldY = (float)(nScreenY) + fOffsetY;
    // }
};


int main(int argc, char** argv)
{
    Game aRogueLike;
    

    aRogueLike.Construct( 980, 720, 1, 1, false, false );
    aRogueLike.Start();

    return 0;
}
