#ifndef ZGEOMENT_DBREGION_H
#define ZGEOMENT_DBREGION_H


#include "zdbmain.h"
#include "zdbsubeid.h"
#include "zgepnt3d.h"
#include "zgevec3d.h"

#pragma pack(push, 8)

class ZcDbRegion: public  ZcDbEntity
{
public:
    ZcDbRegion();
    virtual ~ZcDbRegion();
    ZCDB_DECLARE_MEMBERS(ZcDbRegion);

    static  
    Zcad::ErrorStatus createFromCurves(const ZcDbVoidPtrArray& curveSegments, 
                                       ZcDbVoidPtrArray& regions);

    virtual Zcad::ErrorStatus getPerimeter(double&) const;
    virtual Zcad::ErrorStatus getArea(double& regionArea) const;
    virtual void*             body() const;  
    virtual Zcad::ErrorStatus getAreaProp(
                                 const ZcGePoint3d&  origin,
                                 const ZcGeVector3d& xAxis,
                                 const ZcGeVector3d& yAxis,
                                 double&             perimeter,
                                 double&             area,
                                 ZcGePoint2d&        centroid,
                                 double              momInertia[2],
                                 double&             prodInertia,
                                 double              prinMoments[2],
                                 ZcGeVector2d        prinAxes[2],
                                 double              radiiGyration[2],
                                 ZcGePoint2d&        extentsLow,
                                 ZcGePoint2d&        extentsHigh)const;

    
    virtual Zcad::ErrorStatus getPlane(ZcGePlane& regionPlane) const;

    virtual  Zcad::ErrorStatus intersectWith(const ZcDbEntity* ent,
                                             ZcDb::Intersect   intType, 
                                             ZcGePoint3dArray& points,
                                             Zdesk::GsMarker   thisGsMarker, 
                                             Zdesk::GsMarker   otherGsMarker) const;
    virtual  Zcad::ErrorStatus intersectWith(const ZcDbEntity* ent,
                                             ZcDb::Intersect   intType, 
                                             const ZcGePlane&  projPlane,
                                             ZcGePoint3dArray& points, 
                                             Zdesk::GsMarker   thisGsMarker, 
                                             Zdesk::GsMarker   otherGsMarker) const;

    virtual Zdesk::Boolean    isNull () const;
    virtual Zcad::ErrorStatus getNormal(ZcGeVector3d&) const;

    virtual ZcDbSubentId      internalSubentId      (void* ent) const;                
    virtual void*             internalSubentPtr     (const ZcDbSubentId& id) const;   


    virtual  Zcad::ErrorStatus getSubentPathsAtGsMarker(ZcDb::SubentType     type,
                                                        Zdesk::GsMarker      gsMark, 
                                                        const ZcGePoint3d&   pickPoint,
                                                        const ZcGeMatrix3d&  viewXform, 
                                                        int&                 numPaths,
                                                        ZcDbFullSubentPath*& subentPaths, 
                                                        int                  numInserts = 0,
                                                        ZcDbObjectId* entAndInsertStack = NULL) const;

    virtual Zcad::ErrorStatus getGsMarkersAtSubentPath(
                                 const ZcDbFullSubentPath& subPath, 
                                 ZcArray<Zdesk::GsMarker>& gsMarkers) const;

    virtual ZcDbEntity*       subentPtr(const ZcDbFullSubentPath& id) const;
 
    virtual Zcad::ErrorStatus booleanOper(ZcDb::BoolOperType operation, ZcDbRegion* otherRegion);
    virtual Zcad::ErrorStatus setBody(const void* modelerBody);   

    virtual Zdesk::UInt32 numChanges() const;

    virtual Zcad::ErrorStatus getClassID(CLSID* pClsid) const;

	virtual Zcad::ErrorStatus   dwgInFields(ZcDbDwgFiler* filer);
    virtual Zcad::ErrorStatus   dwgOutFields(ZcDbDwgFiler* filer) const;

    virtual Zcad::ErrorStatus   dxfInFields(ZcDbDxfFiler* filer);
    virtual Zcad::ErrorStatus   dxfOutFields(ZcDbDxfFiler* filer) const;
	

    virtual Zcad::ErrorStatus   transformBy(const ZcGeMatrix3d& xform);
	 virtual Zcad::ErrorStatus   explode(ZcDbVoidPtrArray& entitySet) const;
	 virtual Zdesk::Boolean      worldDraw(ZcGiWorldDraw* mode);
	 virtual void  viewportDraw(ZcGiViewportDraw* mode);

};

#pragma pack(pop)

#endif