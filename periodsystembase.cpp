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
#include "elementLabel.h"
#include "periodsystembase.h"

periodSystem::periodSystem(QWidget *parent)
        : QWidget(parent)
{

    setAutoFillBackground(true);
    QPalette myPalette;

    myPalette = palette();
    myPalette.setColor(QPalette::Window, QColor(Qt::lightGray));

    setPalette(myPalette);

    createTable(0);

}

void periodSystem::createTable(int tableTyp)
{
    if (layout()) {
        delete layout();
    }

    foreach ( elementLabel * i, m_elementItemList ) {
        delete i;
    }

    m_elementItemList.clear();

    QGridLayout *psBase = new QGridLayout(this);
//     psBase->setContentsMargins(0,0,0,0);
    psBase->setVerticalSpacing(1);
    psBase->setHorizontalSpacing(1);

    int group, period;
    psTable  *table = psTables::instance()->getTabletype( tableTyp );

    foreach (int intElement, table->elements()) {
        group = table->elementCoords( intElement ).x();
        period = table->elementCoords( intElement ).y();

        elementLabel *Element = new elementLabel( intElement, this);
        m_elementItemList.append(Element);

	connect(Element, SIGNAL(elementClicked(int)), this, SLOT(slotElementClicked(int)));
	connect(this, SIGNAL(resetElements()), Element, SLOT(slotResetElement()));

// 	connect(
        psBase->addWidget(Element, period, group);
    }
//     delete table;
    setLayout(psBase);
}


void periodSystem::slotChangeTable(int table)
{
    qDebug() << "change Table" << table;
    createTable(table);
}

void periodSystem::slotElementClicked(int thisElement)
{
  emit resetElements();

  qDebug() << "got the " << thisElement;

}



#include "periodsystembase.moc"
