/****************************************************************************
** Copyright (c) 2021, Fougue Ltd. <http://www.fougue.pro>
** All rights reserved.
** See license at https://github.com/fougue/mayo/blob/master/LICENSE.txt
****************************************************************************/

#pragma once

#include "widget_occ_view_controller.h"
#include "theme.h"

#include <QtWidgets/QWidget>
#include <V3d_TypeOfOrientation.hxx>
#include <vector>

namespace Mayo {

class ButtonFlat;
class GuiDocument;
class WidgetClipPlanes;
class WidgetExplodeAssembly;
class IWidgetOccView;

class WidgetGuiDocument : public QWidget {
    Q_OBJECT
public:
    WidgetGuiDocument(GuiDocument* guiDoc, QWidget* parent = nullptr);

    GuiDocument* guiDocument() const { return m_guiDoc; }
    V3dViewController* controller() const { return m_controller; }
    IWidgetOccView* view() const { return m_qtOccView; }

    QColor panelBackgroundColor() const;

protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    void toggleWidgetClipPlanes(bool on);
    void toggleWidgetExplode(bool on);

    void recreateViewControls();
    QRect viewControlsRect() const;
    void layoutViewControls();
    void layoutWidgetPanel(QWidget* panel);

    ButtonFlat* createViewBtn(QWidget* parent, Theme::Icon icon, const QString& tooltip) const;

    GuiDocument* m_guiDoc = nullptr;
    IWidgetOccView* m_qtOccView = nullptr;
    WidgetOccViewController* m_controller = nullptr;
    WidgetClipPlanes* m_widgetClipPlanes = nullptr;
    WidgetExplodeAssembly* m_widgetExplodeAsm = nullptr;
    QRect m_rectControls;

    ButtonFlat* m_btnFitAll = nullptr;
    ButtonFlat* m_btnEditClipping = nullptr;
    ButtonFlat* m_btnExplode = nullptr;
    std::vector<QWidget*> m_vecWidgetForViewProj;
};

} // namespace Mayo
