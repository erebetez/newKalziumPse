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

#ifndef PERIODSYSTEMBASE_H
#define PERIODSYSTEMBASE_H

#include <QWidget>
#include "element.h"

class periodSystem : public QWidget
{
  Q_OBJECT
  public:
  periodSystem(QWidget *parent = 0);
//   ~periodSystem();
  
  public slots:
   void slotChangeTable(int table);
  
  private:
    void createTable(int table);
    
    QList<element*> m_elementItemList;
//     void draw();
    
  
};
#endif // PERIODSYSTEMBASE_H