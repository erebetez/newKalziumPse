/**********************************************************************
 PeriodicTableScene - Periodic Table Graphics Scene for Avogadro

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

#include "periodictablescene_p.h"

// #include "elementdetail_p.h"
// #include "elementtranslator.h"




#include <openbabel/data.h>

#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOption>
#include <QFont>
#include <QFontMetrics>
#include <QDebug>


// The use of postfix operators here is just fine!
// We're using int for postfix, so it's almost zero overhead
// krazy:excludeall=postfixop

  PeriodicTableScene::PeriodicTableScene(QObject *parent)
    : QGraphicsScene(parent)
  {


//     ElementDetail *detail = new ElementDetail(1);
//     detail->setPos(6.5 * width, 0.75 * height);
//     addItem(detail);

    // Connect the slot and the signal...
//     connect(this, SIGNAL(elementChanged(int)),
//             detail, SLOT(elementChanged(int)));





  }


  bool PeriodicTableScene::event(QEvent *e)
  {
    return QGraphicsScene::event(e);
  }

  void PeriodicTableScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
  {
    if (event->button() != Qt::LeftButton)
      return;

    QGraphicsItem *item = QGraphicsScene::itemAt(event->scenePos());
    if (item->data(0).toInt() > 0 && item->data(0).toInt() < 119)
      emit(elementChanged(item->data(0).toInt()));

    QGraphicsScene::mousePressEvent(event);
  }

  void PeriodicTableScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
  {
    QGraphicsScene::mouseMoveEvent(event);
  }

  void PeriodicTableScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
  {
    QGraphicsScene::mouseReleaseEvent(event);
  }


#include "periodictablescene_p.moc"
