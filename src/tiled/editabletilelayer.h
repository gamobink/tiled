/*
 * editabletilelayer.h
 * Copyright 2018, Thorbjørn Lindeijer <bjorn@lindeijer.nl>
 *
 * This file is part of Tiled.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "editablelayer.h"
#include "regionvaluetype.h"
#include "tilelayer.h"

namespace Tiled {
namespace Internal {

class EditableTileLayer : public EditableLayer
{
    Q_OBJECT

    Q_PROPERTY(int width READ width)
    Q_PROPERTY(int height READ height)
    Q_PROPERTY(QSize size READ size)
    Q_PROPERTY(Tiled::Cell cell READ cell)

public:
    explicit EditableTileLayer(EditableMap *map,
                               TileLayer *layer,
                               QObject *parent = nullptr);

    int width() const;
    int height() const;
    QSize size() const;

    Q_INVOKABLE Tiled::Internal::RegionValueType region() const;

    Tiled::Cell cell() const { return Tiled::Cell(); }
    Q_INVOKABLE Tiled::Cell cellAt(int x, int y) const;

signals:

public slots:

private:
    TileLayer *tileLayer() const;
};


inline int EditableTileLayer::width() const
{
    return tileLayer()->width();
}

inline int EditableTileLayer::height() const
{
    return tileLayer()->height();
}

inline QSize EditableTileLayer::size() const
{
    return tileLayer()->size();
}

inline TileLayer *EditableTileLayer::tileLayer() const
{
    return static_cast<TileLayer*>(layer());
}

} // namespace Internal
} // namespace Tiled

Q_DECLARE_METATYPE(Tiled::Internal::EditableTileLayer*)
