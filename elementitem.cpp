/**********************************************************************
 ElementItem - Element Item, part of the Periodic Table Graphics View for
 Avogadro

 Copyright (C) 2007-2009 by Marcus D. Hanwell
 Some portions (C) 2010 by Konstantin Tokarev

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

#include "elementitem.h"
// #include "elementtranslator.h"

#include <openbabel/mol.h>


ElementItem::ElementItem(QDeclarativeItem *parent)
: QDeclarativeItem(parent)
{
}

  
QString ElementItem::symbolname() const
{
   return m_symbolname;
}

void ElementItem::setSymbolname(const QString &name)
{
   m_symbolname = name;
}


#include "elementitem.moc"
