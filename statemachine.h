/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtCore module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor
**     the names of its contributors may be used to endorse or promote
**     products derived from this software without specific prior written
**     permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
** $QT_END_LICENSE$
**
****************************************************************************/

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

    StateSwitchEvent(int table)
            : QEvent(Type(StateSwitchType)),
            m_table(table)
    {}

    enum { StateSwitchType = QEvent::User + 256 };

    int table() const {
        return m_table;
    }

private:
    int m_table;
};


class StateSwitchTransition: public QAbstractTransition
{
public:
    StateSwitchTransition(int table)
            : QAbstractTransition(),
            m_table(table)
    {}

protected:

    virtual bool eventTest(QEvent *event)
    {
        return (event->type() == QEvent::Type(StateSwitchEvent::StateSwitchType))
               && (static_cast<StateSwitchEvent *>(event)->table() == m_table);
    }

    virtual void onTransition(QEvent *) {}

private:
    int m_table;
};


class StateSwitcher : public QState
{
    Q_OBJECT
public:
    StateSwitcher(QStateMachine *machine);

    void addState(QState *state, QAbstractAnimation *animation, int id);

public Q_SLOTS:
    void slotSwitchState(int n);
};

#endif // STATEMACHIEN_H
