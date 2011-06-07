/**********************************************************************
 PeriodicTableView - Periodic Table Graphics View for Avogadro

 Copyright (C) 2007-2009 by Marcus D. Hanwell
 Copyrigth (C) 2010      by Etienne Rebetez

 This is free software; you can redistribute it and/or modify
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

 #include <QDeclarativeEngine>
 #include <QDeclarativeComponent>

#include <libkdeedu/psetables.h>
#include <qdeclarativecontext.h>


PeriodicTableView::PeriodicTableView( QWidget *parent )
     : QDeclarativeView(parent)
{
//     setRenderHint(QPainter::Antialiasing);
//     setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
//     setCacheMode(QGraphicsView::CacheBackground);

    qDebug() << "register elementitem";
    qmlRegisterType<ElementItem>("ElementItem", 1,0, "ElementItem");

    qDebug() << "creating component";
    QDeclarativeComponent component( engine(),  QUrl("../qml/Element.qml" ));
   
    
    qDebug() << "set view source";
    setSource( QUrl::fromLocalFile("../qml/periodicSystem.qml") );
        
    
//     m_maxCoords = pseTables::instance()->getTabletype( m_tableTyp )->tableSize();

    // pseTables::instance()->getTabletype( 0 )->elements()
    
    for( int intElement = 1; intElement < 5; ++intElement ) {
      
        qDebug() << "cast element " << intElement;
        ElementItem *element = qobject_cast<ElementItem *>( component.create());
        
        if (element) {
	  
	  element->setSymbolname( QString::number(intElement) );
	  
	  qWarning() << "My element is the " << element->symbolname();
	  
	  QDeclarativeContext *theContext = new  QDeclarativeContext( rootContext() );

	  theContext->setContextObject( element );
	  
 	  m_elementItems << theContext;
	  
	} else {
	    qWarning() << component.errors();
	}


    }

    


//     setupStatesAndAnimation();
    

}

PeriodicTableView::~PeriodicTableView()
{
//     delete scene();
}
/*
void PeriodicTableView::setupStatesAndAnimation()
{
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

            tableStates.at(j)->assignProperty(item, "pos", QPointF(coords.x() * m_width, coords.y() * m_height));

            // Animation for each element
            QPropertyAnimation *anim = new QPropertyAnimation(m_elementItems.at(i), "pos");
            anim->setDuration( 1600 + i * 2);
            anim->setEasingCurve(QEasingCurve::InOutExpo);
            group->addAnimation(anim);
        }
        stateSwitcher->addState(tableStates.at(j), group, j);
    }

    connect(this , SIGNAL(tableChanged(int)), stateSwitcher, SLOT(slotSwitchState(int)));

    m_states.setInitialState(stateSwitcher);
    stateSwitcher->setInitialState(tableStates.at(0));
    m_states.start();
}

void PeriodicTableView::slotChangeTable(int tableTyp)
{
    m_tableTyp = tableTyp;
    m_maxCoords = pseTables::instance()->getTabletype( m_tableTyp )->tableSize();
    setBiggerSceneRect();
    emit tableChanged(m_tableTyp);
}

void PeriodicTableView::setBiggerSceneRect()
{
    QRectF newRect(0,0, m_table->sceneRect().width(), m_table->sceneRect().height());

    if (m_table->sceneRect().width() < (m_maxCoords.x() + 1) * m_width) {
        newRect.setWidth((m_maxCoords.x() + 1) * m_width);
    }

    if ( m_table->sceneRect().height() < (m_maxCoords.y() + 1) * m_height ) {
        newRect.setHeight((m_maxCoords.y() + 1) * m_height );;
    }

    m_table->setSceneRect(newRect);
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
    if (operator!=(m_table->sceneRect(), QRectF(0, 0, (m_maxCoords.x() + 1) * m_width, (m_maxCoords.y() + 1) * m_height)) ) {
        m_table->setSceneRect(0, 0, (m_maxCoords.x() + 1) * m_width, (m_maxCoords.y() + 1) * m_height);
    }

    fitInView(sceneRect(), Qt::KeepAspectRatio);
    QGraphicsView::resizeEvent(event);
}*/

#include "periodictableview.moc"
