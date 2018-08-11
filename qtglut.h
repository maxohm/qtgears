/*
 * qtglut.h
 *
 * minimum required extract of Glut 3.7 (lib/glut_shapes.c)
 *   http://www.opengl.org/resources/libraries/glut/
 *
 * Copyright (c) Mark J. Kilgard, 1994, 1997.
 *
 */

#ifndef __QTGLUT_H__
#define __QTGLUT_H__

#include <QtOpenGL>

void glutWireCube(GLdouble size);
void glutSolidCube(GLdouble size);

void glutWireTorus(GLdouble innerRadius, GLdouble outerRadius,GLint nsides, GLint rings);
void glutSolidTorus(GLdouble innerRadius, GLdouble outerRadius, GLint nsides, GLint rings);

void glutSolidSphere(GLdouble radius, GLint slices, GLint stacks);
void glutWireSphere(GLdouble radius, GLint slices, GLint stacks);


// misc
quint32 getOsTicks(void);

#endif // __QTGLUT_H__
