# fractol
42 project with an aim to make a little program to explore fractals and learn basics of computer graphics. One of the most enjoyable 42 projects I did so far. I plan to expand it in the future, by implementing variable window size, multithread the computation of fractals and make use of some advanced optimization techniques to make it faster, add some more coloring techniques (especially Pickover stalk for Mandelbrot), saving the picture (into bmp because it's easiest :D)...
## Requirements
* Use MLX library
* Make a program to compute Mandelbrot and Julia set and one additional fractal for bonus points
* Take an argument (./fractol "argument") when running executable and show corresponding fractal
* Make some coloring to show depth of the fractals, make them change for bonus
* Arguments:
	* "mandelbrot" outputs window with Mandelbrot fractal
	* "julia" or "julia "x coordinate" "y coordinate"" while x and y are coordinates in Mandelbrot fractal plane, outputs window with Julia fractal of arbitrary coordinates or, if specified, specific coordinates
	* "newton" outputs window with Newton fractal, bonus fractal of my choice
* Mouse wheel for zooming in and out (zooming doesn't follow the cursor (which was the bonus functionality), my solution is oriented mainly on keyboard controls)
* Arrows for moving up, down, roght or left for bonus
## My solution
I make use of allocated struct to hold all the data needed for a computation of the fractal. I like it this way because usually I can pass just a pointer to this data structure and the function then can perform any kind of operation based on the data in the struct, especially useful for key controlled operations. Though it might not be the most efficient way because it means a lot of pointer dereferencing which can slow things down but on the other hand the computing power of contemporary computers is so high it would't make much of a difference. I created a datatype for complex numbers and set of functions for doing math with these complex numbers, this way writing the actuall algorithm was much easier for me as I just call functions of respective operations. I implemented one more argument, "-h", for printing out the help, like many other programs do. Then there are more keys to control the program.
* Key controls:
	* Arrows: moving around
 	* Page up/down: zooming in and out
	* Home: reset the view
	* C: change color pallete, works for Mandelbrot and Julia
	* J: switches from Julia to Mandelbrot and takes coordinates under the cursor to compute the Julia set, if held down, you can move cursor around and see how the Julia set changes
	* I/K: increase/decrease the number of iterations per pixel, very useful for moving around with low number of iterations because it is faster and when you want more detail, you can just increase the iterations to get clearer image
	* Esc: exits the program
