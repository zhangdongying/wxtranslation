#ifndef _WX_TRANSLATION_TEST_MAINFRAME_H
#define _WX_TRANSLATION_TEST_MAINFRAME_H

#include <wx/wx.h>
#include <wx/listbox.h>

class wxTranslationTestMainFrame : public wxFrame
{
	wxListBox * m_ListBox;
	void CreateControls();
public:
	wxTranslationTestMainFrame(wxWindow * parent = NULL, wxWindowID id = wxID_ANY, 
		const wxString title = _("wxTranslation Test"));
	bool Create(wxWindow * parent = NULL, wxWindowID id = wxID_ANY, 
		const wxString title = _("wxTranslation Test"), 
		const wxPoint & pos = wxDefaultPosition,
		const wxSize & size = wxDefaultSize, 
		long style = wxCAPTION|wxSYSTEM_MENU|wxCLOSE_BOX|wxMINIMIZE_BOX|wxMAXIMIZE_BOX|wxRESIZE_BORDER);
	void RefreshData();
	DECLARE_EVENT_TABLE()
	void OnExit(wxCommandEvent & event);
	void OnSelectLanguage(wxCommandEvent & event);
	void OnToggleStatusBar(wxCommandEvent & event);
	void OnAbout(wxCommandEvent & event);
	void OnAddValue(wxCommandEvent & event);

	void OnToggleStatusBarUpdateUI(wxUpdateUIEvent & event);
};

#endif
