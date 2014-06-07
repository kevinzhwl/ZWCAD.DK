#ifndef ZC_RXBOILER_H
#define ZC_RXBOILER_H

#include "ZdZChar.h"
#include "zrxnames.h"
#pragma pack (push, 8)


#define ZCRX_DECLARE_MEMBERS(CLASS_NAME) \
    virtual ZcRxClass* isA() const; \
    static ZcRxClass* gpDesc; \
    static ZcRxClass* desc(); \
    static CLASS_NAME* cast(const ZcRxObject* inPtr) \
        { return ((inPtr == NULL) || !inPtr->isKindOf(CLASS_NAME::desc())) \
          ? NULL : (CLASS_NAME*)inPtr; }; \
    static void rxInit(); \
    static void rxInit(AppNameChangeFuncPtr)


#define ZCRX_DEFINE_MEMBERS(CLASS_NAME) \
ZcRxClass* CLASS_NAME::desc() \
{ \
    if (CLASS_NAME::gpDesc != NULL) \
        return CLASS_NAME::gpDesc; \
    return CLASS_NAME::gpDesc \
        = (ZcRxClass*)((ZcRxDictionary*)zcrxSysRegistry() \
        ->at(ZCRX_CLASS_DICTIONARY))->at(ZCRX_T(#CLASS_NAME)); \
} \
ZcRxClass* CLASS_NAME::isA() const \
{ \
    if (CLASS_NAME::gpDesc != NULL) \
        return CLASS_NAME::gpDesc; \
    return CLASS_NAME::gpDesc \
        = (ZcRxClass*)((ZcRxDictionary*)zcrxSysRegistry() \
        ->at(ZCRX_CLASS_DICTIONARY))->at(ZCRX_T(#CLASS_NAME)); \
} \
ZcRxClass* CLASS_NAME::gpDesc = NULL

#include "ZdZChar.h"

extern "C" void  zcrx_abort (const ZCHAR * format, ...);
#define ZCRX_STATIC_CHECK(CLASS_NAME) \
    if (CLASS_NAME::gpDesc) { \
        ZcRxClass *pClass = \
        (ZcRxClass*)((ZcRxDictionary*)zcrxSysRegistry() \
            ->at(ZCRX_CLASS_DICTIONARY))->at(ZCRX_T(#CLASS_NAME)); \
        if (pClass) { \
            if (CLASS_NAME::gpDesc == pClass) \
                return; \
            else \
                zcrx_abort(ZCRX_T(/*MSGO*/"Class mismatch")); \
        } \
    }

#define ZCRX_NO_CONS_DEFINE_MEMBERS(CLASS_NAME,PARENT_CLASS) \
ZCRX_DEFINE_MEMBERS(CLASS_NAME); \
void CLASS_NAME::rxInit() { \
    ZCRX_STATIC_CHECK(CLASS_NAME); \
    CLASS_NAME::gpDesc = newZcRxClass(ZCRX_T(#CLASS_NAME), ZCRX_T(#PARENT_CLASS)); \
}

#define ZCRX_CONS_DEFINE_MEMBERS(CLASS_NAME,PARENT_CLASS,VERNO) \
ZCRX_DEFINE_MEMBERS(CLASS_NAME); \
static ZcRxObject * make##CLASS_NAME() { return new CLASS_NAME(); } \
static void del##CLASS_NAME(void* pObj) { delete (CLASS_NAME*)pObj; } \
void CLASS_NAME::rxInit() { \
    ZCRX_STATIC_CHECK(CLASS_NAME); \
    CLASS_NAME::gpDesc = newZcRxClass(ZCRX_T(#CLASS_NAME), ZCRX_T(#PARENT_CLASS), \
        VERNO, &make##CLASS_NAME, 0, 0, &del##CLASS_NAME); \
}

#define ZCRX_DXF_DEFINE_MEMBERS(CLASS_NAME,PARENT_CLASS,DWG_VERSION,\
              MAINTENANCE_VERSION,PROXY_FLAGS,DXF_NAME,APP) \
ZCRX_DEFINE_MEMBERS(CLASS_NAME); \
static ZcRxObject * make##CLASS_NAME() { return new CLASS_NAME(); } \
static void del##CLASS_NAME(void* pObj) { delete (CLASS_NAME*)pObj; } \
void CLASS_NAME::rxInit() { \
    ZCRX_STATIC_CHECK(CLASS_NAME); \
    CLASS_NAME::gpDesc = newZcRxClass(ZCRX_T(#CLASS_NAME), ZCRX_T(#PARENT_CLASS), \
        DWG_VERSION,MAINTENANCE_VERSION,PROXY_FLAGS, \
        &make##CLASS_NAME, ZCRX_T(#DXF_NAME), ZCRX_T(#APP), 0, &del##CLASS_NAME); \
} \
void CLASS_NAME::rxInit(AppNameChangeFuncPtr ptr) { \
    ZCRX_STATIC_CHECK(CLASS_NAME); \
    CLASS_NAME::gpDesc = newZcRxClass(ZCRX_T(#CLASS_NAME), ZCRX_T(#PARENT_CLASS), \
        DWG_VERSION,MAINTENANCE_VERSION,PROXY_FLAGS, \
        &make##CLASS_NAME, ZCRX_T(#DXF_NAME), ZCRX_T(#APP), ptr, &del##CLASS_NAME); \
}

#pragma pack (pop)
#endif
