module menu.toggleButton;

import menu;
import std.string;
import raylib;

class ToggleButton : Button{
	bool isDown = false;
	
	@property override bool Pressed(){
		if(IsMouseButtonPressed(MouseButton.MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), rec))
			toggle();
		return isDown;
	}
	
	@property override bool Released(){
		auto b = IsMouseButtonReleased(MouseButton.MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), rec);
		if(b) toggle();
		return b;
	}
	
	this(Rectangle rec, string text){
		super(rec, text);
	}
	
	void toggle(){
		isDown = !isDown;
	}
	
	override void draw(){
		if(this.Down) DrawRectangleRec(rec, pressColor);
		else if(this.Hovering) DrawRectangleRec(rec, hoverColor);
		else if(isDown) DrawRectangleRec(rec, pressColor);
		else DrawRectangleRec(rec, backColor);
		
		auto txtPosX = rec.x + ((rec.w - (MeasureText(toStringz(text), cast(int)(textRec.h)))) / 2.0f);
		
		DrawText(toStringz(text), cast(int)(txtPosX), cast(int)(textRec.y), cast(int)(textRec.h), textColor);
	}
}

