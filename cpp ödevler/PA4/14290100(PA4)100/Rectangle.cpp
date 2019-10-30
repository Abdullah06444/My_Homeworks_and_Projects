#include "Rectangle.h"
#include <GL/glut.h>
#include "Circle.h"
#include <cmath>
void Rect::draw()
{
	// Do NOT modify this function 
	if (m_bMarked)
		glColor4f(0.0f, 0.0f, 0.0f, 0.5f);
	else
		glColor4f(m_col.r, m_col.g, m_col.b, 0.5f);
	glRectf(m_pos.x, m_pos.y, m_pos.x + m_size.x, m_pos.y + m_size.y);
}

bool Rect::intersects(Shape* pshape)
{

	// intersection between two rectangles

	if (Rect * rect_pshape = dynamic_cast<Rect *>(pshape))
	{

		float distance_xll, distance_xlr, distance_xrl, distance_xrr;
		float distance_ytt, distance_ytb, distance_ybt, distance_ybb;

		distance_xll = this->m_pos.x - rect_pshape->m_pos.x;
		distance_xlr = this->m_pos.x - (rect_pshape->m_pos.x + rect_pshape->m_size.x);
		distance_xrl = (this->m_pos.x + this->m_size.x) - rect_pshape->m_pos.x;
		distance_xrr = (this->m_pos.x + this->m_size.x) - (rect_pshape->m_pos.x + rect_pshape->m_size.x);

		distance_ytt = this->m_pos.y - rect_pshape->m_pos.y;
		distance_ytb = this->m_pos.y - (rect_pshape->m_pos.y + rect_pshape->m_size.y);
		distance_ybt = (this->m_pos.y + this->m_size.y) - rect_pshape->m_pos.y;
		distance_ybb = (this->m_pos.y + this->m_size.y) - (rect_pshape->m_pos.y + rect_pshape->m_size.y);

		if (distance_xrl <= 0 && distance_xlr >= 0)
		{

			if (distance_ytb <= 0 && distance_ybt >= 0)
				return true;

			else if (distance_ybt <= 0 && distance_ytb >= 0)
				return true;
		}

		else if (distance_xlr <= 0 && distance_xrl >= 0)
		{

			if (distance_ytb <= 0 && distance_ybt >= 0)
				return true;

			else if (distance_ybt <= 0 && distance_ytb >= 0)
				return true;
		}

	}

	// intersection between rectangle and circle

	else if (Circ * circ_pshape = dynamic_cast<Circ *>(pshape))
	{

		float distance_xl, distance_xr;
		float distance_yt, distance_yb;

		distance_xl = (this->m_pos.x - circ_pshape->getPos().x);
		distance_xr = (this->m_pos.x + this->m_size.x - circ_pshape->getPos().x);
		distance_yt = (this->m_pos.y - circ_pshape->getPos().y);
		distance_yb = (this->m_pos.y + this->m_size.y - circ_pshape->getPos().y);

		if (distance_xl <= circ_pshape->getRad() && distance_xr >= -circ_pshape->getRad())
		{

			if (distance_yt <= circ_pshape->getRad() && distance_yb >= -circ_pshape->getRad())
			{

				if (distance_xl >= 0 && distance_yt >= 0)
				{

					float dis;

					dis = sqrt(pow(distance_xl, 2) + pow(distance_yt, 2));

					if (dis <= circ_pshape->getRad())
						return true;
				}
				else if (distance_xr <= 0 && distance_yt >= 0)
				{

					float dis;

					dis = sqrt(pow(distance_xr, 2) + pow(distance_yt, 2));

					if (dis <= circ_pshape->getRad())
						return true;
				}
				else if (distance_xl >= 0 && distance_yb <= 0)
				{

					float dis;

					dis = sqrt(pow(distance_xl, 2) + pow(distance_yb, 2));

					if (dis <= circ_pshape->getRad())
						return true;
				}
				else if (distance_xr <= 0 && distance_yb <= 0)
				{

					float dis;

					dis = sqrt(pow(distance_xr, 2) + pow(distance_yb, 2));

					if (dis <= circ_pshape->getRad())
						return true;
				}
				else
					return true;
			}
		}
	}

	return false;
}

