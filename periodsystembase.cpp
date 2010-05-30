#include <QVBoxLayout>
#include <QGridLayout>
#include <QPalette>
// #include <QLayout> 
#include <QLabel> 

//Periodsystemdefinition
#include <libkdeedu/pstables.h>

#include "periodsystembase.h"

periodSystem::periodSystem(QWidget *parent)
 : QWidget(parent)
 {
   
   QGridLayout *psBase = new QGridLayout();
   //QDeclaritivView
   psBase->setContentsMargins(0,0,0,0);
   psBase->setVerticalSpacing(0);
   psBase->setHorizontalSpacing(0);
   
    int group, period, color;
    psTables *tables = new psTables();
    psTable  *table = tables->getTabletype( 0 );
    
    QPalette myPalette;
    
    int maxWidth = table->coordsMax().x();

    foreach (int intElement, table->elements()) {
	if ( intElement <= 112) {
	  group = table->elementCoords( intElement ).x();
	  period = table->elementCoords( intElement ).y();
	  
	  color = 20 + ( ( group - maxWidth/2 ) * ( group - maxWidth/2 ) * 1.5 );

	  QLabel *TestLabel = new QLabel(QString("%1").arg(intElement));
	  TestLabel->setAutoFillBackground(true);
	  myPalette = TestLabel->palette();
// 	  QColor(color, color, color)
	  myPalette.setColor(QPalette::Window, QColor(color, color, color));

	  
	  TestLabel->setPalette(myPalette);
// 	  element *Element = new element( intElement );

	  psBase->addWidget(TestLabel, period, group);
// 	  psBase->addItem (TestLabel, period, group );

// 	  Button->update();
	}
    }  
  
   setLayout(psBase);
   
   
 }


void periodSystem::draw()
{

  
}


#include "periodsystembase.moc"
