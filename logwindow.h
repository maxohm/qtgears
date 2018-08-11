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

#ifndef _LOGWINDOW_H_
#define _LOGWINDOW_H_

#include <QDialog>
#include <QVBoxLayout>
#include <QTextEdit>

class logWindow : public QDialog
{
Q_OBJECT
public:
	logWindow();
    QVBoxLayout *vboxLayout;
    QTextEdit *log;
};

#endif // _LOGWINDOW_H_
