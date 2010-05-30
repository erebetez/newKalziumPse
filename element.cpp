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
// #include <qnamespace.h>
#include "element.h"

element::element(int thisElement)
 : QLabel()
{
    m_elementNumber = thisElement;

    setAutoFillBackground(true);
    
//  	  color = 20 + ( ( group - maxWidth/2 ) * ( group - maxWidth/2 ) * 1.5 );

    QString symbol = OpenBabel::etab.GetSymbol(m_elementNumber);

    setText(symbol);

    setAlignment(Qt::AlignCenter);
    
    setElementColor();

}

void element::setElementColor()
{
   setElementColor(-1);
}

void element::setElementColor(int typ)
{
    QColor color;
    
    
    switch( typ) {
      case 1:
	color = QColor(Qt::red);
	break;
	
      default:
	color = setOpenBabelColor();
	break;
    }
    
    QPalette myPalette;
    
    myPalette = palette();

    myPalette.setColor(QPalette::Window, color);

    setPalette(myPalette);
}

QColor element::setOpenBabelColor()
{
   std::vector<double> babelColor = OpenBabel::etab.GetRGB(m_elementNumber);
    QColor color;
    color.setRgbF(babelColor[0], babelColor[1], babelColor[2]);
    
    return color;
  
}



void element::mousePressEvent(QMouseEvent* e)
{

    qDebug() << "mousePressed " << m_elementNumber << " button " << e->button(); 
    if (e->button() == Qt::LeftButton ) {
	setElementColor(1);
    }

}
