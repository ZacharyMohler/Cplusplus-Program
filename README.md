# Grocery Tracker Program
Zachary Mohler CS210 SNHU 12/15/2021 

#Summarize the project and what problem it was solving.
This project's prompt was that a grocery store had commissioned a program to be made to deal with data the store collected on grocery items purchased throughout the day. Their own existing grocery tracking would create a file with each item purchased throughout the day on a new line in chronological order such as:

flour
eggs
bread

My task was to write a multi-language program in C++ and Python that would read the file and use the data to do various things. The options given to the user were:

1) print each item and it's quantity as a number
2) return the quantity of an item the user inputs
3) write a new file containing the items and their quantities as a number, then read the new file and print a histogram
4) quit

the challenge was to use C++ and Python in tandem, using C++ for user interaction and Python for dealing with the files and data.


#What did you do particularly well?
As is my standard for myself I think my formatting was very neat and readable.
But I also would applaud myself for not slicing the item quantity from the frequency file in user option 3, instead opting for the use of string stream to get the element. This was trickier but also much more stable, as it handles cases where the item quantity is much larger than 100. 

#Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
I am quite proud of this program because it uses the absolute most of my current knowledge and is currently in it's best state that I am aware of. I may return to this section and add notes as my knowledge improves.

#Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
I found reading a file in C++ to be the most time consuming, though I didn't find any particular aspect to this project overly challenging. I 'overcame' this by looking at the C++ documentation. This is my go-to for optimising and understanding things better. Why google vague questions when you can just look at the documentation where it's all right there for you? 

#What skills from this project will be particularly transferable to other projects or course work?
I would like to say "using multiple languages" here, but seeing as we weren't really taught how to hook them up, rather just use them together. I'll instead say the finalization of my learning C++. This is obviously transferable to my future classes and career as well. 

#How did you make this program maintainable, readable, and adaptable?
Organization, planning, and methodical writing. This allows me to write my code in a readable way. All my functions and variables are appropriately named and have inline comments as documentation for maintanability and adaptability. Anyone with a base understanding of the languages could read my code and not be lost or stumped by any line I have written.
