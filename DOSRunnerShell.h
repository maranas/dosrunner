

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 11 23:44:46 2010
 */
/* Compiler settings for .\DOSRunnerShell.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __DOSRunnerShell_h__
#define __DOSRunnerShell_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IContextMenuHandler_FWD_DEFINED__
#define __IContextMenuHandler_FWD_DEFINED__
typedef interface IContextMenuHandler IContextMenuHandler;
#endif 	/* __IContextMenuHandler_FWD_DEFINED__ */


#ifndef __ContextMenuHandler_FWD_DEFINED__
#define __ContextMenuHandler_FWD_DEFINED__

#ifdef __cplusplus
typedef class ContextMenuHandler ContextMenuHandler;
#else
typedef struct ContextMenuHandler ContextMenuHandler;
#endif /* __cplusplus */

#endif 	/* __ContextMenuHandler_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IContextMenuHandler_INTERFACE_DEFINED__
#define __IContextMenuHandler_INTERFACE_DEFINED__

/* interface IContextMenuHandler */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IContextMenuHandler;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7bdcdb1e-3d6f-11df-adb8-60fb4280aea7")
    IContextMenuHandler : public IDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IContextMenuHandlerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IContextMenuHandler * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IContextMenuHandler * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IContextMenuHandler * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IContextMenuHandler * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IContextMenuHandler * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IContextMenuHandler * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IContextMenuHandler * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IContextMenuHandlerVtbl;

    interface IContextMenuHandler
    {
        CONST_VTBL struct IContextMenuHandlerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IContextMenuHandler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IContextMenuHandler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IContextMenuHandler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IContextMenuHandler_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IContextMenuHandler_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IContextMenuHandler_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IContextMenuHandler_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IContextMenuHandler_INTERFACE_DEFINED__ */



#ifndef __DOSRunnerShellLib_LIBRARY_DEFINED__
#define __DOSRunnerShellLib_LIBRARY_DEFINED__

/* library DOSRunnerShellLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_DOSRunnerShellLib;

EXTERN_C const CLSID CLSID_ContextMenuHandler;

#ifdef __cplusplus

class DECLSPEC_UUID("7bdcdb1e-3d6f-11df-b72b-60fb4280aea7")
ContextMenuHandler;
#endif
#endif /* __DOSRunnerShellLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


