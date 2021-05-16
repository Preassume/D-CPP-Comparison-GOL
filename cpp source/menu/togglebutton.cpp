#include "togglebutton.hpp"

bool ToggleButton::Pressed(){
	if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), rec))
		toggle();
	return isDown;
}

bool ToggleButton::Released(){
	bool b = IsMouseButtonReleased(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), rec);
	if(b) toggle();
	return b;
}

ToggleButton::ToggleButton(Rectangle rec, std::string text) : Button(rec, text){}

void ToggleButton::toggle(){
	isDown = !isDown;
}

void ToggleButton::draw(){
	if(Down()) DrawRectangleRec(rec, pressColor);
	else if(Hovering()) DrawRectangleRec(rec, hoverColor);
	else if(isDown) DrawRectangleRec(rec, pressColor);
	else DrawRectangleRec(rec, backColor);
	
	float txtPosX = rec.x + ((rec.width - (MeasureText(text.c_str(), (int)(textRec.height)))) / 2.0f);
	
	DrawText(text.c_str(), (int)(txtPosX), (int)(textRec.y), (int)(textRec.height), textColor);
}
