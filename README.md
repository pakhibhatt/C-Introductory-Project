# C-Introductory-Project

Overview: 
For this project, we'll be using data from recent US presidential elections, with results for each county. (For those not from the US, every state is divided into counties for a level of government between the state and the individual cities--in almost every state, all land is part of a county. For example, Chicago and many close suburbs are in Cook County.) The example data given to you is real, from the MIT election lab (https://electionlab.mit.edu/data), although your project will need to work with other candidates and parties, as described in the project, so that it works for future elections as well.
You must use classes in this project. You must use a Votes class in this project to keep track of the each set of results. The Votes class should keep track of only one set of votes (so, the votes for one candidate in one county), so the main function or another class should have a vector of Vote to be able to keep track of the full set of results.



Data: 
A few sample files are provided for you, and your program should work with any valid file, including files with different candidates and different parties. Each set of data is on a separate line in the file, with the following information, separated by commas:
● State
● County
● Candidate
● Party
● Number of Votes
For example:
ILLINOIS,COOK,BARACK OBAMA,DEMOCRAT,1488537
This is from the 2012 election, and tells us that President Obama received 1,488,537 votes in Cook County. His opponents' votes are listed on separate lines in the file (for that election just Mitt Romney, the Republican candidate, is listed individually, and then there is information for "Other" which combines all others receiving votes).
A few sample files are provided for you. Note that you cannot assume the number of candidates--in 2020, for example, the libertarian candidate Jo Jorgensen received enough votes to be included separately, and the autograder will use other test files with more candidates.
