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
        fOffsetX = -ScreenWidth() / 2;
        fOffsetY = -ScreenHeight() / 2;
        return true;
    }

    bool OnUserUpdate( float fElapsedFrameTime ) override
    {
        Clear(olc::BLACK);

        float fMouseX = (float) GetMouseX();
        float fMouseY = (float) GetMouseY();

        if(GetMouse(0).bPressed)
        {
            fStartPanX = fMouseX;
            fStartPanY = fMouseY;
        }

        if(GetMouse(0).bHeld)
        {
            fOffsetX -= (fMouseX - fStartPanX);
            fOffsetY -= (fMouseY - fStartPanY);

            fStartPanX = fMouseX;
            fStartPanY = fMouseY;
            std::cout << 'X';
            std::cout << fStartPanX << std::endl;
            std::cout << 'Y';
            std::cout << fStartPanY << std::endl;
        }
        
//        if (GetKey(olc::Key::A).bPressed) fStartPanX = fWorldX;
//        if (GetKey(olc::Key::D).bPressed) ;
//        if (GetKey(olc::Key::W).bPressed) fStartPanY = fWorldY;
//        if (GetKey(olc::Key::S).bPressed) fStartPanY = fWorldY;
//
//        if (GetKey(olc::Key::A).bHeld) fOffsetX = fWorldX - 1;
//        if (GetKey(olc::Key::D).bHeld) fOffsetX = fWorldX + 1;
//        if (GetKey(olc::Key::W).bHeld) fOffsetY = fWorldY - 1;
//        if (GetKey(olc::Key::S).bHeld) fOffsetY = fWorldY + 1;
//
//        UpdateWorld(fOffsetX, fOffsetY);

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

    float fStartPanX = 0.0f;
    float fStartPanY = 0.0f;

    float fOffsetX = 0.0f;
    float fOffsetY = 0.0f;

    void WorldToScreen(float fWorldX, float fWorldY, int &nScreenX, int &nScreenY)
    {
        nScreenX = (int)(fWorldX) - fOffsetX;
        nScreenY = (int)(fWorldY) - fOffsetY;
    }

    void ScreenToWorld(int nScreenX, int nScreenY, float &fWorldX, float &fWorldY)
    {
        fWorldX = (float)(nScreenX) + fOffsetX;
        fWorldY = (float)(nScreenY) + fOffsetY;
    }
};


int main(int argc, char** argv)
{
    Game aRogueLike;
    

    aRogueLike.Construct( 980, 720, 1, 1, false, false );
    aRogueLike.Start();

    return 0;
}
