/**********************************************************************
 ElementItem - Element Item, part of the Periodic Table Graphics View for
 Avogadro

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

#ifndef ELEMENTITEM_P_H
#define ELEMENTITEM_P_H

#include <QDeclarativeItem>


  /**
   * @class ElementItem
   * @author Marcus D. Hanwell
   * @brief An element item, intended to display a single element.
   *
   * This class implements a QGraphicsItem for displaying single elements in a
   * perdiodic table. It currently allows the setting of the proton number and
   * gets all other information from OpenBabel.
   */
  class ElementItem : public QDeclarativeItem
  {
    Q_OBJECT
    Q_PROPERTY(QString symbolname READ symbolname WRITE setSymbolname)

  public:

    ElementItem(QDeclarativeItem *parent = 0);

     QString symbolname() const;
     void setSymbolname(const QString &name);

  private:

    QString m_symbolname;

  };


#endif // ELEMENTITEM_P_H
