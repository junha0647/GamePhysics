#include "Walker.h"
#include "InputHandler.h"

Walker::Walker() 
{
  target = new Vector2D(0, 0);
  m_vehicle = new Vehicle(100, 100);
}

void Walker::update() 
{
  target = TheInputHandler::Instance()->getMousePosition();

  m_vehicle->seek(target);

  m_vehicle->update();

}

void Walker::draw(SDL_Renderer* renderer)
{
  filledCircleColor(renderer,
    target->getX(), target->getY(), 16,
    0xFF0000FF);
  
  m_vehicle->show(renderer);
}

//2022.04.29 Git - Replit 연동하기