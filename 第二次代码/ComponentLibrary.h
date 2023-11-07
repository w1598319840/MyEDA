#pragma once
class Coon_01x04 {
public:
	void Draw(wxDC& dc, int x, int y) {
		dc.SetPen(wxPen(wxColor(132, 0, 0), 2));
		dc.SetBrush(wxBrush(wxColor(255, 255, 194)));
		dc.DrawRectangle(wxRect(x, y, 30, 120));//大矩形
		dc.DrawRectangle(wxRect(x, y + 13, 15, 5));//四个小矩形
		dc.DrawRectangle(wxRect(x, y + 43, 15, 5));
		dc.DrawRectangle(wxRect(x, y + 73, 15, 5));
		dc.DrawRectangle(wxRect(x, y + 103, 15, 5));
		dc.DrawLine(x - 40, y + 15, x, y + 15);
		dc.DrawLine(x - 40, y + 45, x, y + 45);
		dc.DrawLine(x - 40, y + 75, x, y + 75);
		dc.DrawLine(x - 40, y + 105, x, y + 105);
		dc.SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
		dc.SetTextForeground(wxColour(72, 72, 255));
		dc.DrawText("无源", x - 75, y + 7);
		dc.DrawText("无源", x - 75, y + 37);
		dc.DrawText("无源", x - 75, y + 67);
		dc.DrawText("无源", x - 75, y + 97);
		dc.SetFont(wxFont(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
		dc.SetTextForeground(wxColour(169, 0, 0));
		dc.DrawText("1", x - 25, y - 5);
		dc.DrawText("2", x - 25, y + 25);
		dc.DrawText("3", x - 25, y + 55);
		dc.DrawText("4", x - 25, y + 85);
		dc.SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
		dc.SetTextForeground(wxColour(2, 101, 101));
		dc.DrawText("J", x + 10, y - 25);
		dc.DrawText("Conn_01x04", x - 40, y + 122);
	}
};

class USB_A {
public:
	void Draw(wxDC& dc, int x, int y) {
		//x = 400, y = 80;
		dc.SetPen(wxPen(wxColor(132, 0, 0), 2));
		dc.SetBrush(wxBrush(wxColor(255, 255, 194)));

		dc.DrawRectangle(wxRect(x, y, 100, 150));//USB_A的外框

		dc.DrawRectangle(wxRect(x + 5, y + 20, 35, 15));//VBUS的外框
		//下面画4个小矩形
		dc.DrawRectangle(wxRect(x + 90, y + 25, 10, 4));//右边最上面
		dc.DrawRectangle(wxRect(x + 90, y + 75, 10, 4));//右边最中间
		dc.DrawRectangle(wxRect(x + 90, y + 100, 10, 4));//右边最下面
		dc.DrawRectangle(wxRect(x + 45, y + 140, 4, 10));//下边
		//下面画5条线
		dc.DrawLine(x + 99, y + 27, x + 120, y + 27);//右上
		dc.DrawLine(x + 99, y + 77, x + 120, y + 77);//右中
		dc.DrawLine(x + 99, y + 102, x + 120, y + 102);//右下
		dc.DrawLine(x + 20, y + 149, x + 20, y + 170);//下左
		dc.DrawLine(x + 47, y + 149, x + 47, y + 170);//下右


		dc.SetBrush(wxBrush(wxColor(132, 0, 0)));
		dc.DrawRectangle(wxRect(x + 8, y + 26, 29, 6));//VBUS的内框
		//很奇怪的东西
		dc.DrawCircle(x + 11, y + 55, 6);//左边的圆

		dc.DrawLine(x + 17, y + 55, x + 52, y + 55);//中间的线

		dc.DrawLine(x + 23, y + 55, x + 33, y + 45);//上边的线
		dc.DrawLine(x + 32, y + 45, x + 35, y + 45);//上边的线

		dc.DrawCircle(x + 39, y + 44, 4);//上边的圆

		dc.DrawLine(x + 30, y + 55, x + 36, y + 65);//下边的线
		dc.DrawLine(x + 35, y + 65, x + 42, y + 65);//下边的线

		dc.DrawRectangle(wxRect(x + 42, y + 61, 8, 8));//下边的方块

		wxPoint points[3];//设置三角形三个点的坐标
		points[0] = wxPoint(x + 53, y + 48);
		points[1] = wxPoint(x + 53, y + 62);
		points[2] = wxPoint(x + 65, y + 55);
		dc.DrawPolygon(3, points);//右边的三角形

		dc.SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
		dc.SetTextForeground(wxColour(2, 101, 101));
		dc.DrawText("J", x, y - 50);
		dc.DrawText("USB_A", x, y - 25);
		dc.DrawText("VBUS", x + 45, y + 16);
		dc.DrawText("D+", x + 65, y + 67);
		dc.DrawText("D-", x + 65, y + 92);
		dc.DrawRotatedText("Shield", x + 8, y + 135, 90);
		dc.DrawRotatedText("GND", x + 35, y + 135, 90);

		dc.SetFont(wxFont(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
		dc.SetTextForeground(wxColour(169, 0, 0));
		dc.DrawText("1", x + 105, y + 6);
		dc.DrawText("3", x + 105, y + 56);
		dc.DrawText("2", x + 105, y + 81);
		dc.DrawRotatedText("5", x - 2, y + 165, 90);
		dc.DrawRotatedText("4", x + 25, y + 165, 90);

		dc.SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
		dc.SetTextForeground(wxColour(72, 72, 255));
		dc.DrawText("电源输入", x + 125, y + 17);
		dc.DrawText("双向", x + 125, y + 68);
		dc.DrawText("双向", x + 125, y + 93);
		dc.DrawRotatedText("无源", x + 10, y + 210, 90);
		dc.DrawRotatedText("电源输入", x + 37, y + 245, 90);
	}
};

class LED {
public:
	void Draw(wxDC& dc, int x, int y) {
		dc.SetPen(wxPen(wxColor(132, 0, 0), 3));
		dc.SetBrush(wxBrush(wxColor(255, 255, 194)));
		wxPoint triangle[3];
		triangle[0] = wxPoint(x, y); // 第一个点
		triangle[1] = wxPoint(x + 100, y + 50); // 第二个点
		triangle[2] = wxPoint(x + 100, y - 50);  // 第三个点

		//
		dc.SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
		dc.SetTextForeground(wxColour(2, 101, 101));
		dc.DrawText("D4", x + 50, y - 80);
		dc.DrawText("LED", x + 50, y - 60);
		// 绘制三角形
		dc.DrawPolygon(3, triangle, wxWINDING_RULE);
		//画线
		dc.SetPen(wxPen(wxColor(132, 0, 0), 2));
		dc.DrawLine(x + 100, y, x + 200, y);
		//画粗线
		dc.SetPen(wxPen(wxColor(132, 0, 0), 5));
		dc.DrawLine(x, y, x, y + 30);
		dc.DrawLine(x, y, x, y - 30);

		dc.SetPen(wxPen(wxColor(132, 0, 0), 2));
		dc.DrawLine(x, y, x - 100, y);
		dc.DrawLine(x, y, x + 100, y);
		//画圆
		dc.DrawCircle(x + 200, y, 10);
		dc.DrawCircle(x - 100, y, 10);
		//箭头1
		dc.DrawLine(x - 10, y + 10, x - 40, y + 40);
		dc.DrawLine(x - 40, y + 40, x - 40, y + 30);
		dc.DrawLine(x - 40, y + 40, x - 30, y + 40);
		//箭头2
		dc.DrawLine(x - 30, y + 10, x - 60, y + 40);
		dc.DrawLine(x - 60, y + 40, x - 45, y + 40);
		dc.DrawLine(x - 60, y + 40, x - 60, y + 30);
	}
};

class Ammeter
{
public:
	void Draw(wxDC& dc, int x, int y) {
		dc.SetPen(wxPen(wxColor(132, 0, 0), 3));
		dc.SetBrush(wxBrush(wxColor(255, 255, 194)));

		dc.SetPen(wxPen(wxColor(132, 0, 0), 6));
		dc.DrawCircle(x, y, 50);
		//画A
		dc.DrawLine(x, y - 50, x - 30, y + 30);
		dc.DrawLine(x, y - 50, x + 30, y + 30);
		dc.DrawLine(x - 15, y, x + 15, y);

		dc.SetPen(wxPen(wxColor(132, 0, 0), 3));
		dc.DrawLine(x, y - 50, x, y - 100);
		dc.DrawLine(x, y + 50, x, y + 100);

		dc.DrawLine(x + 34, y - 34, x + 65, y - 65);
		dc.DrawLine(x - 34, y + 34, x - 65, y + 65);

		dc.DrawLine(x + 65, y - 65, x + 65, y - 35);
		dc.DrawLine(x + 65, y - 65, x + 35, y - 65);
		dc.DrawCircle(x, y - 100, 10);
		dc.DrawCircle(x, y + 100, 10);


		dc.SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
		dc.SetTextForeground(wxColour(2, 101, 101));
		dc.DrawText("MES1", x + 100, y);
		dc.DrawText("Ammeter_DC", x + 100, y - 30);
	}
};

class Battery {
public:
	void Draw(wxDC& dc, int x, int y) {
		//上方的圆
		dc.SetPen(wxPen(wxColor(132, 0, 0), 1));
		dc.SetBrush(wxBrush(wxColor(240, 240, 240)));
		dc.DrawCircle(x, y, 10);

		//上方的线
		dc.SetPen(wxPen(wxColor(132, 0, 0), 2));
		dc.DrawLine(x, y, x, y + 70);

		//上方电池
		dc.SetBrush(wxBrush(wxColor(132, 0, 0)));
		dc.DrawRectangle(wxRect(x - 40, y + 70, 80, 6));
		dc.DrawRectangle(wxRect(x - 30, y + 82, 60, 10));

		//中间的线
		dc.DrawLine(x, y + 95, x, y + 101);
		dc.DrawLine(x, y + 104, x, y + 110);
		dc.DrawLine(x, y + 113, x, y + 119);

		//下方电池
		dc.SetBrush(wxBrush(wxColor(132, 0, 0)));
		dc.DrawRectangle(wxRect(x - 40, y + 122, 80, 6));
		dc.DrawRectangle(wxRect(x - 30, y + 134, 60, 10));

		//下方的圆
		dc.SetPen(wxPen(wxColor(132, 0, 0), 1));
		dc.SetBrush(wxBrush(wxColor(240, 240, 240)));
		dc.DrawCircle(x, y + 214, 10);

		//下方的线 圆要先画，不然圆中的线会被圆覆盖
		dc.SetPen(wxPen(wxColor(132, 0, 0), 2));
		dc.DrawLine(x, y + 144, x, y + 214);

		//+
		dc.SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
		dc.SetTextForeground(wxColor(132, 0, 0));
		dc.DrawText("+", x + 15, y + 30);

		//字
		dc.SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
		dc.SetTextForeground(wxColor(0, 100, 100));
		dc.DrawText("BT1", x + 70, y + 50);

		dc.SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
		dc.SetTextForeground(wxColor(0, 100, 100));
		dc.DrawText("Battery", x + 70, y + 100);
	}
};

class CH330N {
public:
	void Draw(wxDC& dc, int x, int y) {
		//框
		dc.SetPen(wxPen(wxColor(132, 0, 0), 4));
		dc.SetBrush(wxBrush(wxColor(255, 255, 194)));
		dc.DrawRectangle(wxRect(x, y, 300, 250));

		dc.DrawLine(x - 40, y + 40, x, y + 40);
		dc.DrawLine(x - 40, y + 160, x, y + 160);
		dc.DrawLine(x - 40, y + 210, x, y + 210);
		dc.DrawLine(x + 300, y + 40, x + 340, y + 40);
		dc.DrawLine(x + 300, y + 90, x + 340, y + 90);
		dc.DrawLine(x + 300, y + 210, x + 340, y + 210);
		dc.DrawLine(x + 150, y - 40, x + 150, y);
		dc.DrawLine(x + 150, y + 250, x + 150, y + 290);

		dc.SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
		dc.SetTextForeground(wxColor(0, 100, 100));
		dc.DrawText("V3", x + 10, y + 20);
		dc.DrawText("UD+", x + 10, y + 140);
		dc.DrawText("UD-", x + 10, y + 190);
		dc.DrawText("TXD", x + 225, y + 20);
		dc.DrawText("RXD", x + 225, y + 70);
		dc.SetPen(wxPen(wxColor(0, 100, 100), 2));
		dc.DrawLine(x + 225, y + 190, x + 285, y + 190);
		dc.DrawText("RTS", x + 225, y + 190);
		dc.DrawRotatedText("VCC", x + 130, y + 70, 90);
		dc.DrawRotatedText("GND", x + 130, y + 240, 90);

		dc.SetTextForeground(wxColor(132, 0, 0));
		dc.DrawText("8", x - 30, y);
		dc.DrawText("1", x - 30, y + 120);
		dc.DrawText("2", x - 30, y + 170);
		dc.DrawText("6", x + 310, y);
		dc.DrawText("7", x + 310, y + 50);
		dc.DrawText("4", x + 310, y + 170);
		dc.DrawRotatedText("5", x + 110, y - 10, 90);
		dc.DrawRotatedText("3", x + 110, y + 280, 90);

		dc.SetFont(wxFont(35, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
		dc.SetTextForeground(wxColor(0, 100, 100));
		dc.DrawText("U2", x + 200, y - 120);
		dc.DrawText("CH330N", x + 200, y - 80);
	}
};

class Capacitor {
public:
	void Draw(wxDC& dc, int x, int y) {
		dc.SetPen(wxPen(wxColor(132, 0, 0), 7));//用了更粗的线
		dc.SetBrush(wxBrush(wxColor(255, 255, 194)));
		dc.DrawLine(x + 100, y + 100, x + 200, y + 100);//上边的线
		dc.DrawLine(x + 100, y + 150, x + 200, y + 150);//下边的线
		dc.SetPen(wxPen(wxColor(132, 0, 0), 2));
		dc.DrawLine(x + 150, y + 100, x + 150, y + 60);//上导线
		dc.DrawLine(x + 150, y + 150, x + 150, y + 190);//下导线
		dc.SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
		dc.SetTextForeground(wxColour(2, 101, 101));
		dc.DrawText("C", x + 155, y + 70);
		dc.DrawText("C", x + 155, y + 165);
	}
};

class Resistance {
public:
	void Draw(wxDC& dc, int x, int y) {
		dc.SetPen(wxPen(wxColor(132, 0, 0), 5));
		dc.DrawLine(x + 100, y + 100, x + 130, y + 100);//上边的线
		dc.DrawLine(x + 100, y + 200, x + 130, y + 200);//下边的线
		dc.DrawLine(x + 100, y + 100, x + 100, y + 200);//左边的线
		dc.DrawLine(x + 130, y + 100, x + 130, y + 200);//右边的线
		dc.SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
		dc.SetTextForeground(wxColour(2, 101, 101));
		dc.DrawRotatedText("R", x + 105, y + 150, 90);
		dc.DrawRotatedText("R", x + 135, y + 150, 90);
		dc.SetPen(wxPen(wxColor(132, 0, 0), 2));
		dc.DrawLine(x + 115, y + 100, x + 115, y + 80);//上导线
		dc.DrawLine(x + 115, y + 200, x + 115, y + 220);//下导线
		dc.SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
		dc.SetTextForeground(wxColour(72, 72, 255));
		dc.DrawRotatedText("无源", x + 105, y + 70, 90);
		dc.DrawRotatedText("无源", x + 105, y + 260, 90);
	}
};