// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: Test

#include "ui.h"
#include "WiFi.h"
#include "main.h"
#include "ESP32ping.h"
int counter;
String WifyNames[1000];
void wificonnect(lv_event_t *e)
{
	WiFi.begin(WifyNames[lv_dropdown_get_selected(ui_Dropdown1)].c_str(), lv_textarea_get_text(ui_TextArea1));
	Serial.println(WifyNames[lv_dropdown_get_selected(ui_Dropdown1)]);
	lv_label_set_text(ui_Label2, "conncting...");
	counter = 0;
	delay(100);
	while (WiFi.status() != WL_CONNECTED)
	{
		WiFi.reconnect();
		counter++;
		delay(100);
		char dots = '.';
		for (int i = 0; i < counter; i++)
		{
			dots += '.';
		}
		Serial.print(dots);
		lv_label_set_text(ui_Label2, "conncting" + dots);

		if (counter >= 10)
		{
			lv_label_set_text(ui_Label2, "Fail to connct");
			lv_textarea_set_text(ui_TextArea1, " ");
			WiFi.disconnect();
			break;
		}
	}
	if (WiFi.status() == WL_CONNECTED)
	{
		lv_label_set_text(ui_Label2, "Connected successfully");
		_ui_flag_modify(ui_TextArea1, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
		_ui_flag_modify(ui_Keyboard2, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
		_ui_flag_modify(ui_Dropdown1, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
		_ui_flag_modify(ui_Button4, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
		delay(100);
		if (Ping.ping("www.google.com"))
		{
			lv_label_set_text(ui_Label2, "Intertent has internet");
		}
		else
		{
			lv_label_set_text(ui_Label2, "Intertent do not have internet");
		}
	}
}
void addDropdownOptions()
{
	lv_dropdown_clear_options(ui_Dropdown1);
	for (int i = 0; i < network_Nubers; i++)
	{
		lv_dropdown_add_option(ui_Dropdown1, WiFi.SSID(i).c_str(), i);
		Serial.println(WiFi.SSID(i).c_str());
		WifyNames[i] = WiFi.SSID(i);
	}
}

void changebritnes(lv_event_t *e)
{
	ledcSetup(0, 300, 8);
	ledcAttachPin(2, 0);
	int slidervalue;
	slidervalue = lv_slider_get_value(ui_Slider3);
	ledcWrite(0, slidervalue);
}
