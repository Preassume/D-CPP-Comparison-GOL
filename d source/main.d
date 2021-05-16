import std.stdio;
import std.conv;
import std.string;
import raylib;
import board;
import menu;

void main(){
	SetTargetFPS(60);
	InitWindow(2000, 1060, "L i f e");
	
	auto b = new Button(Rectangle(220, 0, 200, 60), "Next");
	auto b2 = new Button(Rectangle(440, 0, 200, 60), "Reset");
	auto b3 = new ToggleButton(Rectangle(0, 0, 200, 60), "Pause");
	b3.toggle();
	
	auto bd = new board(400, 200, 5, 60);
	
	while (!WindowShouldClose())
	{
		BeginDrawing();
		
		ClearBackground(Colors.BLACK);
		
			DrawText(toStringz(to!string(GetFPS())), 700, 0, 60, Colors.VIOLET);
			
			if(IsKeyPressed(KeyboardKey.KEY_SPACE)) b3.toggle();
			
			if(!b3.Pressed) bd.update();
			else if(b.Pressed || IsKeyPressed(KeyboardKey.KEY_F)) bd.update();
			
			bd.draw();
			b.draw();
			b2.draw();
			b3.draw();
		
		EndDrawing();
	}
	CloseWindow();
}
