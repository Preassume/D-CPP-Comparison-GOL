#include <iostream>
#include <raylib.h>

#include "board.hpp"

#include "menu/button.cpp"
#include "menu/togglebutton.cpp"

int main(){
	SetTargetFPS(60);
	InitWindow(2000, 1060, "L i f e");
	
	Button b((Rectangle){220, 0, 200, 60}, "Next");
	Button b2((Rectangle){440, 0, 200, 60}, "Reset");
	ToggleButton b3((Rectangle){0, 0, 200, 60}, "Pause");
	b3.toggle();
	
	board bd(400, 200, 5, 60);
	
	while (!WindowShouldClose())
	{		
		BeginDrawing();
		
		ClearBackground(GRAY);
			
			ClearBackground(BLACK);
			
			DrawText(to_string(GetFPS()).c_str(), 700, 0, 60, VIOLET);
			
			if(IsKeyPressed(KEY_SPACE)) b3.toggle();
			
			if(!b3.Pressed()) bd.update();
			else if(b.Pressed() || IsKeyPressed(KEY_F)) bd.update();
			
			bd.draw();
			b.draw();
			b2.draw();
			b3.draw();
		
		EndDrawing();
	}
	CloseWindow();
}
