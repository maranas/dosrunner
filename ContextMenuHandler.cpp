#include "StdAfx.h"
#include "resource.h"
#include "ContextMenuHandler.h"
#include "DOSRunnerShell.h"
#include <iostream>
#include <fstream>
using namespace std;

/////////////////////////////////////////////////////////////////////////////
// CContextMenuHandler

STDMETHODIMP CContextMenuHandler::Initialize (
    LPCITEMIDLIST pidlFolder, LPDATAOBJECT pDataObj, HKEY hProgID )
{
FORMATETC fmt = { CF_HDROP, NULL, DVASPECT_CONTENT, -1, TYMED_HGLOBAL };
STGMEDIUM stg = { TYMED_HGLOBAL };
HDROP     hDrop;
// Load SHELL32.DLL, if it isn't already
hShell32 = LoadLibrary("shell32.dll");
FileIconInit = (FII_PROC)    GetProcAddress(hShell32, (LPCSTR)660);


    //Directory background
	if ( NULL == pDataObj )
	{
		return S_OK;
	}

    if ( FAILED( pDataObj->GetData ( &fmt, &stg ) ))
    {
      return E_INVALIDARG;
    }

    hDrop = (HDROP) GlobalLock ( stg.hGlobal );

    if ( NULL == hDrop )
        return E_INVALIDARG;

	UINT uNumFiles = DragQueryFile ( hDrop, 0xFFFFFFFF, NULL, 0 );
	HRESULT hr = S_OK;
	// return E_INVALIDARG if there are no items selected
    if ( 0 == uNumFiles )
    {
      GlobalUnlock ( stg.hGlobal );
      ReleaseStgMedium ( &stg );
      return E_INVALIDARG;
    }

    // m_szFile = full path of item.
    if ( 0 == DragQueryFileW ( hDrop, 0, m_szFile, MAX_PATH ) )
        hr = E_INVALIDARG;

    GlobalUnlock ( stg.hGlobal );
    ReleaseStgMedium ( &stg );

    if ( PathIsDirectoryW(m_szFile) )
		m_bFolder = TRUE;
	else
		m_bFolder = FALSE;

    return hr;
}

STDMETHODIMP CContextMenuHandler::QueryContextMenu (
    HMENU hmenu, UINT uMenuIndex, UINT uidFirstCmd,
    UINT uidLastCmd, UINT uFlags )
{
    // Criteria
    if (( uFlags & CMF_DEFAULTONLY ))
        return MAKE_HRESULT ( SEVERITY_SUCCESS, FACILITY_NULL, 0 );

    UINT uID = uidFirstCmd;

    if ( !m_bFolder )
	{
      InsertMenu(hmenu, uMenuIndex, MF_SEPARATOR | MF_BYPOSITION, 0,
                          NULL);
      uMenuIndex++;
      InsertMenu ( hmenu, uMenuIndex, MF_BYPOSITION, uID++, _T("Run in DosBOX") );
	  uMenuIndex++;
      InsertMenu(hmenu, uMenuIndex, MF_SEPARATOR | MF_BYPOSITION, 0,
                          NULL);
	}
    return MAKE_HRESULT ( SEVERITY_SUCCESS, FACILITY_NULL, uID - uidFirstCmd );
}

STDMETHODIMP CContextMenuHandler::GetCommandString (
    UINT_PTR idCmd, UINT uFlags, UINT* pwReserved, LPSTR pszName, UINT cchMax )
{
USES_CONVERSION;

    LPCTSTR szText;
    switch( idCmd )
	{
      case 0:
		  szText = _T("Run in DOSBox");
	    break;
	  default:
        return E_INVALIDARG;	    
	}

    if ( uFlags & GCS_HELPTEXT )
    {
        if ( uFlags & GCS_UNICODE )
            {
              lstrcpynW ( (LPWSTR) pszName, T2CW(szText), cchMax );
            }
        else
            {
              lstrcpynA ( pszName, T2CA(szText), cchMax );
            }
        return S_OK;
    }

    return E_INVALIDARG;
}

STDMETHODIMP CContextMenuHandler::InvokeCommand ( LPCMINVOKECOMMANDINFO pCmdInfo )
{
	int cchMax = MAX_PATH;
    if ( 0 != HIWORD( pCmdInfo->lpVerb ) )
        return E_INVALIDARG;

	wchar_t buffer[MAX_PATH] = L"";
	wchar_t path_to_config[MAX_PATH] = L"";
	wchar_t path_to_dosbox[MAX_PATH] = L"";

	GetModuleFileNameW(_AtlBaseModule.GetModuleInstance(), buffer, cchMax);
	while (wmemcmp(&(buffer[cchMax-1]), L"\\", 1) != 0)
	{
	  cchMax--;
	}
	cchMax--;
	wcsncpy(path_to_config, buffer, cchMax);
    wcsncat(path_to_config,L"\\config.ini", MAX_PATH);
	
	wchar_t filename[MAX_PATH] = L"";
	wcsncpy(filename, m_szFile, MAX_PATH);

	GetPrivateProfileStringW(
		L"dosbox",
		L"path",
		L"",
		path_to_dosbox,
		MAX_PATH,
		path_to_config
	);

    switch ( LOWORD( pCmdInfo->lpVerb) )
        {
        case 0:
			// Generate command
			wchar_t command[(MAX_PATH *2) + 5];
			wcsncpy(command, L"\"", (MAX_PATH *2) + 5);
			wcsncat(command, path_to_dosbox, (MAX_PATH*2) + 4);
			wcsncat(command, L"\" \"", (MAX_PATH) + 1);
			wcsncat(command, filename, (MAX_PATH) + 1);
			wcsncat(command, L"\"", 1);
			/* Test:
			MessageBoxW(
				 NULL,
				 command,
				 path_to_dosbox,
				 MB_OK
			);
			*/
			// Run it
			char command_mbs[(MAX_PATH *2) + 5];
			wcstombs(command_mbs, command, (MAX_PATH *2) + 5);
			WinExec(command_mbs, SW_HIDE);
	        break;
        default:
            return E_INVALIDARG;
        }
	return S_OK;
}
