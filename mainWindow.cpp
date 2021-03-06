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
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QSlider>
#include <QPushButton>


#include <libkdeedu/psetables.h>

#include "mainWindow.h"
#include "periodictableview.h"



mainWindow::mainWindow(QWidget *parent)
 : QWidget(parent)
 {

   QVBoxLayout *mainLayout = new QVBoxLayout(this);

   QHBoxLayout *topLayout = new QHBoxLayout();

   QPushButton *resetButton = new QPushButton();

   resetButton->setText(QString("&Reset"));

   QLabel *typ = new QLabel(QString("Typ:"));

   QComboBox *tables = new QComboBox();

   foreach (QString item, pseTables::instance()->tables()) {
      tables->addItem(item);
   }

   topLayout->addWidget(resetButton);
   topLayout->addWidget(typ);
   topLayout->addWidget(tables);

   mainLayout->addLayout(topLayout);
   PeriodicTableView *ps = new PeriodicTableView();

   mainLayout->addWidget(ps);


   connect(tables, SIGNAL(currentIndexChanged(int)), ps, SLOT(slotChangeTable(int)));

   resize( 800 , 600 );
//    connect(resetButton, SIGNAL(clicked()), ps, SIGNAL(resetElements()));
 }



#include "mainWindow.moc"