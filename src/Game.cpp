#include "Game.h"

Game::Game()
{
    InitAudioDevice();
    eatSound = LoadSound("Sounds/eat.mp3");
    gameOverSound = LoadSound("Sounds/gameOver.mp3");
}

Game::~Game()
{
    UnloadSound(eatSound);
    UnloadSound(gameOverSound);
    CloseAudioDevice();
}

void Game::Draw()
{
    food.Draw();
    snake.Draw();
}

void Game::HandleInput()
{
    int keyPressed = GetKeyPressed();
    switch(keyPressed)
    {
        case KEY_UP:
        case KEY_W:
            if (snake.direction.y != 1)
            {
                snake.direction = {0, -1};
                running = true;
            }
            break;

        case KEY_DOWN:
        case KEY_S:
            if (snake.direction.y != -1)
            {
                snake.direction = {0, 1};
                running = true;
            }
            break;

        case KEY_LEFT:
        case KEY_A:
            if (snake.direction.x != 1)
            {
                snake.direction = {-1, 0};
                running = true;
            }
            break;

        case KEY_RIGHT:
        case KEY_D:
            if (snake.direction.x != -1)
            {
                snake.direction = {1, 0};
                running = true;
            }
            break;
    }
}

void Game::Update()
{
    float currentTime = GetTime();
    if (currentTime - lastUpdateTime >= speed)
    {
        if(running)
        {
            snake.Update();
            CheckCollisionWithEdges();
            CheckCollisionWithFood();
            CheckCollisionWithTail();
        }
        lastUpdateTime = currentTime;
    }
}

void Game::CheckCollisionWithFood()
{
    if(Vector2Equals(snake.body[0], food.position))
    {
        food.position = food.generateRandomPos(snake.body);
        snake.addSegment = true;
        score++;
        PlaySound(eatSound);

        if (score % 5 == 0)
        {
            speed = std::max(0.05, speed - 0.02);
        }
    }
}

void Game::CheckCollisionWithEdges()
{
    if(snake.body[0].x < 0)
    {
        snake.body[0].x = cellCount - 1;
    }
    else if (snake.body[0].x >= cellCount)
    {
        snake.body[0].x = 0;
    }

    if(snake.body[0].y < 0)
    {
        snake.body[0].y = cellCount - 1;
    }
    else if (snake.body[0].y >= cellCount)
    {
        snake.body[0].y = 0;
    }
}

bool Game::elementInDeque(Vector2 element, std::deque<Vector2> deque)
{
    for(unsigned int i = 0; i < deque.size(); i++)
    {
        if(Vector2Equals(deque[i], element))
        {
            return true;
        }
    }
    return false;
}

void Game::CheckCollisionWithTail()
{
    std::deque<Vector2> headlessBody = snake.body;
    headlessBody.pop_front();
    if(elementInDeque(snake.body[0], headlessBody))
    {
        gameOver();
    }
}

void Game::gameOver()
{
    snake.Reset();
    food.position = food.generateRandomPos(snake.body);
    running = false;
    score = 0;
    speed = 0.2;
    PlaySound(gameOverSound);
}