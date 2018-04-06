#include "wxTranslationTestApp.h"
#include "wxTranslationTestMainFrame.h"
#include <wx/filename.h>

IMPLEMENT_APP(wxTranslationTestApp)

bool wxTranslationTestApp::OnInit()
{
	wxFileName appFileName(argv[0]);
	appFileName.Normalize(wxPATH_NORM_DOTS|wxPATH_NORM_ABSOLUTE|
		wxPATH_NORM_TILDE);
	m_TranslationHelper = new wxTranslationHelper(*this, appFileName.GetPath(), false);
	wxString path = appFileName.GetPath()+
		wxFileName::GetPathSeparator()+
		GetAppName()+wxT(".ini");
	m_TranslationHelper->SetConfigPath(path);
	m_TranslationHelper->Load();
	RecreateGUI();
	return true;
}

int wxTranslationTestApp::OnExit()
{
	if(m_TranslationHelper)
	{
		wxDELETE(m_TranslationHelper);
	}
	return 0;
}

wxArrayString & wxTranslationTestApp::GetDocument()
{
	return m_SomeKindOfDocument;
}

bool wxTranslationTestApp::SelectLanguage()
{
	wxArrayString names;
	wxArrayLong identifiers;	

	m_TranslationHelper->GetInstalledLanguages(names, identifiers);
	bool res = m_TranslationHelper->AskUserForLanguage(names, identifiers);	
	return res;
}

void wxTranslationTestApp::RecreateGUI()
{
	wxWindow * topwindow = GetTopWindow();
	if(topwindow)
	{
		SetTopWindow(NULL);
		topwindow->Destroy();
	}
	wxTranslationTestMainFrame * frame = new wxTranslationTestMainFrame;
	SetTopWindow(frame);
	frame->Centre();
	frame->Show();
}
