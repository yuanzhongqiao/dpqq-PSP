#include <wx/app.h>
#include <wx/cmdline.h>
#include <wx/event.h>
#include <wx/image.h>
#include <wx/msgdlg.h>
#include <wx/stdpaths.h>
#include <wx/textfile.h>

#include "MainFrame.h"
#include "PropertiesData.h"

// Define the MainApp
class MainApp : public wxApp
{
   public:
    MainApp() {}
    virtual ~MainApp() {}
    bool LoadInitFile(PropertiesData* propertiesData)
    {
        wxFileName fn(wxStandardPaths::Get().GetExecutablePath());
        wxTextFile file(fn.GetPath() + wxFileName::GetPathSeparator() + "config.ini");
        auto data = propertiesData->GetGeneralPropertiesData();

        if(!file.Create()) {
            if(!file.Open()) return false;

            wxString line;
            for(line = file.GetFirstLine(); !file.Eof(); line = file.GetNextLine()) {
                wxString tag = "";
                wxString tagValue = "";
                bool parseValue = false;
                for(unsigned int i = 0; i < line.Len(); ++i) {
                    if(line[i] == '=') {
                        parseValue = true;
                    } else {
                        if(parseValue)
                            tagValue += line[i];
                        else
                            tag += line[i];
                    }
                }
                // Language
                if(tag == "lang") {
                    if(tagValue == "pt-br" || tagValue == "pt") {
                        data.language = wxLANGUAGE_PORTUGUESE_BRAZILIAN;
                    } else if(tagValue == "en" || tagValue == "en-us" || tagValue == "en-uk") {
                        data.language = wxLANGUAGE_ENGLISH;
                    }
                }
                if(tag == "theme") {
                    if(tagValue == "light") {
                        data.theme = THEME_LIGHT;
                    } else if(tagValue == "dark") {
                        data.theme = THEME_DARK;
                    }
                }
            }
            file.Close();
        } else {  // Create default init file.
            if(!file.Open()) return false;

            // Default parameters.
            file.AddLine("lang=en");
            file.AddLine("theme=light");

            file.Write();
            file.Close();

            data.language = wxLANGUAGE_ENGLISH;
            data.theme = THEME_LIGHT;
            propertiesData->SetGeneralPropertiesData(data);
        }

        propertiesData->SetGeneralPropertiesData(data);
        return true;
    }

    void LoadCatalogs(wxLocale* locale, PropertiesData* propertiesData)
    {
        if(!locale->Init(propertiesData->GetGeneralPropertiesData().language, wxLOCALE_DONT_LOAD_DEFAULT)) {
            wxMessageDialog msgDialog(NULL, _("This language is not supported by the system."), _("Error"),
                                      wxOK | wxCENTRE | wxICON_ERROR);
            msgDialog.ShowModal();
        }

        wxFileName fn(wxStandardPaths::Get().GetExecutablePath());
        wxString langPath = fn.GetPath() + wxFileName::DirName("\\..\\data\\lang", wxPATH_WIN).GetPath();
        locale->AddCatalogLookupPathPrefix(langPath);
        //pt_BR
        if(propertiesData->GetGeneralPropertiesData().language == wxLANGUAGE_PORTUGUESE_BRAZILIAN) {
            if(!locale->AddCatalog(wxT("pt_BR"))) {
                wxMessageDialog msgDialog(NULL, _("Fail to load brazilian portuguese language catalog."), _("Error"),
                                          wxOK | wxCENTRE | wxICON_ERROR);
                msgDialog.ShowModal();
            }
        }
    }

    virtual bool OnInit()
    {
        // Add image handlers
        wxImage::AddHandler(new wxPNGHandler);
        wxImage::AddHandler(new wxJPEGHandler);

        PropertiesData* propertiesData = new PropertiesData();
        LoadInitFile(propertiesData);

        wxLocale* locale = new wxLocale();
        LoadCatalogs(locale, propertiesData);

        wxString openFilePath = "";

        wxCmdLineParser cmdLineParser(wxApp::argc, wxApp::argv);
        cmdLineParser.AddParam("", wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL);
        if(cmdLineParser.Parse() == 0) {
            wxCmdLineArgs args = cmdLineParser.GetArguments();
            for(auto it = args.begin(), itEnd = args.end(); it != itEnd; ++it) {
                if(it->GetKind() == wxCMD_LINE_PARAM) { openFilePath = it->GetStrVal(); }
            }
        }
        MainFrame* mainFrame = new MainFrame(NULL, locale, propertiesData, openFilePath);
#ifdef __WXMSW__
        mainFrame->SetIcon(wxICON(aaaaprogicon));
#endif
        SetTopWindow(mainFrame);
        return GetTopWindow()->Show();
    }
};

DECLARE_APP(MainApp)
IMPLEMENT_APP(MainApp)
