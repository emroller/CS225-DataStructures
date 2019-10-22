
#include "cs225/PNG.h"
#include "FloodFilledImage.h"
#include "Animation.h"

#include "imageTraversal/DFS.h"
#include "imageTraversal/BFS.h"

#include "colorPicker/RainbowColorPicker.h"
#include "colorPicker/GradientColorPicker.h"
#include "colorPicker/GridColorPicker.h"
#include "colorPicker/SolidColorPicker.h"
#include "colorPicker/MyColorPicker.h"

using namespace cs225;

int main() {

  // @todo [Part 3]
  // - The code below assumes you have an Animation called `animation`
  // - The code provided below produces the `myFloodFill.png` file you must
  //   submit Part 3 of this assignment -- uncomment it when you're ready.

	PNG png;
	png.readFromFile("pacman-solid-bfs-2.png");
  
	FloodFilledImage ffi(png);
	BFS bfs(png, Point(2,2), 0.1 );
	BFS bfs2(png, Point(png.width() - 10, png.height() - 10), 0.03);

	MyColorPicker mcp(HSLAPixel(70, 1, 0.5), HSLAPixel(30, 1, 0.5), HSLAPixel(100, .6, 0.9));
	MyColorPicker mcp2(HSLAPixel(220, .5, 0.5), HSLAPixel(300, 1, 0.9), HSLAPixel(200, .9, 0.9));

	ffi.addFloodFill(bfs, mcp);
	ffi.addFloodFill(bfs2, mcp2);
	Animation animation = ffi.animate(100);


 	// ----------- given ------------ //
	PNG lastFrame = animation.getFrame( animation.frameCount() - 1 );
  	lastFrame.writeToFile("myFloodFill.png");
  	animation.write("myFloodFill.gif");
  return 0;
}
