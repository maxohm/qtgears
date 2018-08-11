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

#include <QtGui>
#include <QtOpenGL>
#include "window.h"
#include "logwindow.h"
#include "glwidget.h"
#include "qtglut.h"

Window::Window()
{
	QFrame * mainFrame= new QFrame(this);
	QVBoxLayout * mainLayout = new QVBoxLayout(mainFrame);
	glWidget = new GLWidget;
	sectimer = new QTimer;
	actionTimer = new QTimer;
	logwin = new logWindow;

	setWindowTitle(tr("QtGears - glxgears for Qt"));
	mainLayout->setContentsMargins(0,0,0,0);
	setCentralWidget(mainFrame);
	mainLayout->addWidget(glWidget);

	QMenu * aboutMenu = new QMenu( this );
	aboutMenu = menuBar()->addMenu( "&About");
	QAction * aboutAction = aboutMenu->addAction("qtgears");
	QAction * aboutQtAction = aboutMenu->addAction("Qt");

	connect(sectimer, SIGNAL(timeout()), this, SLOT(secTick()));
	connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));
	connect(aboutQtAction, SIGNAL(triggered()), this, SLOT(aboutQt()));

	loop = 0;
	fpsindex = 0;
	seccnt = 0;
	memset(frames, 0, sizeof(frames));

	connect(actionTimer, SIGNAL(timeout()), this, SLOT(startAction()));
	actionTimer->setSingleShot(true);
	actionTimer->start(5);

	logwin->setWindowTitle(this->windowTitle());
	logwin->show();
	logwin->log->insertPlainText("next message in 5s...\n");
}


QString Window::aboutText(bool extensions)
{
	QString s;
	s.append("glxgears clone compiled using Qt\n");
	s.append("get sources at http://lab.bachem-it.com/opengl/qtgears/\n");
	s.append("\nGL_RENDERER: ");
	s.append(QString((char*)glGetString(GL_RENDERER)));
	s.append("\nGL_VERSION: ");
	s.append((char*)glGetString(GL_VERSION));
	s.append("\nGL_VENDOR: ");
	s.append((char*)glGetString(GL_VENDOR));
	if (extensions) {
		s.append("\nGL_EXTENSIONS : ");
		s.append((char*)glGetString(GL_EXTENSIONS));
		s.append("\n");
	}
	return (s);
}


void Window::startAction(void)
{
	loop=1;
	sectimer->start(1000);
	while(loop) {
		glWidget->action();
		QCoreApplication::processEvents();
	}
	sectimer->stop();
}

void Window::secTick(void)
{
	quint32 fpsakku=0, fpsavg;
	int i;

	frames[seccnt % FPS_BUFFER] = glWidget->frames;
	for (i=0; i<FPS_BUFFER; i++)
		fpsakku += frames[i];
	fpsavg = fpsakku / FPS_BUFFER;
	seccnt++;

	statusBar()->showMessage(QString("%1 fps        %2s-average : %3 fps")
		.arg(glWidget->frames)
		.arg(FPS_BUFFER)
		.arg(fpsavg)
	);

	if (!(seccnt % FPS_BUFFER)) {
		logwin->log->moveCursor(QTextCursor::End);
		QString s;
		s = QString("%1 frames in %2 seconds = %3 FPS\n")
				.arg(fpsakku)
				.arg(FPS_BUFFER)
				.arg(fpsavg);
		logwin->log->insertPlainText(s);
		logwin->log->ensureCursorVisible();
	}

	glWidget->frames = 0;
}

void Window::keyPressEvent(QKeyEvent *event)
{
	switch (event->key()) {
		case Qt::Key_Escape:
			loop = 0;
			QCoreApplication::exit();
			break;

		case Qt::Key_A :
			loop = !loop;
			if (loop) {
				actionTimer->start(5);
			}
			break;
	}
}

void Window::mousePressEvent (QMouseEvent * event)
{
	switch (event->button()) {
		case Qt::LeftButton:
		case Qt::MidButton:
		case Qt::RightButton:
			break;
		default:
			break;
	}
}

void Window::about()
{
	QMessageBox::information(this, this->windowTitle(), aboutText(false));
}

void Window::aboutQt()
{
	QMessageBox::aboutQt( this, this->windowTitle());
}

void Window::closeEvent(QCloseEvent* ce) {
	loop = 0;
	glWidget->cleanup();
	ce->accept();
	QCoreApplication::exit();
	return;
}
