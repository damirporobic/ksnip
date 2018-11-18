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

#ifndef KSNIP_X11SNIPPINGAREA_H
#define KSNIP_X11SNIPPINGAREA_H

#include "AbstractSnippingArea.h"

class X11SnippingArea : public AbstractSnippingArea
{
public:
    explicit X11SnippingArea();
    ~X11SnippingArea() override = default;
    QRect selectedRectArea() const override;

protected:
    virtual void setFullScreen();
    QPoint getMousePosition() const override;
};

#endif //KSNIP_X11SNIPPINGAREA_H
