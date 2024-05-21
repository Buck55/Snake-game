#include "Food.h"
#include "Colors.h"

bool Food::elementInDeque(Vector2 element, std::deque<Vector2> deque)
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

Food::Food(std::deque<Vector2> snakeBody) 
{
    position = generateRandomPos(snakeBody);

    Image image = LoadImage("Graphics/ball.png");
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
}

Food::~Food()
{
    UnloadTexture(texture);
}

void Food::Draw()
{
    DrawTexture(texture, offset + position.x * cellSize, offset + position.y * cellSize, WHITE);
}

Vector2 Food::generateRandomCell()
{
    float x = GetRandomValue(0, cellCount - 1);
    float y = GetRandomValue(0, cellCount - 1);
    return Vector2{x, y};
}

Vector2 Food::generateRandomPos(std::deque<Vector2> snakeBody)
{
    Vector2 position = generateRandomCell();
    while (elementInDeque(position, snakeBody))
    {
        position = generateRandomCell();
    }
    return position;
} 
