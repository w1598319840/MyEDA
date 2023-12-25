#include"ContainView.h"
#include <wx/wx.h>


ContainView::ContainView(const wxString& title, const wxSize& size, MyPanel* myPanel, int index) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, size)
{
	this->index = index;
	this->myPanel = myPanel;
	Component component = allComponent[index];
	string modifiedContent = "name：" + component.name;
	SetPosition(wxPoint(40, 40));
	wxPanel* panel = new wxPanel(this, wxID_ANY);

	wxTextCtrl* text1 = new wxTextCtrl(panel, wxID_ANY, modifiedContent, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);

	text1->SetPosition(wxPoint(10, 10));
	text1->SetSize(wxSize(500, 30));

	Show();
}