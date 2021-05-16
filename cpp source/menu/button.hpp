#include <raylib.h>
#include <string>

class Button{
public:
	float textSize = 0.8;
	Rectangle rec, textRec;
	std::string text;
	Color backColor, pressColor, hoverColor, textColor;
	
	// Mouse detection stuff
	bool Pressed();
	bool Down();
	bool Released();
	bool Hovering();
	
	Button(Rectangle r, std::string txt);
		
	void draw();
};
