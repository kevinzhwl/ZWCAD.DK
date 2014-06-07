
#if !defined(AFX_ZINETSTRC_H__4D0B9A84_B226_11d1_A4B1_0060B0576A88__INCLUDED_)
#define AFX_ZINETSTRC_H__4D0B9A84_B226_11d1_A4B1_0060B0576A88__INCLUDED_

#pragma pack (push, 8)


namespace ZcadInet
{
	const int StatusBase = 20000;
	enum Status
	{
		statusOk	= StatusBase,
		statusInCache,

		statusFileNotFound,						
		statusBadPath,							
		statusTooManyOpenFiles,					
		statusFileAccessDenied,					
		statusInvalidFileHandle,				
		statusDirectoryFull,					
		statusHardwareError,					
		statusSharingViolation,					
		statusDiskFull,							
		statusFileGenericError,					

		statusValidURL,
		statusNotAnURL,							
		statusNoWinInet,						
		statusOldWinInet,						
		statusNoZcadInet,						
		statusNotImplemented,					
		statusProtocolNotSupported,				

		statusCreateInternetSessionFailed,		
		statusInternetSessionConnectFailed,
		statusInternetSessionOpenFailed,

		statusInvalidAccessType,				
		statusFileOpenFailed,					
		statusHttpOpenRequestFailed,			
		statusUserCancelledTransfer,

		statusHttpBadRequest,					
		statusHttpAccessDenied,					
		statusHttpPaymentRequired,				
		statusHttpRequestForbidden,				
		statusHttpObjectNotFound,				
		statusHttpBadMethod,					
		statusHttpNoAcceptableResponse,			
		statusHttpProxyAuthorizationRequired,	
		statusHttpTimedOut,						
		statusHttpConflict,						
		statusHttpResourceGone,					
		statusHttpLengthRequired,				
		statusHttpPreconditionFailure,			
		statusHttpRequestTooLarge,				
		statusHttpUriTooLong,					
		statusHttpUnsupportedMedia,				

		statusHttpServerError,					
		statusHttpNotSupported,					
		statusHttpBadGateway,					
		statusHttpServiceUnavailable,			
		statusHttpGatewayTimeout,				
		statusHttpVersionNotSupported,			

		statusInternetError,					

		statusGenericException,

		statusUnknownError
	};
}


namespace ZcadInet
{
	enum 
	{
		TF_VALIDATE_URL		= 0x01,	
		TF_DOWNLOAD_FILE	= 0x02,
		TF_UPLOAD_FILE		= 0x04,
		TF_IGNORE_CACHE		= 0x08	
	};
}


#pragma pack (pop)
#endif	
