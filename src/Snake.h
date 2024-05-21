#pragma once
#include <raylib.h>
#include <deque>
#include <raymath.h>

class Snake
{
    public:
        Snake();

        void Draw();
        void Update();
        void Reset();
        
        bool addSegment = false;
        
        Vector2 direction;
        std::deque<Vector2> body;

    private:
        int cellSize = 25;
        int offset = 55;
        float x;
        float y;
};