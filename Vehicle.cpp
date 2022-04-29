#include "Vehicle.h"
#include <math.h>

const int WIDTH = 600;
const int HEIGHT = 400;

//const float PI = 3.14f;

Vehicle::Vehicle(float x, float y)
{
  pos = new Vector2D(x, y);
  vel = new Vector2D(0, 0);
  acc = new Vector2D(0, 0);
  maxSpeed = 4;
  maxForce = 0.05f;
  r = 16;

  V_force = new Vector2D(0, 0);

  radian = 0;
  m_xy1 = new Vector2D(0, 0);
  m_xy2 = new Vector2D(0, 0);
  m_xy3 = new Vector2D(0, 0);
}

void Vehicle::seek(Vector2D* target)
{
  *V_force = *target - *pos;
  
  V_force->normalize();
  *V_force *= maxSpeed;
  
  *V_force -= *vel;
  
  V_force->limit(maxForce);
  
  applyForce(V_force);
}

void Vehicle::applyForce(Vector2D* force)
{
  *acc += *force;
}

void Vehicle::edges()
{
  if(pos->getX() > WIDTH + r)
  {
    pos->setX(-r);
  }
  else if(pos->getX() < -r)
  {
    pos->setX(WIDTH + r);
  }

  if(pos->getY() > HEIGHT + r)
  {
    pos->setY(-r);
  }
  else if(pos->getY() < -r)
  {
    pos->setY(HEIGHT + r);
  }
}

Vector2D Vehicle::rotate(float _x, float _y, float rad)
{
  /*
  // double 라디안 = 각도 * (float)(Math.PI / 180);
  radian = atan2(vel->getY(), vel->getX());

  m_x = cos(radian) * pos->getX() - sin(radian) * pos->getY();
  m_y = sin(radian) * pos->getX() + cos(radian) * pos->getY();
  */

  /*
  Vector2D* tmp = new Vector2D(0, 0);
  
  tmp->setX(cos(radian) * _x - sin(radian) * _y);
  tmp->setY(sin(radian) * _x + cos(radian) * _y);

  return *tmp;
*/
  Vector2D tmp(0,0); 
  
  tmp.setX(cos(rad) * _x - sin(rad) * _y);
  tmp.setY(sin(rad) * _x + cos(rad) * _y);

  return tmp;
}

void Vehicle::update()
{
  edges();

  radian = atan2(vel->getY(), vel->getX());
  
  *m_xy1 = rotate(-r, -r / 2, radian);
  *m_xy2 = rotate(-r, r / 2, radian);
  *m_xy3 = rotate(r, 0, radian);
    
  *vel += *acc;
  
  vel->limit(maxSpeed);
  
  *pos += *vel;
  
  *acc *= 0;
}

void Vehicle::show(SDL_Renderer* renderer)
{
  /*
  filledTrigonColor(renderer,
                -r + pos->getX(), -r / 2 + pos->getY(),
                -r + pos->getX(), r / 2 + pos->getY(),
                r + pos->getX(), pos->getY(),
                0xFFFFFFFF);
  */

  filledTrigonColor(renderer,
      m_xy1->getX() + pos->getX(), m_xy1->getY() + pos->getY(),
      m_xy2->getX() + pos->getX(), m_xy2->getY() + pos->getY(),
      m_xy3->getX() + pos->getX(), m_xy3->getY() + pos->getY(),
      0xFFFFFFFF);
}