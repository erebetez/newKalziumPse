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


#include <openbabel/mol.h>
#include <qdebug.h>
#include <QMouseEvent>
#include "elementLabel.h"

elementLabel::elementLabel(int thisElement, QWidget *parent)
        : QLabel(parent)
{
    m_elementNumber = thisElement;
    m_normalStatusColor = 2;

    setAutoFillBackground(true);

    QString symbol = OpenBabel::etab.GetSymbol(m_elementNumber);

    setElementColor();

    setText(symbol);

    setAlignment(Qt::AlignCenter);

}

void elementLabel::setElementColor()
{
    setElementColor(m_normalStatusColor);
}

void elementLabel::setElementColor(int typ)
{
    QPalette myPalette;

    myPalette = palette();
    myPalette.setColor(QPalette::WindowText, QColor(Qt::black));

     QRadialGradient radialGrad( QPointF(size().width()/2, size().height()/2), size().height()/2);

    setFrameStyle(QFrame::Box | QFrame::Plain);
    setLineWidth(1);
    setMidLineWidth ( 0 );

//     if (ElementValue  <  m_referenzValue) then make it typ 0 (gray) or somthing like that

    switch ( typ ) {
    case 0:
	myPalette.setColor(QPalette::Window, Qt::lightGray);
        break;

    case 1:

        radialGrad.setColorAt(0, Qt::white);
        radialGrad.setColorAt(0.5, Qt::yellow);
        radialGrad.setColorAt(1, Qt::red);

        myPalette.setBrush(QPalette::Window, QBrush( radialGrad ));

        setFrameStyle(QFrame::Panel | QFrame::Sunken);
        setLineWidth(3);
        setMidLineWidth ( 3 );

        break;

    case 2:
	myPalette.setColor(QPalette::Window, setOpenBabelColor());
        break;


    default:

        break;
    }

//     myPalette.setColor(QPalette::Text, QColor(Qt::yellow));

    setPalette(myPalette);
}

QColor elementLabel::setOpenBabelColor()
{
    std::vector<double> babelColor = OpenBabel::etab.GetRGB(m_elementNumber);
    QColor color;
    color.setRgbF(babelColor[0], babelColor[1], babelColor[2]);

    return color;
}

void elementLabel::slotResetElement()
{
      setElementColor(m_normalStatusColor);
      m_isActive = false;

}

// Look vor somthing like a Pair or Hash
void elementLabel::slotSetReferenceValue( double )
{




}

void elementLabel::slotSetSheme( int sheme)
{
  // Do some check if sheme existe etc.
  //if
    m_normalStatusColor = sheme;

    setElementColor(m_normalStatusColor);


}


void elementLabel::mousePressEvent(QMouseEvent* e)
{

    qDebug() << "mousePressed " << m_elementNumber << " button " << e->button();
    if (e->button() == Qt::LeftButton ) {
      if (!m_isActive) {
        emit elementClicked(m_elementNumber);
        setElementColor(1);
	m_isActive = true;
      }
    }

}

void elementLabel::mouseMoveEvent(QMouseEvent* e)
{


    QLabel::mouseMoveEvent(e);
}


#include "elementLabel.moc"
