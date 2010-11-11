// DOSRunnerShell.cpp : Implementation of DLL Exports.

#include "stdafx.h"
#include "resource.h"
#include "DOSRunnerShell.h"

#include "ContextMenuHandler.h"

class CDOSRunnerShellModule : public CAtlDllModuleT< CDOSRunnerShellModule >
{
public :
	DECLARE_LIBID(LIBID_DOSRunnerShellLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_DOSRunnerShell, "{7bdcdb1e-3d6f-11df-8122-60fb4280aea7}")
};

CDOSRunnerShellModule _AtlModule;

BEGIN_OBJECT_MAP(ObjectMap)
OBJECT_ENTRY(CLSID_ContextMenuHandler, CContextMenuHandler)
END_OBJECT_MAP()

// DLL Entry Point
extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
    return _AtlModule.DllMain(dwReason, lpReserved); 
}


// Used to determine whether the DLL can be unloaded by OLE
STDAPI DllCanUnloadNow(void)
{
    return _AtlModule.DllCanUnloadNow();
}


// Returns a class factory to create an object of the requested type
STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
    return _AtlModule.DllGetClassObject(rclsid, riid, ppv);
}


// DllRegisterServer - Adds entries to the system registry
STDAPI DllRegisterServer(void)
{
   if ( 0 == (GetVersion() & 0x80000000UL) )
   {
	   CRegKey reg;
	   LONG    lRet;

	   lRet = reg.Open ( HKEY_LOCAL_MACHINE,
		   _T("Software\\Microsoft\\Windows\\CurrentVersion\\Shell Extensions\\Approved"),
		   KEY_SET_VALUE );

	   if ( ERROR_SUCCESS != lRet )
		   return E_ACCESSDENIED;

	   lRet = reg.SetValue ( _T("DOSRunnerContextMenuHandler"), 
		   _T("{7bdcdb1e-3d6f-11df-b72b-60fb4280aea7}") );

	   if ( ERROR_SUCCESS != lRet )
		   return E_ACCESSDENIED;
   }

    // registers object, typelib and all interfaces in typelib
    HRESULT hr = _AtlModule.DllRegisterServer();
	return hr;
}


// DllUnregisterServer - Removes entries from the system registry
STDAPI DllUnregisterServer(void)
{
    if ( 0 == (GetVersion() & 0x80000000UL) )
	{
		CRegKey reg;
        LONG    lRet;

        lRet = reg.Open ( HKEY_LOCAL_MACHINE,
			_T("Software\\Microsoft\\Windows\\CurrentVersion\\Shell Extensions\\Approved"),
			KEY_SET_VALUE );

		if ( ERROR_SUCCESS == lRet )
		{
			lRet = reg.DeleteValue ( _T("{7bdcdb1e-3d6f-11df-b72b-60fb4280aea7}") );
		}
	}

	HRESULT hr = _AtlModule.DllUnregisterServer();
	return hr;
}
