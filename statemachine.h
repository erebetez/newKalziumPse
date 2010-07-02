
#ifndef STATEMACHIEN_H
#define STATEMACHIEN_H

#include <QtCore>


class StateSwitchEvent: public QEvent
{
public:
    StateSwitchEvent()
	: QEvent(Type(StateSwitchType))
    {
    }

    StateSwitchEvent(int rand)
	: QEvent(Type(StateSwitchType)),
	  m_rand(rand)
    {
      qDebug() << "event: " << rand;
    }

    enum { StateSwitchType = QEvent::User + 256 };

    int rand() const { return m_rand; }

private:
    int m_rand;
};


class StateSwitchTransition: public QAbstractTransition
{
public:
    StateSwitchTransition(int rand)
	: QAbstractTransition(),
	  m_rand(rand)
    {
      qDebug() << "transition " << rand;
    }

protected:

    virtual bool eventTest(QEvent *event)
    {
      qDebug() << static_cast<StateSwitchEvent *>(event)->rand() << " == " << m_rand;

	return (event->type() == QEvent::Type(StateSwitchEvent::StateSwitchType))
	    && (static_cast<StateSwitchEvent *>(event)->rand() == m_rand);
    }


    virtual void onTransition(QEvent *) {}

private:
    int m_rand;
};


class StateSwitcher : public QState
{
    Q_OBJECT
public:
    StateSwitcher(QStateMachine *machine);



    void addState(QState *state, QAbstractAnimation *animation, int id);

public Q_SLOTS:
   void slotSwitchState(int n);

private:

};

#endif // STATEMACHIEN_H