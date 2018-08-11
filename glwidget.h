/*
 * Copyright (c) 1993-2003, Silicon Graphics, Inc.
 * All Rights Reserved
 *
 * please review readme.txt which comes with this software
 * or review http://lab.bachem-it.com/opengl/redbook/readme.txt
 * for a detailed copyright notice and warranty disclaimer.
 *
 * get a copy of the complete source code at
 *   http://www.opengl-redbook.com/code/
 *   http://lab.bachem-it.com/opengl/redbook/
 *
 */

#ifndef __GLWIDGET_H__
#define __GLWIDGET_H__

#include <QGLWidget>

#define WINDOW_WIDTH	300
#define WINDOW_HEIGHT	300

class GLWidget : public QGLWidget
{
Q_OBJECT

public:
	GLWidget(QWidget *parent = 0);
	QSize minimumSizeHint() const;
	QSize sizeHint() const;
	void action(void);

	void cleanup(void);
	void gear(GLfloat inner_radius, GLfloat outer_radius,
	          GLfloat width, GLint teeth, GLfloat tooth_depth);

	GLfloat view_rotx, view_roty, view_rotz;
	GLint gear1, gear2, gear3;
	GLfloat angle;

	GLint T0;
	GLint frames;
	GLint autoexit;
	GLint win;

protected:
	void initializeGL();
	void paintGL();
	void resizeGL(int width, int height);
};

#endif // __GLWIDGET_H__
