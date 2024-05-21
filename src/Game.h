#pragma once
#include <raylib.h>
#include "Snake.h"
#include "Food.h"

class Game
{
    public:
        Snake snake = Snake(); 
        Food food = Food(snake.body);
        Sound eatSound;
        Sound gameOverSound;

        Game();
        ~Game();

        void HandleInput();
        void Draw();
        void Update();
        void CheckCollisionWithFood();
        void CheckCollisionWithEdges();
        void CheckCollisionWithTail();
        void gameOver();

        bool elementInDeque(Vector2 element, std::deque<Vector2> deque);
        bool running = true;
        int score = 0;
        float speed = 0.2;

    private:
        int cellCount = 35;
        double lastUpdateTime = 0;
};