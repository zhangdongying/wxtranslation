#include "wxTranslationTestMainFrame.h"
#include "wxTranslationTestApp.h"
#include <wx/textdlg.h>

enum wxTranslationTestMainFrameIDs
{
	ID_TOGGLE_STATUSBAR = 10001,
	ID_SELECT_LANGUAGE,
	ID_ADD_VALUE,
	ID_LISTBOX
};

BEGIN_EVENT_TABLE(wxTranslationTestMainFrame, wxFrame)
EVT_MENU(wxID_EXIT, wxTranslationTestMainFrame::OnExit)
EVT_MENU(wxID_ABOUT, wxTranslationTestMainFrame::OnAbout)
EVT_MENU(ID_SELECT_LANGUAGE, wxTranslationTestMainFrame::OnSelectLanguage)
EVT_MENU(ID_TOGGLE_STATUSBAR, wxTranslationTestMainFrame::OnToggleStatusBar)
EVT_MENU(ID_ADD_VALUE, wxTranslationTestMainFrame::OnAddValue)
EVT_UPDATE_UI(ID_TOGGLE_STATUSBAR, wxTranslationTestMainFrame::OnToggleStatusBarUpdateUI)
END_EVENT_TABLE()

wxTranslationTestMainFrame::wxTranslationTestMainFrame(wxWindow * parent, wxWindowID id, 
		const wxString title)
{
	Create(parent, id, title);
}

bool wxTranslationTestMainFrame::Create(wxWindow * parent, wxWindowID id, 
		const wxString title, const wxPoint & pos, const wxSize & size, long style)
{
	bool res = wxFrame::Create(parent, id, title, pos, size, style);
	if(res)
	{
		CreateControls();
	}
	return res;
}

void wxTranslationTestMainFrame::CreateControls()
{
	wxMenuBar * menuBar = new wxMenuBar;
	SetMenuBar(menuBar);

	wxMenu * fileMenu = new wxMenu;
	fileMenu->Append(wxID_EXIT, _("Exit\tAlt+F4"));

	wxMenu * viewMenu = new wxMenu;
	viewMenu->Append(ID_SELECT_LANGUAGE, _("Language"));
	viewMenu->AppendCheckItem(ID_TOGGLE_STATUSBAR, _("Status Bar"));

	wxMenu * documentMenu = new wxMenu;
	documentMenu->Append(ID_ADD_VALUE, _("Add new item to document"));

	wxMenu * helpMenu = new wxMenu;
	helpMenu->Append(wxID_ABOUT, _("About..."));

	menuBar->Append(fileMenu, _("File"));
	menuBar->Append(viewMenu, _("View"));
	menuBar->Append(documentMenu, _("Document"));
	menuBar->Append(helpMenu, _("Help"));

	wxBoxSizer * sizer = new wxBoxSizer(wxVERTICAL);
	SetSizer(sizer);

	m_ListBox = new wxListBox(this, ID_LISTBOX);
	sizer->Add(m_ListBox, 1, wxEXPAND);

	RefreshData();

	CreateStatusBar(2);
}

void wxTranslationTestMainFrame::OnExit(wxCommandEvent & event)
{
	Close();
}

void wxTranslationTestMainFrame::OnToggleStatusBar(wxCommandEvent & event)
{
	wxStatusBar * statusBar = GetStatusBar();
	if(statusBar)
	{
		SetStatusBar(NULL);
		statusBar->Destroy();
	}
	else
	{
		CreateStatusBar(2);
	}
}

void wxTranslationTestMainFrame::OnSelectLanguage(wxCommandEvent & event)
{
	if(wxGetApp().SelectLanguage())
	{
		wxGetApp().RecreateGUI();
	}
}

void wxTranslationTestMainFrame::OnAbout(wxCommandEvent & event)
{
	wxMessageBox(_("wxTranslation Test"));
}

void wxTranslationTestMainFrame::OnAddValue(wxCommandEvent & event)
{
	wxString new_value = wxGetTextFromUser(
		_("Add new item to document"), 
		_("Change some data"));
	if(!new_value.IsEmpty())
	{
		wxGetApp().GetDocument().Add(new_value);
		RefreshData();
	}
}

void wxTranslationTestMainFrame::RefreshData()
{
	m_ListBox->Freeze();
	m_ListBox->Clear();
	for(size_t i = 0; i < wxGetApp().GetDocument().Count(); i++)
	{
		m_ListBox->Append(wxGetApp().GetDocument()[i]);
	}
	m_ListBox->Thaw();
}

void wxTranslationTestMainFrame::OnToggleStatusBarUpdateUI(wxUpdateUIEvent & event)
{
	event.Check(GetStatusBar() != NULL);
}
