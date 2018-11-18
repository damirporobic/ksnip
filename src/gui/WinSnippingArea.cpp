/*
 * Copyright (C) 2018 Damir Porobic <https://github.com/damirporobic>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include "WinSnippingArea.h"

WinSnippingArea::WinSnippingArea() : AbstractSnippingArea()
{

}

QRect WinSnippingArea::selectedRectArea() const
{
    auto topLeft = mapToGlobal(mCaptureArea.topLeft());
    auto bottomRight = mapToGlobal(mCaptureArea.bottomRight());
    return {topLeft, bottomRight};
}

void WinSnippingArea::setFullScreen()
{
    auto fullScreenRect = getFullScreenRect();
    setGeometry(fullScreenRect);
    QWidget::show();
}

QPoint WinSnippingArea::getMousePosition() const
{
    return mapFromGlobal(QCursor::pos());
}

QRect WinSnippingArea::getFullScreenRect() const
{
    auto fullScreenRect = QDesktopWidget().rect();
    auto screenCount = QDesktopWidget().screenCount();
    for(int i = 0; i < screenCount; i++) {
        auto screenRect = QDesktopWidget().screenGeometry(i);
        if(screenRect.x() < fullScreenRect.x()) {
            fullScreenRect.setX(screenRect.x());
        }
        if(screenRect.y() < fullScreenRect.y()) {
            fullScreenRect.setY(screenRect.y());
        }
    }
    return fullScreenRect;
}
