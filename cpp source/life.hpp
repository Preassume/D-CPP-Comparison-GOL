#include <raylib.h>
#include <string>

using namespace std;

class life{
public:
	bool isAlive = false;
	int liveNeighbors = 0;
	Rectangle rec;
	Color liveColor = VIOLET;
	
	life(){}
	
	void init(int x, int y, int size){
		rec.x = x;
		rec.y = y;
		rec.width = size;
		rec.height = size;
	}
	
	// Draw the life
	void draw(){
		if(isAlive) DrawRectangleRec(rec, liveColor);
		else DrawRectangleRec(rec, BLACK);
	}
	
	// Apply the rules of GOL to this life instance
	void update(){
		if(isAlive){
			if(liveNeighbors < 2 || liveNeighbors > 3) isAlive = false;
		}
		else{
			if(liveNeighbors == 3) isAlive = true;
		}
		liveNeighbors = 0;
	}
};
