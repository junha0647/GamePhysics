#pragma once

#include "usr/include/SDL2/SDL.h"
#include "usr/include/SDL2/SDL2_gfxPrimitives.h"

#include "Vector2D.h"
#include "Vehicle.h"

class Walker 
{
public:
  Walker();
  void update();
  void draw(SDL_Renderer* renderer);

private:
  Vector2D* target;
  Vehicle* m_vehicle;
};