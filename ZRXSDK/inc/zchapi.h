#ifndef ZCHAPI_H
#define ZCHAPI_H 1

#include "ZdZchar.h"

#pragma pack (push, 8)


class ZcDbHyperlink 
{
public:
    ZcDbHyperlink() {};
    virtual ~ZcDbHyperlink(){};
    

    enum HLinkFlags {
        kUndefined = 0,
        kConvertDwgToDwf = 0x1
    };


    virtual const ZCHAR * name() const = 0;   
    virtual void setName(const ZCHAR * cName) = 0; 


    virtual const ZCHAR * description() const = 0;  
    virtual void setDescription(const ZCHAR * cDescription) = 0;
    

    virtual const ZCHAR * subLocation() const = 0;  
    virtual void setSubLocation(const ZCHAR * cSubLocation) = 0;


    virtual const ZCHAR * getDisplayString() const = 0;  


    virtual bool isOutermostContainer() const = 0;


    virtual const int getNestedLevel() const = 0;

    virtual const long flags() const;
    virtual void setFlags(const long lFlags);
};



class ZcDbHyperlinkCollection   
{
public:
    ZcDbHyperlinkCollection();
    virtual ~ZcDbHyperlinkCollection();
   

    virtual void addHead(const ZCHAR * sName, const ZCHAR * sDescription,
                         const ZCHAR * sSubLocation = NULL) = 0;
    virtual void addTail(const ZCHAR * sName, const ZCHAR * sDescription,
                         const ZCHAR * sSubLocation = NULL) = 0;
    virtual void addAt(const int nIndex, const ZCHAR * sName,
                       const ZCHAR * sDescription,
                       const ZCHAR * sSubLocation = NULL) = 0;
    

    virtual void removeHead() = 0;
    virtual void removeTail() = 0;
    virtual void removeAt(const int nIndex) = 0;
    

    virtual int count() const = 0;
    

    virtual ZcDbHyperlink * item(const int nIndex) const = 0;
};


class ZcDbEntityHyperlinkPE : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbEntityHyperlinkPE);
    
    virtual Zcad::ErrorStatus getHyperlinkCollection(ZcDbObject * pObj, 
                                                     ZcDbHyperlinkCollection *& pcHCL,
                                                     bool bOneOnly = false, 
                                                     bool bIgnoreBlockDefinition = true) = 0;

    
    virtual Zcad::ErrorStatus getHyperlinkCollection(const ZcArray<ZcDbObjectId> *& idContainers,
                                              ZcDbHyperlinkCollection *& pcHCL,                                               
                                              bool bOneOnly = false,                                               
                                              bool bIgnoreBlockDefinition = true) = 0;

   

    virtual Zcad::ErrorStatus setHyperlinkCollection(ZcDbObject * pObj, 
                                                     ZcDbHyperlinkCollection * pcHCL) = 0;
    

    virtual Zcad::ErrorStatus getHyperlinkCount(ZcDbObject * pObj, 
                                                UINT & nCount, 
                                                bool bIgnoreBlockDefinition = true) = 0;


    virtual Zcad::ErrorStatus getHyperlinkCount(const ZcArray<ZcDbObjectId> *& idContainers, 
                                                UINT & nCount, 
                                                bool bIgnoreBlockDefinition = true) = 0;
    
    

    virtual Zcad::ErrorStatus hasHyperlink(ZcDbObject * pObj, 
                                            bool & bHasHyperlink, 
                                            bool bIgnoreBlockDefinition = true) = 0;

    

    virtual Zcad::ErrorStatus hasHyperlink(const ZcArray<ZcDbObjectId> *& idContainers, 
                                           bool & bHasHyperlink,
                                           bool bIgnoreBlockDefinition = true) = 0;

};



#define HAPI_SERVICE  ZCRX_T("ZcadHyperlinks")

#pragma pack (pop)
#endif
