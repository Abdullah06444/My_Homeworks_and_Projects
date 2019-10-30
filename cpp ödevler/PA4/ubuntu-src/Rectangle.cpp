#include "Rectangle.h"

#include <GL/glut.h>
#include "Circle.h"
#include <cmath>
 void Rect::draw()
	{
		// Do NOT modify this function 
		if (m_bMarked)
			glColor4f(0.0f, 0.0f, 0.0f,0.5f);
		else
			glColor4f(m_col.r, m_col.g, m_col.b, 0.5f);
		glRectf(m_pos.x, m_pos.y, m_pos.x + m_size.x, m_pos.y + m_size.y);
		
	}
	
 bool Rect::intersects(Shape* pshape)
	{
		// TODO: write the implementation for this function

		return false;
	}
