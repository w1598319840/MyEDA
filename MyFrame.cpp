#include "MyFrame.h"
#include "ContainView.h"
#include <wx/wx.h>
#include <ctime>

MyPanel::MyPanel(wxFrame* parent) : wxPanel(parent) {
	Bind(wxEVT_PAINT, &MyPanel::OnPaint, this);
	wxButton* button1 = new wxButton(this, wxID_ANY, "添加电气元件", wxPoint(20, 20), wxSize(80, 30));
	button1->Bind(wxEVT_BUTTON, &MyPanel::OnButton1Click, this);

	Bind(wxEVT_MOTION, &MyPanel::OnMouseMove, this);
	Bind(wxEVT_LEFT_DOWN, &MyPanel::OnMouseLeftDown, this);
	Bind(wxEVT_LEFT_UP, &MyPanel::OnMouseLeftUp, this);
	Bind(wxEVT_LEFT_DCLICK, &MyPanel::OnMouseDoubleClick, this);

}

void MyPanel::OnMouseMove(wxMouseEvent& event) {
	if (isDragging) {
		if (cur == -1)return;

		// 计算鼠标移动的距离
		int disX = event.GetPosition().x - originalX;
		int disY = event.GetPosition().y - originalY;
		//disX /= 10; disY /= 10;
		allComponent[cur].centerX += disX;
		allComponent[cur].centerY += disY;
		originalX += disX;
		originalY += disY;
		for (int i = 0; i < allComponent[cur].vLine.size(); i++) {
			allComponent[cur].vLine[i].centerx += disX;
			allComponent[cur].vLine[i].centery += disY;
		}
		for (int i = 0; i < allComponent[cur].vRectangle.size(); i++) {
			allComponent[cur].vRectangle[i].centerx += disX;
			allComponent[cur].vRectangle[i].centery += disY;
		}
		for (int i = 0; i < allComponent[cur].vCircle.size(); i++) {
			allComponent[cur].vCircle[i].centerx += disX;
			allComponent[cur].vCircle[i].centery += disY;
		}
		for (int i = 0; i < allComponent[cur].vCurve.size(); i++) {
			allComponent[cur].vCurve[i].centerx += disX;
			allComponent[cur].vCurve[i].centery += disY;
		}
		for (int i = 0; i < allComponent[cur].vText.size(); i++) {
			allComponent[cur].vText[i].centerx += disX;
			allComponent[cur].vText[i].centery += disY;
		}
		//cout << cur << " " << allComponent[cur].vLine[0].x1 << " " << allComponent[cur].vLine[0].y1 << endl;
		b = clock();
		if (b - a > 1000 / 60)Refresh(), a = clock();
	}

	event.Skip();
}

void MyPanel::OnMouseLeftDown(wxMouseEvent& event) {
	// 标记开始拖动，并记录初始鼠标位置
	isDragging = true;
	a = clock();
	int temX = event.GetPosition().x;
	int temY = event.GetPosition().y;
	for (int i = 0; i < allComponent.size(); i++)
	{
		int dist = (allComponent[i].centerX - temX) * (allComponent[i].centerX - temX) + (allComponent[i].centerY - temY) * (allComponent[i].centerY - temY);
		cout << dist << endl;
		if (dist <= 20000)
		{
			cur = i;
			originalX = allComponent[i].centerX;
			originalY = allComponent[i].centerY;
			return;
		}
	}
	cur = -1;
}

void MyPanel::OnMouseLeftUp(wxMouseEvent& event) {
	// 停止拖动
	isDragging = false;
	Refresh();
}

void MyPanel::OnMouseDoubleClick(wxMouseEvent& event)
{
	int temX = event.GetPosition().x;
	int temY = event.GetPosition().y;
	for (int i = 0; i < allComponent.size(); i++)
	{
		int dist = (allComponent[i].centerX - temX) * (allComponent[i].centerX - temX) + (allComponent[i].centerY - temY) * (allComponent[i].centerY - temY);
		cout << dist << endl;
		if (dist <= 20000)
		{
			sel = i;
			originalX = allComponent[i].centerX;
			originalY = allComponent[i].centerY;
			break;
		}
	}
	if (sel != -1)
	{
		new ContainView("信息显示", wxSize(800, 600), this, sel);
	}
	sel = -1;
}

void MyPanel::OnPaint(wxPaintEvent& event) {
	wxPaintDC dc(this);
	//dc.SetBackground(*wxWHITE_BRUSH);

	/* 开始绘图 */
	Component::drawComponent(dc, allComponent);
	//dc.Blit(0, 0, GetClientSize().GetWidth(), GetClientSize().GetHeight(), &memDC, 0, 0);
}

void MyPanel::OnButton1Click(wxCommandEvent& event) {
	new ComponentSelection("选择符号", wxSize(800, 600), this);
}

MyFrame::MyFrame(const wxString& title, const wxSize& size) :wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, size)
{
	Centre();
	//MyPanel* myPanel = new MyPanel(this);
	wxMenuBar* menuBar = new wxMenuBar();
	wxMenu* fileMenu = new wxMenu();
	fileMenu->Append(wxID_NEW, "new", "Create a new file");
	fileMenu->Append(wxID_OPEN, "Open", "Open a file");
	fileMenu->Append(wxID_SAVE, "Save", "Save the current file");
	fileMenu->Append(wxID_EXIT, "Exit", "Exit the application");
	menuBar->Append(fileMenu, "File");
	SetMenuBar(menuBar);

	Bind(wxEVT_MENU, &MyFrame::OnNew, this, wxID_NEW);
	Bind(wxEVT_MENU, &MyFrame::OnOpen, this, wxID_OPEN);
	Bind(wxEVT_MENU, &MyFrame::OnSave, this, wxID_SAVE);
	Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
}

void MyFrame::OnNew(wxCommandEvent& event) {
	allComponent.clear();
	OnSave(event);
	myPanel->Refresh();
}

void MyFrame::OnOpen(wxCommandEvent& event) {
	string filePath;
	wxFileDialog openFileDialog(this, "路径选择", "", "", ".lyx文件 (*.lyx)|*.lyx", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
	if (openFileDialog.ShowModal() == wxID_OK) {
		filePath = openFileDialog.GetPath();
		Component::readFile(allComponent, 0, filePath);//调用静态函数
		myPanel->Refresh();
	}

}

void MyFrame::OnSave(wxCommandEvent& event) {
	string destPath;
	wxFileDialog saveFileDialog(this, "路径选择", "", "", ".lyx文件 (*.lyx)|*.lyx", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
	if (saveFileDialog.ShowModal() == wxID_OK) {
		destPath = saveFileDialog.GetPath();
		Component::saveComponent(allComponent, destPath);
	}
}

void MyFrame::OnExit(wxCommandEvent& event) {
	Close();
}