#include <wx/wx.h>
#include <cstdlib>

class MyRect : public wxPanel {
public:
	MyRect(wxFrame* parent) : wxPanel(parent) {
		//SetBackgroundStyle(wxBG_STYLE_PAINT);//调用wxPanel的构造函数，设置窗口背景为绘制模式。
		Bind(wxEVT_PAINT, &MyRect::OnPaint, this);//将绘制事件wxEVT_PAINT绑定到处理函数Onpaint上
	}

	void OnPaint(wxPaintEvent& event) {
		wxPaintDC dc(this);//实例化wxPaintDC类的对象dc，将当前窗口控件传入

		//画背景
		dc.SetPen(wxPen(wxColor(255, 223, 225), 2));//使用自定颜色的画笔，线宽为2
		dc.SetBrush(wxBrush(wxColor(144, 238, 144)));//使用颜色填充
		wxRect rect(75, 75, 200, 200);//设置一个矩形所在位置x,y和宽度和高度w,h
		dc.DrawRectangle(rect);//绘制这个图形

		//画脸
		dc.SetPen(wxPen(wxColor(255, 255, 255), 2));
		dc.SetBrush(wxBrush(wxColor(255, 228, 0)));
		dc.DrawCircle(175, 175, 65);//x,y,r

		//眼睛
		dc.SetPen(wxPen(wxColor(0, 0, 0), 1));
		dc.SetBrush(wxBrush(wxColor(255, 255, 255)));
		dc.DrawCircle(150, 150, 20);
		dc.DrawCircle(200, 150, 20);

		//眼珠
		dc.SetPen(wxPen(wxColor(0, 0, 0), 1));
		dc.SetBrush(wxBrush(wxColor(0, 0, 0)));
		dc.DrawCircle(150, 155, 10);
		dc.DrawCircle(200, 155, 10);

		//脸颊
		dc.SetPen(wxPen(wxColor(255, 255, 255), 0));
		dc.SetBrush(wxBrush(wxColor(255, 228, 225)));
		dc.DrawCircle(130, 190, 10);
		dc.DrawCircle(215, 190, 10);

		//嘴
		wxPointList points;
		points.Append(new wxPoint(150, 215));  // 第一个控制点
		points.Append(new wxPoint(175, 229));  // 第二个控制点
		points.Append(new wxPoint(200, 215));  // 第三个控制点
		dc.SetPen(wxPen(wxColour(0, 0, 0), 3));  // 设置画笔颜色和宽度
		dc.DrawSpline(&points);  // 绘制曲线

	}
};



class App : public wxApp {
public:
	bool OnInit() {
		wxFrame* window = new wxFrame(NULL, wxID_ANY, "绘画", wxDefaultPosition, wxSize(400, 400));//实例化一个Frame,
		wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);//布局管理，水平方向布局

		MyRect* rect1 = new MyRect(window);
		window->Show();

		//wxstatictext* text = new wxstatictext(window, wxid_any, "hello,world!", wxdefaultposition, wxdefaultsize, wxalign_centre_horizontal);
		//text->setfont(wxfont(20, wxfontfamily_default, wxfontstyle_normal, wxfontweight_normal));
		//sizer->add(text, 1, wxalign_center);
		//window->setsizer(sizer);
		//window->show();

		return true;
	}
};

wxIMPLEMENT_APP(App);//程序入口

