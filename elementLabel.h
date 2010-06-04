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
#ifndef ELEMENTLABEL_H
#define ELEMENTLABEL_H

#include <QWidget>
#include <QLabel>
#include <QColor>

class elementLabel : public QLabel
{
Q_OBJECT

public:
    elementLabel(int thisElement, QWidget *parent = 0);
//    ~elementLabel();

Q_SIGNALS:
    void elementClicked(int);

public Q_SLOTS:
    void slotResetElement();
    void slotSetReferenceValue(double);
    void slotSetSheme(int);

private:
    void setElementColor();
    void setElementColor(int typ);
//     int checkStateForStyle();
    QColor setOpenBabelColor();

    //could be a pair: ValueTyp and Value. Temperatur, 260K
    double m_referenceValue;

    int m_normalStatusColor;

    int m_elementNumber;

    // I don't realy need this
    bool m_isActive;

protected:
    virtual void mousePressEvent( QMouseEvent * e );
    virtual void mouseMoveEvent( QMouseEvent * e );

};

#endif // ELEMENT_H
