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
#include "periodictablescene_p.h"

  PeriodicTableView::PeriodicTableView(QWidget *parent) : QGraphicsView(parent)
  {
    // Use a small title bar (Qt::Tool) with no minimize or maximise buttons
    setWindowFlags(Qt::Dialog | Qt::Tool);

    PeriodicTableScene *table = new PeriodicTableScene;

    table->setItemIndexMethod(QGraphicsScene::NoIndex);
    table->setBackgroundBrush(Qt::white);

    setScene(table);
    setRenderHint(QPainter::Antialiasing);
//     setWindowTitle(tr("Periodic Table"));
//     resize(490, 270);
//     setFixedSize(490, 270);



    connect(table, SIGNAL(elementChanged(int)),
            this, SLOT(elementClicked(int)));
  }

  PeriodicTableView::~PeriodicTableView()
  {
    delete scene();
  }

  void PeriodicTableView::elementClicked(int id)
  {
    emit(elementChanged(id));
  }

  bool PeriodicTableView::event(QEvent *e)
  {
    return QGraphicsView::event(e);
  }

//   void PeriodicTableView::mouseDoubleClickEvent(QMouseEvent *)
//   {
//     close();
//   }

  void PeriodicTableView::resizeEvent ( QResizeEvent * event )
  {
    qDebug() << "viewport " << viewport()->size().height() << "x" << viewport()->size().width();
    qDebug() << "sizeHint " << scene()->sceneRect().height() << "x" << scene()->sceneRect().width();


    double faktor = viewport()->size().width() / scene()->sceneRect().width();


    qDebug() << faktor;
    resetTransform ();
    scale(faktor, faktor);


  }

#include "periodictableview.moc"
