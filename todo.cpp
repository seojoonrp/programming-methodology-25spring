#include "todo.h"
#include <stdexcept>
using namespace std;

void TodoList::init() {
    // TODO: set size to 0 and all task pointers to nullptr

    size = 0;
    for (int i = 0; i < MAX_TASKS; i++) {
        tasks[i] = nullptr;
    }
}

void TodoList::destroy() {
    // TODO: delete all tasks and reset pointers

    for (int i = 0; i < size; i++) {
        delete[] tasks[i];
        tasks[i] = nullptr;
    }
    size = 0;
}

int TodoList::string_length(const char* str) const {
    // TODO: return the number of characters before '\0'

    int i = 0;
    while (str[i] != '\0') {
        i++;
    }

    return i;
}

void TodoList::string_copy(char* dest, const char* src) const {
    // TODO: copy characters from src to dest

    for (int i = 0; i < string_length(src); i++) {
        dest[i] = src[i];
    }

    dest[string_length(src)] = '\0';
}

void TodoList::add_task(const char* task) {
    // TODO: if full, throw. otherwise allocate and copy new task

    if (size == MAX_TASKS) {
        throw overflow_error("Tasks already full");
    }

    tasks[size] = new char[string_length(task) + 1];
    string_copy(tasks[size], task);
    size++;
}

void TodoList::remove_task(int index) {
    // TODO: check bounds, delete task, shift left

    if (index < 0 || index >= size) {
        throw out_of_range("Invalid Index");
    }

    delete[] tasks[index];

    for (int i = index; i < size - 1; i++) {
        tasks[i] = tasks[i + 1];
    }

    tasks[size - 1] = nullptr;
    size--;
}

const char** TodoList::get_pending_tasks(int& count) const {
    // TODO: set count and return task array
    
    count = size;

    return const_cast<const char**>(tasks);
}