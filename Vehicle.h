#pragma once

#include "Vector2D.h"
#include "usr/include/SDL2/SDL2_gfxPrimitives.h"

class Vehicle
{
public:
  Vehicle(float x, float y);
  void seek(Vector2D* target);
  void applyForce(Vector2D* force);
  void edges();
  Vector2D rotate(float _x, float _y, float rad);
  void update();
  void show(SDL_Renderer* renderer);

private:
  Vector2D* pos;
  Vector2D* vel;
  Vector2D* acc;
  float maxSpeed;
  float maxForce;
  float r;

  Vector2D* V_force;

  double radian;
  Vector2D* m_xy1;
  Vector2D* m_xy2;
  Vector2D* m_xy3;
};