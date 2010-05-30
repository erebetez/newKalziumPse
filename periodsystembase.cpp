#include <QVBoxLayout>
#include <QGridLayout>
#include <QPalette>
// #include <QLayout> 
#include <QLabel> 

//Periodsystemdefinition
#include <libkdeedu/pstables.h>
#include "element.h"
#include "periodsystembase.h"

periodSystem::periodSystem(QWidget *parent)
 : QWidget(parent)
 {
   
   QGridLayout *psBase = new QGridLayout();
   //QDeclaritivView
   psBase->setContentsMargins(0,0,0,0);
   psBase->setVerticalSpacing(1);
   psBase->setHorizontalSpacing(1);
   
    int group, period;
    psTables *tables = new psTables();
    psTable  *table = tables->getTabletype( 0 );
    
    QPalette myPalette;
    
//     int maxWidth = table->coordsMax().x();

    foreach (int intElement, table->elements()) {
	if ( intElement <= 112) {
	  group = table->elementCoords( intElement ).x();
	  period = table->elementCoords( intElement ).y();
	  
	  element *Element = new element( intElement );

	  psBase->addWidget(Element, period, group);

	}
    }  
   setLayout(psBase);
 }


#include "periodsystembase.moc"
