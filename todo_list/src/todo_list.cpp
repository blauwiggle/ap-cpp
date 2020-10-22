#include "todo_list.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

std::vector<std::string> todos;

void print(const std::vector<std::string> &list)
{
    int i = 0;
    std::cout << "ToDos:\n";
    for (const auto &element : list)
    {
        std::cout << i++ << "\t" << element << "\n";
    }
}

void add()
{
    std::cout << "Enter a new ToDo:\n";
    std::string todo;
    std::getline(std::cin, todo);
    todos.push_back(todo);
}

void remove()
{
    std::cout << "Enter index to delete:\n";
    int i;
    std::cin >> i;
    std::string line;
    std::getline(std::cin, line);
    if (i >= todos.size() || i < 0)
    {
        std::cout << "Index out of bounds";
    }
    else
    {
        todos.erase(todos.begin() + i);
    }
}

bool parseCommand()
{
    std::string command;

    std::cout << "Enter a command [add, delete, list, exit]:\n";
    std::getline(std::cin, command);

    if (command == "add")
    {
        add();
    }
    else if (command == "delete")
    {
        remove();
    }
    else if (command == "list")
    {
        print(todos);
    }
    else if (command == "exit")
    {
        return false;
    }
    return true;
}

std::vector<std::string> loadTodos(const std::string &filename)
{
    std::ifstream file(filename);
    std::vector<std::string> todos;
    std::string line;
    while (std::getline(file, line))
    {
        todos.push_back(line);
    }
    return todos;
}

void saveTodos(const std::vector<std::string> &todos, const std::string &filename)
{
    std::ofstream file(filename);
    for (auto &todo : todos)
    {
        file << todo << "\n";
    }
}

int runTodoList(int argc, char *argv[])
{
    todos = loadTodos("todos.txt");
    do
    {
    } while (parseCommand());

    saveTodos(todos, "todos.txt");
    return 0;
}
