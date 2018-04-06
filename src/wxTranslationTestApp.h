#ifndef _WX_TRANSLATION_TEST_APP_H
#define _WX_TRANSLATION_TEST_APP_H

#include <wx/wx.h>
#include <wx/intl.h>

class wxTranslationHelper
{
	wxApp & m_App;
	wxString m_SearchPath;
	wxString m_ConfigPath;
	wxLocale * m_Locale;
	bool m_UseNativeConfig;
public:
	wxTranslationHelper(wxApp & app, const wxString & search_path, bool use_native_config = true);
	~wxTranslationHelper();
	wxLocale * GetLocale();
	void GetInstalledLanguages(wxArrayString & names, wxArrayLong & identifiers);
	bool AskUserForLanguage(wxArrayString & names, wxArrayLong & identifiers);
	bool Load();
	void Save(bool bReset = false);

	const wxString & GetSearchPath();
	void SetSearchPath(wxString & value);

	const wxString & GetConfigPath();
	void SetConfigPath(wxString &);
};

class wxTranslationTestApp : public wxApp
{
	wxTranslationHelper * m_TranslationHelper;
	wxArrayString m_SomeKindOfDocument;
public:
	virtual bool OnInit();
	virtual int OnExit();
	void RecreateGUI();
	bool SelectLanguage();
	wxArrayString & GetDocument();
};

DECLARE_APP(wxTranslationTestApp);

#endif
