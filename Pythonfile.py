import re
import string


###########EXAMPLE FUNCTIONS##############
#def printsomething():
#    print("Hello from python!")

#def PrintMe(v):
#    print("You sent me: " + v)
#    return 100;

#def SquareValue(v):
#    return v * v

##########################################


#this function reads a file line by line and keeps track of 
#word frequency
def printFrequency() :

	file = open("Release\CS210_Project_Three_Input_File.txt", 'r') #open the file for reading

	namesFrequencies = {} #initialize the dictionary

	#read each line of the file creating dict keys for each new occurance
	#and incrementing each existing occurance
	for line in file :
	      
		line = line.strip() #convert to raw input

		#case where key already exists
		if(line in namesFrequencies.keys()) :
			
			#increment value
			namesFrequencies[line] = namesFrequencies.get(line) + 1

		#new key
		else :
			
			namesFrequencies[line] = 1


	#loop through our finished dictionary to print
	for key in namesFrequencies.keys() :
		print(key, namesFrequencies.get(key))

	#close file
	file.close()

#this function reads a file line by line to a dictionary and keeps
#track of word frequency. Then it returns the frequency of the word
#passed in (item)
def returnFrequency(item) :

	file = open("Release\CS210_Project_Three_Input_File.txt", 'r') #open the file for reading

	namesFrequencies = {} #initialize the dictionary

	#read each line of the file creating dict keys for each new occurance
	#and incrementing each existing occurance
	for line in file :
	      
		line = line.strip() #convert to raw input

		#case where key already exists
		if(line in namesFrequencies.keys()) :
			
			#increment value
			namesFrequencies[line] = namesFrequencies.get(line) + 1

		#new key
		else :
			
			namesFrequencies[line] = 1


	#return the frequency. In the case where the item is not in the dict return 0
	if(item in namesFrequencies.keys()) :
		return namesFrequencies.get(item)

	else :
		return 0

	#close file
	file.close()

#this function reads a file line by line to a dictionary and keeps
#track of word frequency. Then it writes a new file which contains
#a histogram of the keys and values. The values are represented by
#the value # of special chars
def writeHistogram() :
	

	########################### READ ########################################

	fileRead = open("Release\CS210_Project_Three_Input_File.txt", 'r') #open the file for reading

	namesFrequencies = {} #initialize the dictionary

	#read each line of the file creating dict keys for each new occurance
	#and incrementing each existing occurance
	for line in fileRead :
	      
		line = line.strip() #convert to raw input

		#case where key already exists
		if(line in namesFrequencies.keys()) :
			
			#increment value
			namesFrequencies[line] = namesFrequencies.get(line) + 1

		#new key
		else :
			
			namesFrequencies[line] = 1

	############################ WRITE ######################################

	fileWrite = open("frequency.dat", 'w') #create and open file to write to

	#print each key
	for key in namesFrequencies.keys() :

		#write key to file followed by a space
		fileWrite.write(key + " ")
		#write value to file followed by a newline
		fileWrite.write(str(namesFrequencies.get(key)) + "\n")
	
	print("Write success") #print when finished writing
	fileWrite.close() #close file