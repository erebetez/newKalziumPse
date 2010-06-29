/**********************************************************************
 PeriodicTableView - Periodic Table Graphics View for Avogadro

 Copyright (C) 2007-2009 by Marcus D. Hanwell

 This file is part of the Avogadro molecular editor project.
 For more information, see <http://avogadro.openmolecules.net/>

 Avogadro is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.

 Avogadro is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 02110-1301, USA.

 **********************************************************************/

//TODO removeme
#include <qdebug.h>

#include "periodictableview.h"

#include <libkdeedu/psetables.h>

// #include <QGraphicsWidget>


PeriodicTableView::PeriodicTableView( QWidget *parent ) : QGraphicsView(parent)
{

    setRenderHint(QPainter::Antialiasing);
    setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    setCacheMode(QGraphicsView::CacheBackground);

    m_tableTyp = 0;

    int width = 26;
    int height = 26;

    m_table = new PeriodicTableScene();
    m_table->setItemIndexMethod(QGraphicsScene::NoIndex);
    m_table->setBackgroundBrush(Qt::white);

    foreach (int intElement, pseTables::instance()->getTabletype( 0 )->elements()) {
        ElementItem *item = new ElementItem(intElement);
//       item->setPos( pseTables::instance()->getTabletype( 0 )->elementCoords( intElement ).x() * width, pseTables::instance()->getTabletype( 0 )->elementCoords( intElement ).y() * height);
        item->setZValue(intElement);
        m_elementItems << item;
        m_table->addItem(item);
    }
    setScene(m_table);

    // States
    QState *rootState = new QState;
    rootState->setObjectName("root");

    QList<QState *> tableStates;

    for (int j = 0; j < pseTables::instance()->tables().count(); ++j)
    {
        tableStates << new QState(rootState);

        // Values
        for (int i = 0; i < m_elementItems.count(); ++i) {
            ElementItem *item = m_elementItems.at(i);

            int x = pseTables::instance()->getTabletype( j )->elementCoords( i + 1 ).x();
            int y = pseTables::instance()->getTabletype( j )->elementCoords( i + 1 ).y();

	    // put the not needed elements a bit away
            if ( x == 0) {
                y = 10;
                x = 10;
            }

            tableStates.at(j)->assignProperty(item, "pos",
                                              QPointF(x* width, y * height));

            connect(tableStates.at(j), SIGNAL(propertiesAssigned()), this, SLOT(slotResetSceneRect()));
        }
    }

    states.addState(rootState);
    states.setInitialState(rootState);
    rootState->setInitialState(tableStates.at(0));


    QParallelAnimationGroup *group = new QParallelAnimationGroup;
    for (int i = 0; i < m_elementItems.count(); ++i) {
        QPropertyAnimation *anim = new QPropertyAnimation(m_elementItems.at(i), "pos");
//         anim->setDuration(750 + i * 25);
        anim->setDuration( 1400 + i * 2);
//         anim->setEasingCurve(QEasingCurve::InOutBack);
        anim->setEasingCurve(QEasingCurve::InOutExpo);
        group->addAnimation(anim);
    }


    QAbstractTransition *trans = rootState->addTransition(this, SIGNAL(regularTable()), tableStates.at(0));
    trans->addAnimation(group);

    trans = rootState->addTransition(this, SIGNAL(shortTable()), tableStates.at(1));
    trans->addAnimation(group);

    trans = rootState->addTransition(this, SIGNAL(longTable()), tableStates.at(2));
    trans->addAnimation(group);

    trans = rootState->addTransition(this, SIGNAL(dTable()), tableStates.at(3));
    trans->addAnimation(group);

    trans = rootState->addTransition(this, SIGNAL(dzTable()), tableStates.at(4));
    trans->addAnimation(group);


    states.start();

    connect(m_table, SIGNAL(elementChanged(int)), this, SLOT(elementClicked(int)));

}



PeriodicTableView::~PeriodicTableView()
{
    delete scene();
//     delete m_table;
}

void PeriodicTableView::slotChangeTable(int tableTyp)
{
    m_tableTyp = tableTyp;

    switch (m_tableTyp) {
    case 0:
        emit regularTable();
        qDebug() << "regular Table emited";
        break;

    case 1:
        emit shortTable();
        qDebug() << "s Table emited";
        break;

    case 2:
        emit longTable();
        qDebug() << "long Table emited";
        break;

    case 3:
        emit dTable();
        qDebug() << "d Table emited";
        break;

    case 4:
        emit dzTable();
        qDebug() << "dz Table emited";
        break;
    }
}

void PeriodicTableView::slotResetSceneRect()
{
    // TODO Should find a better variant than that...
    int width = 26;
    int height = 26;

    m_table->setSceneRect(0, 0, (pseTables::instance()->getTabletype( m_tableTyp )->coordsMax().x() + 1) * width, (pseTables::instance()->getTabletype( m_tableTyp )->coordsMax().y() + 1) * height);
}


void PeriodicTableView::elementClicked(int id)
{
    emit(elementChanged(id));
    qDebug() << "element " <<  id;
}

bool PeriodicTableView::event(QEvent *e)
{
    return QGraphicsView::event(e);
}

void PeriodicTableView::resizeEvent ( QResizeEvent * event )
{
    QGraphicsView::resizeEvent(event);
    fitInView(sceneRect(), Qt::KeepAspectRatio);
}



#include "periodictableview.moc"
