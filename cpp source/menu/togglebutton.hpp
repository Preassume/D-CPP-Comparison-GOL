#include <raylib.h>
#include <string>

class ToggleButton : Button{
public:
	bool isDown = false;
	
	bool Pressed();
	
	bool Released();
	
	ToggleButton(Rectangle rec, std::string text);
	
	void toggle();
	
	void draw();
};
