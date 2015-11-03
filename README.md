# C Systems Programming
A repository containing C programming projects that I have completed which relate to systems programming. 


## I.  Folder Structure

~/C_Systems_Programming/include: Contains all header files for programs found within the src folder   
~/C_Systems_Programming/lib:     Contains all libraries    
~/C_Systems_Programming/mnsms:   Contains the source files for a fully functional shell [Incomplete at this time]    
~/C_Systems_Programming/src:     Contains individual folders for each project.  Each project folder contains the source code and Makefile for that project    
~/C_Systems_Programming/test:    Contains the test code for all projects located in the src folder


## II.  Projects

*  my: A basic library containing functions for basic string/vector manipulation, comparison, and printing.   
*  list:  A doubly linked circular list.    
*  minitalk: The server is responsible for reading in messages from the client in the form of signals.  The client sends        messages to the server via signals one message at a time.  
*  pipes: A basic pipes program which sends the user input message from the grandparent to the parent, and then the child       process.  
*  socket:  A client server chat application that allows for multiple users to connect and chat on a single server using        sockets.  
*  gtk: A graphical user interface for the above socket chat application.  The GUI is implemented using the GTK toolkit.  
*  myselect:  A program which allows for a user to select and highlight user input items through a menu interface.  The         menu/selection interface is generated using termcaps.  
*  minishell:  A very basic command line shell that allows for program execution, directory navigation, and file listing.   
*  mnsms: "My Not so Mini Shell" A full command line shell supporting all terminal capabilities [still under construction].


## III.  Build & Execution Instructions

1.  Navigate to ` ~/C_Systems_Programming/src/[PROJECTNAME] `
2.  Type make command: ` make `
3.  Run Program using ` ./executableName [argument1] [argument2]... ` All programs provide a usage message describing the proper input standard.  In order to view this usage message simply type ` ./executableName `.  For client-server programs, simply open two terminal windows and execute the client in the first, and the server in the second.  
