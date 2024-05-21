#include "Snake.h"
#include "Colors.h"

Snake::Snake()
{
    body = {Vector2{19,17}, Vector2{18,17}, Vector2{17,17}};
    direction = {1, 0};
}

void Snake::Draw()
{
    for(unsigned int i = 0; i < body.size(); i++)
    {
        x = body[i].x;
        y = body[i].y;

        Rectangle segment = Rectangle{offset + x * cellSize, offset + y * cellSize, (float)cellSize, (float)cellSize};

        if (i == 0)
        {
            DrawRectangleRounded(segment, 0.75, 10, black);
            DrawRectangleRoundedLines(segment, 0.75, 10, 2, WHITE);
        }
        else
        {
            DrawRectangleRounded(segment, 0.75, 10, black);
            DrawRectangleRoundedLines(segment, 0.75, 10, 2, gold);
        }
    }
}

void Snake::Update()
{
    body.push_front(Vector2Add(body[0], direction));
    if(addSegment == true)
    {
        addSegment = false;
    }else
    {
        body.pop_back();
    }
}

void Snake::Reset()
{
    body = {Vector2{19,17}, Vector2{18,17}, Vector2{17,17}};
    direction = {1, 0};
}