# Projects-Testing
-     Summarize the project and what problem it was solving:

	The objective of this project was to create a running clock with the ability to accept user designated changes to the displayed time. A simple menu with the 
	control inputs and both a 24-hour and 12-hour clock was required to be displayed and updated constantly while still being able to accept user input. 
	An exit function and input validation were also required. 

-     What did you do particularly well?

	I feel that I resolved the issues with input validation and running multiple functions quite well. While I am not entirely satisfied with the occasional flickering in 
	my menu, or the existing functionality of my functions, I feel that this portion of my code works well.

-     Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?

	I feel that I should have utilized the system clock function from the Windows library to track the time, or at least set the initial time instead of relying
	purely on nested for loops. This, I think, would have more accurately satisfied the functional requirements of the program by immediately localizing the displayed time 
	instead of requiring user input to set the initial time. I also feel that I could have found a way to prevent the menu from 'expanding' as the clock 
	advanced, as it will currently push the spacers out of alignment as the clock moved into double-digits.

-     Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?

	I found the prospect of running multiple functions simultaneously within a single class file to be the most challenging aspect of this project. I tried
	to resolve the issue with strategically placed function calls to skip through the program, but this continued to cause errors in the UI such as flickering, input
	lag or even runaway function calls leading to a crash. Utilizing multithreading, while it may not be the most efficient tool for more complex projects, is a tool 
	that I am glad to include in my list of known resources.

-     What skills from this project will be particularly transferable to other projects or course work?

	The usage of multithreading and experience with basic UI design, in addition to building in a  measure of input validtion
	will all prove useful in future projects.

-    How did you make this program maintainable, readable, and adaptable?

	I ensured that each function was clearly marked out with simple in-line comments detailing what specific sections of code were meant to do. I also kept 
	my variable naming conventions consistent across global and function variable to help keep track of scope. Finally, I broke up variables and arithmetic with
	spacing to make the program easier to read in the future. 
