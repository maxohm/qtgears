/*
 * (c) 2008 Martin Bachem, info@bachem-it.com
 *
 * This file is part of qtgears
 *
 * qtgears is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation version 2
 *
 * qtgears is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with qtgears.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <QtGui>
#include <QWidget>
#include <QDialog>
#include <QMainWindow>
#include "glwidget.h"
#include "logwindow.h"

#define FPS_BUFFER 5

class Window : public QMainWindow
{
	Q_OBJECT

public:
	Window();
	QString aboutText(bool extensions);

private:
	GLWidget *glWidget;
	QTimer *sectimer, *actionTimer;
	logWindow * logwin;
	quint32 frameAkku;
	int loop;
	int fpsindex;
	quint32 seccnt;
	quint32 frames[FPS_BUFFER];
	quint32 getOsTicks(void);

private slots:
	void about();
	void aboutQt();
    void secTick(void);
	void startAction(void);

protected:
	void keyPressEvent(QKeyEvent *event);
	void mousePressEvent (QMouseEvent * event);
	void closeEvent( QCloseEvent* );
};

#endif // __WINDOW_H__
