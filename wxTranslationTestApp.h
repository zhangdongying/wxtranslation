#ifndef _WX_TRANSLATION_TEST_APP_H
#define _WX_TRANSLATION_TEST_APP_H

#include <wx/wx.h>
#include <wx/wxTranslationHelper/wxTranslationHelper.h>

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
