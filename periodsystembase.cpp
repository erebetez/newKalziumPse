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


#include <QGridLayout>
#include <QPalette>
#include <QLabel> 

#include <qdebug.h>

//Periodsystemdefinition
#include <libkdeedu/pstables.h>
#include "element.h"
#include "periodsystembase.h"

periodSystem::periodSystem(QWidget *parent)
 : QWidget(parent)
 {
   

   //QDeclaritivView

   
   createTable(0);
   
 }

void periodSystem::createTable(int tableTyp)
{
  if (layout()) {
    
    qDebug() << "delete layout";

    delete layout();
  }
  
    foreach ( element * i, m_elementItemList ) {
        delete i;	
    }
    
    m_elementItemList.clear();
    
    QGridLayout *psBase = new QGridLayout(this);
//    psBase->setContentsMargins(0,0,0,0);
   psBase->setVerticalSpacing(1);
   psBase->setHorizontalSpacing(1);    
    
    int group, period;
    psTables *tables = new psTables();
    psTable  *table = tables->getTabletype( tableTyp );    
    
    foreach (int intElement, table->elements()) {
	  group = table->elementCoords( intElement ).x();
	  period = table->elementCoords( intElement ).y();
	  
	  element *Element = new element( intElement );
	  m_elementItemList.append(Element);
	  
	  psBase->addWidget(Element, period, group);
    }
    
    setLayout(psBase);
}


void periodSystem::slotChangeTable(int table)
{
    qDebug() << "change Table" << table;
    createTable(table);
}


#include "periodsystembase.moc"
