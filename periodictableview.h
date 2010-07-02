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

#ifndef PERIODICTABLEVIEW_H
#define PERIODICTABLEVIEW_H

#include <QtCore>
#include <QGraphicsView>

#include "elementitem_p.h"
#include "periodictablescene_p.h"



/**
 * @class PeriodicTableView periodictableview.h <avogadro/periodictableview.h>
 * @author Marcus D. Hanwell
 * @brief This class implements the view of the PeriodicTableScene.
 *
 * This is the class that actually draws the widget onto screen. This is
 * the class that should normally be instantiated in order to display a
 * Periodic Table.
 */
class PeriodicTableView : public QGraphicsView
{
    Q_OBJECT

public:
    /**
     * Constructor - contructs a new PeriodicTableView with an internal instance
     * of PeriodicTableScene.
     */
    explicit PeriodicTableView(QWidget *parent = 0);

    /**
     * Destructor.
     */
    ~PeriodicTableView();

private Q_SLOTS:
    /**
     * Use this slot to change the active element.
     */
    void elementClicked(int element);

    void slotChangeTable(int table);



Q_SIGNALS:
    /**
     * Signal emitted when the active element in the PeriodicTableView changes.
     */
    void elementChanged(int element);
    void tableChanged(int tableTyp);


private:
    void setBiggerSceneRect();

    /**
     * Proton number of the active element.
     */
    int m_element;

    int m_tableTyp;

    QPoint m_maxCoords;

    QStateMachine m_states;
    QList<ElementItem *> m_elementItems;

    PeriodicTableScene *m_table;

protected:
    /**
     * Generic event handler, currently defaults to calling parent class
     * (included for future compatibility)
     */
    bool event(QEvent *e);

    void resizeEvent ( QResizeEvent * event );
};



#endif

