
#ifndef ZOLEAUTO_H
#define ZOLEAUTO_H

#include "zdbmain.h"
#include <wtypes.h>
#pragma pack (push, 8)

class ZcAxOleLinkManager
{
public:
    
    virtual IUnknown* GetIUnknown(ZcDbObject* pObject) = 0;

    virtual Zdesk::Boolean SetIUnknown(ZcDbObject* pObject, IUnknown* pUnknown) = 0;

    virtual IUnknown* GetIUnknown(ZcDbDatabase* pDatabase) = 0;

    virtual Zdesk::Boolean SetIUnknown(ZcDbDatabase* pDatabase, IUnknown* pUnknown) = 0;

    virtual IDispatch* GetDocIDispatch(ZcDbDatabase* pDatabase) = 0;

    virtual Zdesk::Boolean SetDocIDispatch(ZcDbDatabase* pDatabase, IDispatch* pDispatch) = 0;

    virtual IUnknown* GetIUnknown(ZcDbObject* pObject,
        const ZcDbSubentId &id) = 0;

    virtual Zdesk::Boolean SetIUnknown(ZcDbObject* pObject,
        const ZcDbSubentId &id, IUnknown* pUnknown) = 0;
};

ZcAxOleLinkManager* ZcAxGetOleLinkManager();

#pragma pack (pop)
#endif 
