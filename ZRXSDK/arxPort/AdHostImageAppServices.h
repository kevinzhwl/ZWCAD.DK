
#ifndef _ARXPORT_AD_ADHOSTIMAGEAPPSERVICES_H_
#define _ARXPORT_AD_ADHOSTIMAGEAPPSERVICES_H_ 1

#include "AdAChar.h"
//#include "..\inc\ZdCharFmt.h"
#include "..\inc\zdHostImageAppServices.h"

namespace Atil {
    class ImageFormatCodec;
    class ProgressCallbackInterface;
};

typedef ZdHostImageAppServices		AdHostImageAppServices;
#define getAdHostImageAppServices	getZdHostImageAppServices

#endif
