#include "MyFrame.h"
#include "ContainView.h"
#include <wx/wx.h>
#include <ctime>
#define SAVE_NET 5023
extern std::vector<Net> allNet;

MyPanel::MyPanel(wxFrame* parent) : wxPanel(parent) {
	ConnectButton = new wxButton(this, wxID_ANY, wxT("连线"));

	ConnectButton->Bind(wxEVT_BUTTON, &MyPanel::OnConnect, this);
	Bind(wxEVT_PAINT, &MyPanel::OnPaint, this);
	Bind(wxEVT_MOTION, &MyPanel::OnMouseMove, this);
	Bind(wxEVT_LEFT_DOWN, &MyPanel::OnMouseLeftDown, this);
	Bind(wxEVT_LEFT_UP, &MyPanel::OnMouseLeftUp, this);
	Bind(wxEVT_LEFT_DCLICK, &MyPanel::OnMouseDoubleClick, this);
	SetBackgroundColour(wxColor(245, 244, 239));
}

void MyPanel::MyRefresh() {
	if (!a)a = clock();
	b = clock();
	if (b - a > 1000 / 60)Refresh(), a = clock();
}

void MyPanel::OnConnect(wxCommandEvent& event) {
	isConnecting = true;
}

void MyPanel::Drag(wxMouseEvent& event) {
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
	MyRefresh();
}

void MyPanel::Connect(wxMouseEvent& event) {
	if (isDrawing == 0)return;
	int temX = event.GetPosition().x;
	int temY = event.GetPosition().y;
	int nw = allNet.size() - 1;
	if (allNet[nw].Px.empty() || allNet[nw].Px.size() <= 1) {
		allNet[nw].Px.push_back(temX);
		allNet[nw].Py.push_back(temY);
	}
	else {
		allNet[nw].Px[1] = temX;
		allNet[nw].Py[1] = temY;
	}
	MyRefresh();
};

void MyPanel::OnMouseMove(wxMouseEvent& event) {
	if (isDragging) {
		Drag(event);
	}
	if (isConnecting) {
		Connect(event);
	}
	event.Skip();
}

void MyPanel::OnMouseLeftDown(wxMouseEvent& event) {
	int temX = event.GetPosition().x;
	int temY = event.GetPosition().y;
	// 如果处于画线阶段
	if (isConnecting == 1) {
		if (isDrawing == 0) {
			allNet.push_back(Net());
			isDrawing = 1;
		}
		else isDrawing = 0;
		int nw = allNet.size() - 1;
		if (allNet[nw].Px.empty() || allNet[nw].Px.size() <= 1) {
			allNet[nw].Px.push_back(temX);
			allNet[nw].Py.push_back(temY);
		}
		else {
			allNet[nw].Px[1] = temX;
			allNet[nw].Py[1] = temY;
		}
		return;
	}
	// 标记开始拖动，并记录初始鼠标位置
	for (int i = 0; i < allComponent.size(); i++)
	{
		int dist = (allComponent[i].centerX - temX) * (allComponent[i].centerX - temX) + (allComponent[i].centerY - temY) * (allComponent[i].centerY - temY);
		cout << dist << endl;
		if (dist <= 2000)
		{
			a = clock();
			cur = i;
			originalX = allComponent[i].centerX;
			originalY = allComponent[i].centerY;
			isDragging = true;
			return;
		}
	}
	cur = -1;
}

void MyPanel::OnMouseLeftUp(wxMouseEvent& event) {
	// 停止拖动
	if (isConnecting == 1) {
		if (isDrawing == 1)return;
		isConnecting = 0;
	}
	else isDragging = false;
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

	wxSize size = GetClientSize();
	Component::drawInformation(dc, allComponent, size);
	Component::drawComponent(dc, allComponent);
	Net::drawNet(dc, allNet);
}

MyFrame::MyFrame(const wxString& title, const wxSize& size) :wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, size)
{
	Centre();
	//MyPanel* myPanel = new MyPanel(this);
	wxMenuBar* menuBar = new wxMenuBar();
	wxMenu* fileMenu = new wxMenu();
	wxMenu* componentMenu = new wxMenu();
	fileMenu->Append(wxID_NEW, "新建", "新建一个文件");
	fileMenu->Append(wxID_OPEN, "打开", "打开文件");
	fileMenu->Append(wxID_SAVE, "导出原理图", "导出当前文件为原理图");
	fileMenu->Append(SAVE_NET, "导出网表", "导出当前文件为网表");
	fileMenu->Append(wxID_EXIT, "退出", "退出程序");
	componentMenu->Append(wxID_ADD, "选择符号", "添加一个电气元件");
	menuBar->Append(fileMenu, "文件");
	menuBar->Append(componentMenu, "元件");
	SetMenuBar(menuBar);

	Bind(wxEVT_MENU, &MyFrame::OnNew, this, wxID_NEW);
	Bind(wxEVT_MENU, &MyFrame::OnOpen, this, wxID_OPEN);
	Bind(wxEVT_MENU, &MyFrame::OnSave_sch, this, wxID_SAVE);
	Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
	Bind(wxEVT_MENU, &MyFrame::OnSave_net, this, SAVE_NET);
	Bind(wxEVT_MENU, &MyFrame::addComponent, this, wxID_ADD);
}

void MyFrame::addComponent(wxCommandEvent& event) {
	new ComponentSelection("选择符号", wxSize(800, 600), myPanel);
}

void MyFrame::OnNew(wxCommandEvent& event) {
	allComponent.clear();
	allNet.clear();
	Information infor;
	OnSave_sch(event);
	myPanel->Refresh();
}

void MyFrame::OnOpen(wxCommandEvent& event) {
	wxFileDialog openFileDialog(this, "路径选择", "", "", ".lyx文件 (*.lyx)|*.lyx", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
	if (openFileDialog.ShowModal() == wxID_OK) {
		destPath = openFileDialog.GetPath();
		Component::readFile(allComponent, 0, destPath);//调用静态函数
		myPanel->Refresh();
	}
}

void MyFrame::OnSave_sch(wxCommandEvent& event) {
	wxFileDialog saveFileDialog(this, "路径选择", "", "", ".lyx文件 (*.lyx)|*.lyx", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
	if (saveFileDialog.ShowModal() == wxID_OK) {
		destPath = saveFileDialog.GetPath();
		string fileName;
		fileName = saveFileDialog.GetFilename();
		ofstream destFile(destPath);
		Information::saveInformation(destFile, fileName);
		Component::saveComponent_sch(allComponent, destFile);
		Net::saveNet_sch(allNet, destFile);
		destFile.close();
	}
}

void MyFrame::OnSave_net(wxCommandEvent& event) {
	if (destPath == "") {
		wxMessageBox("需要先保存文件为原理图!");
		return;
	}
	string destPath;
	wxFileDialog saveFileDialog(this, "路径选择", "", "", ".net文件 (*.net)|*.net", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
	if (saveFileDialog.ShowModal() == wxID_OK) {
		destPath = saveFileDialog.GetPath();
		ofstream destFile(destPath);
		Component::saveComponent_net(allComponent, destFile, destPath);
		Net::saveNet_net(allNet, destFile);
		destFile.close();
	}
}

void MyFrame::OnExit(wxCommandEvent& event) {
	Close();
}