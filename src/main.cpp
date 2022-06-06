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
        Clear(olc::BLACK);

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


int main(int* argc, char** argv) 
{
    Engine::GetInstance().pge.Construct( 980, 720, 1, 1, false, false );
    Engine::GetInstance().pge.Start();

    return 0;
}
