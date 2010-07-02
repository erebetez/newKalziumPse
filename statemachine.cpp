
#include "statemachine.h"
#include <QDebug>


StateSwitcher::StateSwitcher(QStateMachine *machine)
    : QState(machine)
{
}


void StateSwitcher::addState(QState *state, QAbstractAnimation *animation, int id) {
    StateSwitchTransition *trans = new StateSwitchTransition(id);
    trans->setTargetState(state);
    addTransition(trans);
    trans->addAnimation(animation);
}


void StateSwitcher::slotSwitchState(int n)
{
  qDebug() << "slot switch activ " << n;
  machine()->postEvent(new StateSwitchEvent(n));
}


#include "statemachine.moc"