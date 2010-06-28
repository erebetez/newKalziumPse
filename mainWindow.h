/***************************************************************************
 *   Copyright (C) 2010 by Etienne Rebetez                                 *
 *   etienne.rebetez@oberwallis.ch                                         *
 *                                                                         *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.          *
 ***************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QtCore>

#include "elementitem_p.h"
#include "periodictableview.h"
#include "periodictablescene_p.h"

class mainWindow : public QWidget
{
  Q_OBJECT
  public:
  mainWindow(QWidget *parent = 0);
//   ~periodSystem();

 private Q_SLOTS:
  void slotChangeTable(int table);

  Q_SIGNALS:
    //     // TODO make it more generic
    void regularTable();
    void longTable();

  private:
    QStateMachine states;
    QList<ElementItem *> m_elementItems;

};

#endif // MAINWINDOW_H