//Drew Post

# Compiling and Running
- Open in Code::Blocks
- Build and Run 
- If you're generating an image, after the images have been generated as .ppm's, use GIMP to convert them to .jpg's before opening the .html file


# Notes
- Changed Code::Blocks settings to compile with GCC by the C++11 standard
  -> changed setting made it so I didn't have to convert strings to character arrays to be read in
  
- If you are running the program and entering a file that was converted to ppm with GIMP, the second line with the '#' comment should be deleted before reading it into the program.

- The zip file is going to have generatedExample.jpg, this is an example image that's for the .html file 
  -> I added this in as an example of what a random .jpg will look like in my .html file once converted from .ppm
	
- I couldn't find a formula for sepia that worked fully, but the formula I have works on most of the picture inputted

- If a user is in any menu and enters a bunch of random characters, but the first character they entered is a valid menu option, then the program will ignore the random characters after the first one and take the first one as the user input
