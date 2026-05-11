FitNest

---DESCRIPTION---

A console based software that helps people identify, track, and manage their phyisical activities and status.

Created by: Calix Gabriel B. Sindac 

This also serves as partial fullfillment for the course

---USAGE---

The program must be run on main.cpp and should have visibilty on 'data' directory. 
The directory should be 'FitNest---Fitness-and-Health-Tracker---DSA-Final-Project' when running / compiling the program

---LANGUAGE---

This project is writted using mostly C++ with little C elements found in the code.

variables are written in snake case

---DIRECTORIES---

(1) data/
    - contains txt files for data storage.

    user_info.txt
        - file that stores the user's name, age, height, and weight.
        - parsed through extract_user_info function in file_handler.cpp

    physical_activities.txt 
        - file that stores all Physical_Activites logged by the user
        - parsed through extract_activities function in file_handler.cpp

    [FLAG]
    [ENTRY TEXT]
    ...
    [ENDING FLAG]

    '--ENTRY--' for physical_activities.txt
    '--END--' for user_info.txt

    FLAGS for physical_activities.txt
    '-D' denotes the date logged
    '-N' denotes the name of the activity
    '-T' denotes the time done in minutes
    '-C' denotes the calories burned

    FLAGS for user_info.txt
    '-N' denotes the user's name
    '-A' denotes the user's age
    '-H' denotes the user's height
    '-W' denotes the user's weight

(2) src/
    - contains all .cpp files.
    - see following section for more inforamtion about the cpp files


---CPP FILES---

(1) main.cpp
    - The main file where the program runs. Here, you can find the main program loop.

(2) headers.cpp
    - A file containing all the libraries used in the whole project.
    - Is included in all the cpp files in the project.

(3) file_handler.cpp
    - contains all the functions pertaining to file manipulations.
    - Appending to & reading physical_activities.
    - Writing to & reading user_info.txt.

    - ACTIVITY_PATH & USER_INFO are file paths and can be changed based on the user's specifications. Just make sure it is in the 
      data/ directory.

(4) functions.cpp
    - Contains all the functions used in the program.
    - Functions related to modifying the User or Physical_Acticity struct are passed by reference.

(5) structures.cpp
    - Contains structures, enums, and constants used in file_handler.cpp and functions.cpp
    - Maps for MET values and exercises based on categories are in this file
