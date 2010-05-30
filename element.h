#include <QWidget>
#include <QLabel> 
#include <QColor>
 
class element : public QLabel
{
  public:
  element(int thisElement);
//   ~periodSystem();
  

  
  private:
    void setElementColor();
    void setElementColor(int typ);
    QColor setOpenBabelColor();
    int m_elementNumber;
//     void draw();
    
  protected:
  virtual void mousePressEvent( QMouseEvent * e );  
  
};