#include "Vector2D.h"
#include "math.h"
#include <iostream>
using namespace std;

Vector2D& Vector2D::Set(float r, float s){

x=r;
y=s;

}
Vector2D& Vector2D::operator +=(const Vector2D& v)
{
x+=v.x;
y+=v.y;
return *this;
}

Vector2D& Vector2D::operator -=(const Vector2D& v)
{
x-=v.x;
y-=v.y;
return *this;
}

Vector2D& Vector2D::operator *=(float t)
{

x*=t;
y*=t;

return *this;
}

Vector2D& Vector2D::operator /=(float t)
{

x/=t;
y/=t;

return *this;
}

Vector2D  Vector2D::operator -(void) const{
Vector2D yenivektor(-x,-y);
return yenivektor;

}

Vector2D Vector2D::operator +(const Vector2D& v) const
{
Vector2D vektortoplami(x+v.x,y+v.y);
return vektortoplami;

}

Vector2D Vector2D::operator *(float t) const
{
Vector2D vektorcarpimi(x*t,y*t);
return vektorcarpimi;

}

Vector2D Vector2D::operator /(float t) const
{
Vector2D vektorbolumu(x/t,y/t);
return vektorbolumu;

}
bool Vector2D::operator ==(const Vector2D& v) const
{
if(x==v.x && y==v.y)
	return true;
else
	return false;
}
	
bool Vector2D::operator !=(const Vector2D& v) const
{
if(x!=v.x && y!=v.y)
	return true;
else
	return false;
}

