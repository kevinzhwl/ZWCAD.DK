#ifndef ZCPLPLOTERRORHANDLERLOCK_H
#define ZCPLPLOTERRORHANDLERLOCK_H


#include "ZdZChar.h"
#include "ZcPlObject.h"

class ZcPlPlotErrorHandler;

class ZcPlPlotErrorHandlerLock : public ZcPlObject
{
    ZCPL_DECLARE_MEMBERS(ZcPlPlotErrorHandlerLock);
public:
    enum LockStatus {
        kLocked,
        kUnLocked
    };

    ZCPL_PORT ZcPlPlotErrorHandlerLock();
    ZCPL_PORT ZcPlPlotErrorHandlerLock(ZcPlPlotErrorHandler* pAppErrHandler, 
                             const ZCHAR * pAppName);

    ZCPL_PORT LockStatus status() const;
    ZCPL_PORT bool lock(ZcPlPlotErrorHandler* pAppErrHandler, const ZCHAR * pAppName);
    ZCPL_PORT bool unLock(ZcPlPlotErrorHandler* pAppErrHandler);
    ZCPL_PORT void getErrorHandler(ZcPlPlotErrorHandler*& pAppErrHandler) const;
    ZCPL_PORT const ZCHAR * appName() const;
};

#endif 
