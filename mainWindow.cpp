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
#include <QtCore>

#include "mainWindow.h"






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


    int width = 26;
    int height = 26;

    PeriodicTableScene *table = new PeriodicTableScene();
//     table->setItemIndexMethod(QGraphicsScene::NoIndex);
    table->setBackgroundBrush(Qt::white);
    table->setSceneRect(0, 0, (pseTables::instance()->getTabletype( 0 )->coordsMax().x() + 1) * width, (pseTables::instance()->getTabletype( 0 )->coordsMax().y() + 1) * height);




    foreach (int intElement, pseTables::instance()->getTabletype( 0 )->elements()) {
      ElementItem *item = new ElementItem(intElement);
//       item->setPos( pseTables::instance()->getTabletype( 0 )->elementCoords( intElement ).x() * width, pseTables::instance()->getTabletype( 0 )->elementCoords( intElement ).y() * height);
      item->setZValue(intElement);
      m_elementItems << item;
      table->addItem(item);
    }

  // States
    QState *rootState = new QState;
    rootState->setObjectName("root");
    QState *regularState = new QState(rootState);
    QState *longState = new QState(rootState);
//     QState *centeredState = new QState(rootState);

    // Values
    for (int i = 0; i < m_elementItems.count(); ++i) {
        ElementItem *item = m_elementItems.at(i);

        regularState->assignProperty(item, "pos",
                                         QPointF(pseTables::instance()->getTabletype( 0 )->elementCoords( i + 1 ).x() * width,
                                                 pseTables::instance()->getTabletype( 0 )->elementCoords( i + 1 ).y() * height));


        longState->assignProperty(item, "pos",
                                         QPointF(pseTables::instance()->getTabletype( 2 )->elementCoords( i + 1 ).x() * width,
                                                 pseTables::instance()->getTabletype( 2 )->elementCoords( i + 1 ).y() * height));

	// Centered
//         centeredState->assignProperty(item, "pos", QPointF());
    }


    PeriodicTableView *ps = new PeriodicTableView(table);

   mainLayout->addWidget(ps);


    states.addState(rootState);
    states.setInitialState(rootState);
    rootState->setInitialState(regularState);


    QParallelAnimationGroup *group = new QParallelAnimationGroup;
    for (int i = 0; i < m_elementItems.count(); ++i) {
        QPropertyAnimation *anim = new QPropertyAnimation(m_elementItems.at(i), "pos");
//         anim->setDuration(750 + i * 25);
        anim->setDuration( 1400 + i * 2);
//         anim->setEasingCurve(QEasingCurve::InOutBack);
	 anim->setEasingCurve(QEasingCurve::InOutExpo);
        group->addAnimation(anim);
    }


    QAbstractTransition *trans = rootState->addTransition(this, SIGNAL(regularTable()), regularState);
    trans->addAnimation(group);

    trans = rootState->addTransition(this, SIGNAL(longTable()), longState);
    trans->addAnimation(group);


//     QTimer timer;
//     timer.start(125);
//     timer.setSingleShot(true);
//     trans = rootState->addTransition(&timer, SIGNAL(timeout()), regularState);
//     trans->addAnimation(group);


    states.start();


   connect(tables, SIGNAL(currentIndexChanged(int)), this, SLOT(slotChangeTable(int)));

//    connect(resetButton, SIGNAL(clicked()), ps, SIGNAL(resetElements()));
 }


 void mainWindow::slotChangeTable(int table)
{

   switch(table){
     case 0:
       emit regularTable();
       qDebug() << "regular Table emited";
       break;

     case 2:
       emit longTable();
       qDebug() << "long Table emited";
       break;


   }

}


#include "mainWindow.moc"