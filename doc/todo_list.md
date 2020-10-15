# Exercise: ToDo List

Try to get familiar with your development environment and the basic syntax of C++ and some fundamental parts of the standard library. At the end of this exercise you should have your first C++ program running.

You will implement a command-line ToDo List application to keep things simple. The user should be able to control the application textually. A project is already setup for you in the `todo_list` folder. Implement the whole application in `todo_list.cpp`.

1. Run the code as is to check whether the compiler is working and your code runs.

2. Run the dummy unit test with `ctest`

3. When the program starts, print an overview of all available commands. Users
   should be able to `add` and `delete` todos and to `list` them and finally to `exit` the
   program.

4. The program should wait for a command from the user.

   _Hint:_ Use the std::getline
   function to read input from the user into an `std::string`.

5. If the user types `add` and return, print a message which asks the user to enter the text for
   the task. Read the task description from the console and add it to the task list.

6. If the user types `delete` and return, print a message which asks for the index of the task
   to be deleted. Read an integer with the >> operator. Then use getline again to
   clear the input buffer. You may ignore the output of getline.

7. If the user types `list` and return, print a list of todos. Output the index for each todo in
   front of its description.

8. If the user types `exit` and return the program should end. Otherwise the program will again
   ask for a command.

9. Finally our ToDo List application has to save and load the task list so users do not
   have to keep the application open all the time. When the program starts, try to
   read the `todolist.txt`. Each line of the file contains a todo description.

   You can use the ifstream and ofstream file streams from the <fstream> header to
   read from and write to files:

   ```cpp
   std::ifstream file(“todolist.txt”);
   ```

   The resulting file object can be used the same way as `std::cin`. This also applies
   to the output stream `std::ostream`. `std::getline` can also be used for input file
   streams. You can test whether you are at the end of the stream by using the file
   object directly in a condition:

   ```cpp
   if (file) {
    std::getline(file, line);
   }
   ```

10. Save the todo list in the `todolist.txt` file after the user selects the exit command,
    just before the program ends. Write each todo in a single line.
