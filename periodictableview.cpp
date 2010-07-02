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
#include "statemachine.h"

#include <libkdeedu/psetables.h>


PeriodicTableView::PeriodicTableView( QWidget *parent ) : QGraphicsView(parent)
{
    setRenderHint(QPainter::Antialiasing);
    setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    setCacheMode(QGraphicsView::CacheBackground);

    m_tableTyp = 0;
    m_maxCoords = pseTables::instance()->getTabletype( m_tableTyp )->coordsMax();

    int width = 26;
    int height = 26;

    m_table = new PeriodicTableScene();
    m_table->setItemIndexMethod(QGraphicsScene::NoIndex);
    m_table->setBackgroundBrush(Qt::white);

    foreach (int intElement, pseTables::instance()->getTabletype( 0 )->elements()) {
        ElementItem *item = new ElementItem(intElement);
        item->setZValue(intElement);
        m_elementItems << item;
        m_table->addItem(item);
    }
    setScene(m_table);


    QList<QState *> tableStates;

    StateSwitcher *stateSwitcher = new StateSwitcher(&m_states);

    QParallelAnimationGroup *group = new QParallelAnimationGroup;


    for (int j = 0; j < pseTables::instance()->tables().count(); ++j)
    {
        tableStates << new QState(stateSwitcher);

        // Values for each Element
        for (int i = 0; i < m_elementItems.count(); ++i) {
            ElementItem *item = m_elementItems.at(i);

            QPoint coords = pseTables::instance()->getTabletype( j )->elementCoords( i + 1 );

            // put the not needed elements a bit away
            if ( coords.x() == 0) {
                coords.setY(-10);
            }

            tableStates.at(j)->assignProperty(item, "pos",
                                              QPointF(coords.x() * width, coords.y() * height));

            // Animation for each element
            QPropertyAnimation *anim = new QPropertyAnimation(m_elementItems.at(i), "pos");
            anim->setDuration( 1400 + i * 2);
            anim->setEasingCurve(QEasingCurve::InOutExpo);
            group->addAnimation(anim);
        }
        stateSwitcher->addState(tableStates.at(j), group, j);

    }

    connect(this , SIGNAL(tableChanged(int)), stateSwitcher, SLOT(slotSwitchState(int)));

    m_states.setInitialState(stateSwitcher);
    stateSwitcher->setInitialState(tableStates.at(0));
    m_states.start();

    connect(m_table, SIGNAL(elementChanged(int)), this, SLOT(elementClicked(int)));

}

PeriodicTableView::~PeriodicTableView()
{
    delete scene();
}

void PeriodicTableView::slotChangeTable(int tableTyp)
{
    m_tableTyp = tableTyp;
    m_maxCoords = pseTables::instance()->getTabletype( m_tableTyp )->coordsMax();
    setBiggerSceneRect();
    emit tableChanged(m_tableTyp);
}

void PeriodicTableView::setBiggerSceneRect()
{
    int width = 26;
    int height = 26;

    if (m_table->sceneRect().width() < (m_maxCoords.x() + 1) * width || m_table->sceneRect().height() < (m_maxCoords.y() + 1) * height ) {
        m_table->setSceneRect(0, 0, (m_maxCoords.x() + 1) * width, (m_maxCoords.y() + 1) * height);
    }
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
    // TODO Should find a better variant than that...
    int width = 26;
    int height = 26;

    QGraphicsView::resizeEvent(event);

    if (operator!=(m_table->sceneRect(), QRectF(0, 0, (m_maxCoords.x() + 1) * width, (m_maxCoords.y() + 1) * height)) ) {
        m_table->setSceneRect(0, 0, (m_maxCoords.x() + 1) * width, (m_maxCoords.y() + 1) * height);
    }

    fitInView(sceneRect(), Qt::KeepAspectRatio);
}



#include "periodictableview.moc"
