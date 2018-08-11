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

#include <QDialog>
#include "logwindow.h"

logWindow::logWindow() {
	this->resize(500, 200);
	vboxLayout = new QVBoxLayout(this);
	vboxLayout->setContentsMargins(0, 0, 0, 0);
    log = new QTextEdit(this);
    QFont font;
    font.setFamily(QString::fromUtf8("Courier New"));
    font.setPointSize(8);
    log->setFont(font);
    vboxLayout->addWidget(log);
}
