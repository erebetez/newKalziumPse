 
// ElementLabel::ElementLabel ( int element, Plasma::Applet *applet, QGraphicsWidget * parent )
// //         : QGraphicsItem()


	  color = 20 + ( ( group - maxWidth/2 ) * ( group - maxWidth/2 ) * 1.5 );

	  QLabel *TestLabel = new QLabel(QString("%1").arg(intElement));
	  TestLabel->setAutoFillBackground(true);
	  myPalette = TestLabel->palette();
// 	  QColor(color, color, color)
	  myPalette.setColor(QPalette::Window, QColor(color, color, color));

	  
	  TestLabel->setPalette(myPalette);