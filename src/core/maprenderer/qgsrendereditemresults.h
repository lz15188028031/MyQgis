/***************************************************************************
  qgsrendereditemresults.h
  -------------------
   begin                : August 2021
   copyright            : (C) Nyall Dawson
   email                : nyall dot dawson at gmail dot com
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef QGSRENDEREDITEMRESULTS_H
#define QGSRENDEREDITEMRESULTS_H

#include "qgis_core.h"
#include "qgis_sip.h"
#include <memory>
#include <QList>
#include <vector>

class QgsRenderedItemDetails;
class QgsRenderContext;
class QgsRenderedAnnotationItemDetails;
class QgsRectangle;

///@cond PRIVATE
class QgsRenderedItemResultsSpatialIndex;
///@endcond

/**
 * \ingroup core
 * \brief Stores collated details of rendered items during a map rendering operation.
 * \since QGIS 3.22
 */
class CORE_EXPORT QgsRenderedItemResults
{
  public:
    QgsRenderedItemResults();
    ~QgsRenderedItemResults();

    //! QgsRenderedItemResults cannot be copied.
    QgsRenderedItemResults( const QgsRenderedItemResults & ) = delete;
    //! QgsRenderedItemResults cannot be copied.
    QgsRenderedItemResults &operator=( const QgsRenderedItemResults &rh ) = delete;

    /**
     * Returns a list of all rendered items.
     */
    QList< QgsRenderedItemDetails * > renderedItems() const;

    /**
     * Returns a list with details of the rendered annotation items within the specified \a bounds.
     *
     * \since QGIS 3.22
     */
    QList<const QgsRenderedAnnotationItemDetails *> renderedAnnotationItemsInBounds( const QgsRectangle &bounds ) const;

#ifndef SIP_RUN

    /**
     * Appends rendered item details to the results object.
     *
     * Ownership of \a results is transferred to the this object.
     *
     * The render \a context argument is used to specify the render context used to render the items. It will be used
     * to transform the details to the destination map CRS.
     *
     * \note Not available in Python bindings.
     */
    void appendResults( const QList< QgsRenderedItemDetails * > &results, const QgsRenderContext &context );
#endif

  private:
#ifdef SIP_RUN
    QgsRenderedItemResults( const QgsRenderedItemResults & );
#endif

    std::vector< std::unique_ptr< QgsRenderedItemDetails > > mDetails;
    std::unique_ptr< QgsRenderedItemResultsSpatialIndex > mAnnotationItemsIndex;

};

#endif // QGSRENDEREDITEMRESULTS_H