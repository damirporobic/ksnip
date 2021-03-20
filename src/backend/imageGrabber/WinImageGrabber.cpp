/*
 * Copyright (C) 2018 Damir Porobic <https://github.com/damirporobic>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include "WinImageGrabber.h"

WinImageGrabber::WinImageGrabber() :
	AbstractRectAreaImageGrabber(new WinSnippingArea),
    mWinWrapper(new WinWrapper)
{
	addSupportedCaptureMode(CaptureModes::RectArea);
	addSupportedCaptureMode(CaptureModes::LastRectArea);
	addSupportedCaptureMode(CaptureModes::FullScreen);
	addSupportedCaptureMode(CaptureModes::ActiveWindow);
	addSupportedCaptureMode(CaptureModes::CurrentScreen);
}

QRect WinImageGrabber::activeWindowRect() const
{
    auto rect = mWinWrapper->getActiveWindowRect();
    return mHdpiScaler.unscale(rect);
}

QRect WinImageGrabber::fullScreenRect() const
{
    auto rect = mWinWrapper->getFullScreenRect();
    return mHdpiScaler.unscale(rect);
}

CursorDto WinImageGrabber::getCursorWithPosition() const
{
	return mWinWrapper->getCursorWithPosition();
}
