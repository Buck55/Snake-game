#pragma once
#include <raylib.h>
#include <deque>
#include <raymath.h>

class Food
{
    public:
        Food(std::deque<Vector2> snakeBody);
        ~Food();

        void Draw();
        bool elementInDeque(Vector2 element, std::deque<Vector2> deque);
        
        Vector2 position;
        Texture2D texture;
        Vector2 generateRandomPos(std::deque<Vector2> snakeBody);
        Vector2 generateRandomCell();

    private:
        int cellSize = 25;
        int cellCount = 35;
        int offset = 55;
};