// ContextMenuHandler.h : Declaration of CContextMenuHandler
#include "resource.h"       // main symbols
#include "DOSRunnerShell.h"

class ATL_NO_VTABLE CContextMenuHandler :
	public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CContextMenuHandler, &CLSID_ContextMenuHandler>,
	public IDispatchImpl<IContextMenuHandler, &IID_IContextMenuHandler, &LIBID_DOSRunnerShellLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
    public IShellExtInit,
    public IContextMenu
{
public:
	CContextMenuHandler() { }

	DECLARE_REGISTRY_RESOURCEID(IDR_ContextMenuHandler)

    BEGIN_COM_MAP(CContextMenuHandler)
		COM_INTERFACE_ENTRY(IContextMenuHandler)
		COM_INTERFACE_ENTRY(IDispatch)
        COM_INTERFACE_ENTRY(IShellExtInit)
        COM_INTERFACE_ENTRY(IContextMenu)
    END_COM_MAP()

public:
  DECLARE_PROTECT_FINAL_CONSTRUCT()

  // IShellExtInit
  STDMETHODIMP Initialize(LPCITEMIDLIST, LPDATAOBJECT, HKEY);

  // IContextMenu
  STDMETHODIMP GetCommandString(UINT_PTR, UINT, UINT*, LPSTR, UINT);
  STDMETHODIMP InvokeCommand(LPCMINVOKECOMMANDINFO);
  STDMETHODIMP QueryContextMenu(HMENU, UINT, UINT, UINT, UINT);

  HRESULT FinalConstruct()
  {
    return S_OK;
  }
	
  void FinalRelease() 
  {
  }

protected:
    typedef BOOL (WINAPI * SH_GIL_PROC)(HIMAGELIST *phLarge, HIMAGELIST *phSmall);
    typedef BOOL (WINAPI * FII_PROC)   (BOOL fFullInit);
    wchar_t m_szFile [MAX_PATH];
	BOOL m_bFolder;	
	FII_PROC     FileIconInit;
	HMODULE hShell32;
};


OBJECT_ENTRY_AUTO(__uuidof(ContextMenuHandler), CContextMenuHandler)