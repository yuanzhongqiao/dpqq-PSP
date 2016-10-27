#ifndef SYNCMACHINEFORM_H
#define SYNCMACHINEFORM_H

#include "ElementForm.h"

class GeneratorStabForm;
class SyncGenerator;
class SyncMotor;

class SyncMachineForm : public SyncMachineFormBase
{
   public:
    SyncMachineForm(wxWindow* parent, SyncGenerator* syncGenerator);
    SyncMachineForm(wxWindow* parent, SyncMotor* syncMotor);
    virtual ~SyncMachineForm();

   protected:
    virtual void OnCancelButtonClick(wxCommandEvent& event) { EndModal(wxID_CANCEL); };
    virtual void OnCheckMaxReactive(wxCommandEvent& event);
    virtual void OnCheckMinReactive(wxCommandEvent& event);
    virtual void OnOKButtonClick(wxCommandEvent& event);
    virtual void OnStabilityButtonClick(wxCommandEvent& event);

    virtual bool ValidateData();
    virtual void ReplaceStaticTextLabelChar(wxStaticText* staticText, wchar_t newChar);

    SyncGenerator* m_syncGenerator;
    SyncMotor* m_syncMotor;
    wxWindow* m_parent;
};
#endif  // SYNCMACHINEFORM_H
