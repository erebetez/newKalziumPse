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
#include <QGridLayout>
#include <QPalette>
// #include <QLayout> 
#include <QLabel> 

//Periodsystemdefinition
#include <libkdeedu/pstables.h>
#include "element.h"
#include "periodsystembase.h"

periodSystem::periodSystem(QWidget *parent)
 : QWidget(parent)
 {
   
   QGridLayout *psBase = new QGridLayout();
   //QDeclaritivView
   psBase->setContentsMargins(0,0,0,0);
   psBase->setVerticalSpacing(1);
   psBase->setHorizontalSpacing(1);
   
    int group, period;
    psTables *tables = new psTables();
    psTable  *table = tables->getTabletype( 0 );
    
    QPalette myPalette;
    
//     int maxWidth = table->coordsMax().x();

    foreach (int intElement, table->elements()) {
	if ( intElement <= 112) {
	  group = table->elementCoords( intElement ).x();
	  period = table->elementCoords( intElement ).y();
	  
	  element *Element = new element( intElement );

	  psBase->addWidget(Element, period, group);

	}
    }  
   setLayout(psBase);
 }


#include "periodsystembase.moc"
