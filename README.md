# Task-manager-project
This contain a project related to a somple task manager made in C which saves tasks locally on machine and contains memory of what was written before it.

#About
This project was build to excercise some concepts of C:-
- File Handling in C
- Struct and array handling
- Memory management

#Requirements-
- GCC compiler
- Any machilne like Mac,Linux,Windows.


## compile
gcc src/main.c -o main

#How to use

#add task
./main add task1
.main add "play game"

#list all tasks
./main list     
1|task1|not_done

2|play game|not_done

#mark done
./main done 1
./main list
1|task1|done

2|play game|not_done

#delete
./main delete 1
./main list
2|play game|not_done

#Data storage
Tasks are saved at:
- Linux/Mac: ~/tasklinelists.txt
- Windows: C:\Users\username\tasklinelists.txt

you can open the source file in any text editor to view your tasks

