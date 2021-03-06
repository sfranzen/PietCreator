/*
    Copyright (C) 2010 Casey Link <unnamedrambler@gmail.com>

    This library is free software; you can redistribute it and/or modify it
    under the terms of the GNU Library General Public License as published by
    the Free Software Foundation; either version 3 of the License, or (at your
    option) any later version.

    This library is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
    License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to the
    Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
    02110-1301, USA.
*/

#ifndef DEBUGWIDGET_H
#define DEBUGWIDGET_H

#include "ui_DebugWidget.h"
#include "Command.h"
#include "FlowCompass.h"

#include <QWidget>

struct trace_step;
struct trace_action;
class ImageModel;
class DebugWidget : public QWidget, public Ui_DebugUi
{
    Q_OBJECT
public:
    DebugWidget( ImageModel* model, QWidget* parent = 0, Qt::WindowFlags f = 0 );
    virtual ~DebugWidget();

public slots:
    void slotStepped( trace_step* );
    void slotActionChanged( trace_action* );
    void slotDebugStopped();
    void slotDebugStarted();

private:
    void changeCurrent( int idx );
    Command command( int light_change, int hue_change );
    ImageModel* mImageModel;
    FlowCompass *mFlowCompass;
};

#endif // DEBUGWIDGET_H
