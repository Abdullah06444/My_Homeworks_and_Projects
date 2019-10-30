#include "Circle.h"
#include <cmath>
#include <GL/glut.h>
#include "Rectangle.h"

void Circ::draw()
{
	// Do NOT modify this function
	if (m_bMarked)
		glColor4f(0.0f, 0.0f, 0.0f, 0.5f);
	else
		glColor4f(m_col.r, m_col.g, m_col.b, 0.5f);


	glBegin(GL_TRIANGLE_FAN);

	for (int i = 0; i < 50; i++)
	{
		float theta = i * (2.0f * (float)3.14159 / 50);
		float x = m_rad * cos(theta);
		float y = m_rad * sin(theta);
		glVertex2f(x + m_pos.x, y + m_pos.y);
	}
	glEnd();

}

bool Circ::intersects(Shape* pshape)
{

	// intersection between two circles

	if (Circ * circ_pshape = dynamic_cast<Circ *>(pshape))
	{

		float distance, temp;

		temp = pow((this->m_pos.x - circ_pshape->m_pos.x), 2) + pow((this->m_pos.y - circ_pshape->m_pos.y), 2);

		distance = sqrt(temp);

		if (distance <= m_rad + circ_pshape->m_rad)
			return true;
	}

	// intersection between circle and rectangle

	else if (Rect * rect_pshape = dynamic_cast<Rect *>(pshape))
	{

		float distance_xl, distance_xr;
		float distance_yt, distance_yb;

		distance_xl = (rect_pshape->getPos().x - this->m_pos.x);
		distance_xr = (rect_pshape->getPos().x + rect_pshape->getSize().x - this->m_pos.x);
		distance_yt = (rect_pshape->getPos().y - this->m_pos.y);
		distance_yb = (rect_pshape->getPos().y + rect_pshape->getSize().y - this->m_pos.y);

		if (distance_xl <= m_rad && distance_xr >= -m_rad)
		{

			if (distance_yt <= m_rad && distance_yb >= -m_rad)
			{

				if (distance_xl >= 0 && distance_yt >= 0)
				{

					float dis;

					dis = sqrt(pow(distance_xl, 2) + pow(distance_yt, 2));

					if (dis <= m_rad)
						return true;
				}
				else if (distance_xr <= 0 && distance_yt >= 0)
				{

					float dis;

					dis = sqrt(pow(distance_xr, 2) + pow(distance_yt, 2));

					if (dis <= m_rad)
						return true;
				}
				else if (distance_xl >= 0 && distance_yb <= 0)
				{

					float dis;

					dis = sqrt(pow(distance_xl, 2) + pow(distance_yb, 2));

					if (dis <= m_rad)
						return true;
				}
				else if (distance_xr <= 0 && distance_yb <= 0)
				{

					float dis;

					dis = sqrt(pow(distance_xr, 2) + pow(distance_yb, 2));

					if (dis <= m_rad)
						return true;
				}
				else
					return true;
			}
		}
	}

	return false;
}

/*
 
 dis = m_rad*cos alpha;

 1. durumdaki koordinati
 m_pos.x			,	m_pos.y				;

 2. durumdaki koordinati
 m_pos.x+m_veldir.x	,	m_pos.x+m_veldir.y	;

 alpha = arctan(2x-1x/2y-1y);

 cos alpha;
 sin alpha;
 */
