#include "button.hpp"

bool Button::Pressed() { return (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), rec)); }
bool Button::Down() { return (IsMouseButtonDown(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), rec)); }
bool Button::Released() { return (IsMouseButtonReleased(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), rec)); }
bool Button::Hovering() { return (IsMouseButtonUp(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), rec)); }

Button::Button(Rectangle r, std::string txt){
	rec = r;
	text = txt;
	
	backColor = WHITE;
	pressColor = YELLOW;
	hoverColor = BLUE;
	textColor = BLACK;
	
	textRec.width = rec.width * textSize;
	textRec.height = rec.height * textSize;
	
	textRec.x = rec.x + (rec.width - textRec.width) / 2;
	textRec.y = rec.y + (rec.height - textRec.height) / 2;
}
	
void Button::draw(){
	if(Down()) DrawRectangleRec(rec, pressColor);
	else if(Hovering()) DrawRectangleRec(rec, hoverColor);
	else DrawRectangleRec(rec, backColor);
	
	float txtPosX = rec.x + ((rec.width - (MeasureText(text.c_str(), (int)(textRec.height)))) / 2.0f);
	
	DrawText(text.c_str(), (int)(txtPosX), (int)(textRec.y), (int)(textRec.height), textColor);
}
