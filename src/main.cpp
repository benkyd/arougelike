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

    void UpdateWorld(float fWorldOffsetX, float fWorldOffsetY)
    {
        fWorldX = fWorldOffsetX;
        fWorldY = fWorldOffsetX;
    }

    bool OnUserUpdate( float fElapsedFrameTime ) override
    {
        Clear(olc::BLACK);
        
        if (GetKey(olc::Key::A).bPressed) fStartPanX = fWorldX;
        if (GetKey(olc::Key::D).bPressed) fStartPanX = fWorldX;
        if (GetKey(olc::Key::W).bPressed) fStartPanY = fWorldY;
        if (GetKey(olc::Key::S).bPressed) fStartPanY = fWorldY;

        if (GetKey(olc::Key::A).bHeld) fOffsetX = fWorldX - 1;
        if (GetKey(olc::Key::D).bHeld) fOffsetX = fWorldX + 1;
        if (GetKey(olc::Key::W).bHeld) fOffsetY = fWorldY - 1;
        if (GetKey(olc::Key::S).bHeld) fOffsetY = fWorldY + 1;

        UpdateWorld(fOffsetX, fOffsetY);

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

    float fCameraPos = 20.0f;

    float fCenterX = 0 + (ScreenWidth() / static_cast<float>(2));
    float fCenterY = 0 + (ScreenHeight() / static_cast<float>(2));

    float fWorldX = fCenterX;
    float fWorldY = fCenterY;

    float fStartPanX = 0.0f;
    float fStartPanY = 0.0f;

    float fOffsetX = 0.0f;
    float fOffsetY = 0.0f;
};


int main(int* argc, char** argv) 
{
    Game aRogueLike;
    

    aRogueLike.Construct( 980, 720, 1, 1, false, false );
    aRogueLike.Start();

    return 0;
}
