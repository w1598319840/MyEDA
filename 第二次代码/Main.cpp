#include <wx/wx.h>
#include <cstdlib>
#include "ComponentLibrary.h"

class MyPanel : public wxPanel {
public:
	int res = 0;
public:
	MyPanel(wxFrame* parent) : wxPanel(parent) {
		//SetBackgroundStyle(wxBG_STYLE_PAINT);//调用wxPanel的构造函数，设置窗口背景为绘制模式。
		wxButton* button = new wxButton(this, wxID_ANY, "添加电气元件", wxPoint(20, 20), wxSize(100, 30));
		button->Bind(wxEVT_BUTTON, &MyPanel::OnButtonClick, this);
	}
public:
	class MyDialog : public wxDialog {
	public:
		MyDialog(wxWindow* parent) : wxDialog(parent, wxID_ANY, "选择符号", wxDefaultPosition, wxSize(350, 200)) {
			wxButton* button1 = new wxButton(this, wxID_ANY, "Coon_01X04", wxPoint(20, 20), wxSize(80, 30));
			wxButton* button2 = new wxButton(this, wxID_ANY, "USB_A", wxPoint(120, 20), wxSize(80, 30));
			wxButton* button3 = new wxButton(this, wxID_ANY, "LED", wxPoint(220, 20), wxSize(80, 30));
			wxButton* button4 = new wxButton(this, wxID_ANY, "Ammeter", wxPoint(20, 70), wxSize(80, 30));
			wxButton* button5 = new wxButton(this, wxID_ANY, "Battery", wxPoint(120, 70), wxSize(80, 30));
			wxButton* button6 = new wxButton(this, wxID_ANY, "CH330N", wxPoint(220, 70), wxSize(80, 30));
			wxButton* button7 = new wxButton(this, wxID_ANY, "Capacitor", wxPoint(20, 120), wxSize(80, 30));
			wxButton* button8 = new wxButton(this, wxID_ANY, "Resistance", wxPoint(120, 120), wxSize(80, 30));
			button1->Bind(wxEVT_BUTTON, &MyDialog::OnButton1Click, this);
			button2->Bind(wxEVT_BUTTON, &MyDialog::OnButton2Click, this);
			button3->Bind(wxEVT_BUTTON, &MyDialog::OnButton3Click, this);
			button4->Bind(wxEVT_BUTTON, &MyDialog::OnButton4Click, this);
			button5->Bind(wxEVT_BUTTON, &MyDialog::OnButton5Click, this);
			button6->Bind(wxEVT_BUTTON, &MyDialog::OnButton6Click, this);
			button7->Bind(wxEVT_BUTTON, &MyDialog::OnButton7Click, this);
			button8->Bind(wxEVT_BUTTON, &MyDialog::OnButton8Click, this);
		}

		void OnButton1Click(wxCommandEvent& event) {
			EndModal(1);
		}
		void OnButton2Click(wxCommandEvent& event) {
			EndModal(2);
		}
		void OnButton3Click(wxCommandEvent& event) {
			EndModal(3);
		}
		void OnButton4Click(wxCommandEvent& event) {
			EndModal(4);
		}
		void OnButton5Click(wxCommandEvent& event) {
			EndModal(5);
		}
		void OnButton6Click(wxCommandEvent& event) {
			EndModal(6);
		}
		void OnButton7Click(wxCommandEvent& event) {
			EndModal(7);
		}
		void OnButton8Click(wxCommandEvent& event) {
			EndModal(8);
		}
	};

	void OnButtonClick(wxCommandEvent& event) {
		MyDialog dialog(this);
		dialog.SetPosition(wxPoint(100, 200));
		res = dialog.ShowModal();
		Refresh();  // 刷新窗口，触发绘制事件
		Bind(wxEVT_PAINT, &MyPanel::OnPaint, this);//将绘制事件wxEVT_PAINT绑定到处理函数Onpaint上
	}

	void OnPaint(wxPaintEvent& event) {
		wxPaintDC dc(this);//实例化wxPaintDC类的对象dc，将当前窗口控件传入

		if (res == 1) {
			Coon_01x04 coon;
			coon.Draw(dc, 400, 200);
		}
		if (res == 2) {
			USB_A usb_A;
			usb_A.Draw(dc, 400, 200);
		}
		if (res == 3) {
			LED led;
			led.Draw(dc, 400, 200);
		}
		if (res == 4) {
			Ammeter ammeter;
			ammeter.Draw(dc, 400, 200);
		}
		if (res == 5) {
			Battery battery;
			battery.Draw(dc, 400, 200);
		}
		if (res == 6) {
			CH330N ch330n;
			ch330n.Draw(dc, 400, 200);
		}
		if (res == 7) {
			Capacitor capcitor;
			capcitor.Draw(dc, 400, 200);
		}
		if (res == 8) {
			Resistance resistance;
			resistance.Draw(dc, 400, 200);
		}
	}
};


class App : public wxApp {
public:
	bool OnInit()override {
		wxFrame* window = new wxFrame(NULL, wxID_ANY, "原理图编辑器", wxDefaultPosition, wxSize(1000, 700));//实例化一个Frame,
		window->Centre();

		MyPanel* myPanel = new MyPanel(window);
		window->Show();

		return true;
	}
};

wxIMPLEMENT_APP(App);//程序入口

