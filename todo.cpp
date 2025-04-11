#include "todo.h"
#include <stdexcept>

void TodoList::init() {
    // TODO: set size to 0 and all task pointers to nullptr
    size = 0;
    for (int i = 0; i < MAX_TASKS; ++i) {
        tasks[i] = nullptr;
    }
}

void TodoList::destroy() {
    // TODO: delete all tasks and reset pointers
    for (int i = 0; i < size; ++i) {
        delete[] tasks[i];
        tasks[i] = nullptr;
    }
}

int TodoList::string_length(const char* str) const {
    // TODO: return the number of characters before '\0'
    int length = 0;
    while (str[length] != '\0') length++;
    return length;
}

void TodoList::string_copy(char* dest, const char* src) const {
    // TODO: copy characters from src to dest
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; 
}

void TodoList::add_task(const char* task) {
    // TODO: if full, throw. otherwise allocate and copy new task
    if (size==MAX_TASKS) throw std::invalid_argument("full task unavailable");
    else{
        tasks[size] = new char[string_length(task)+1];
        string_copy(tasks[size], task);
        size++;
    }
}

void TodoList::remove_task(int index) {
    // TODO: check bounds, delete task, shift left
    if (index<0 || index>=size) throw std::invalid_argument("index out of range");
    else{
        delete tasks[index];
        for(int i=0;i<size-index-1;i++) tasks[index+i] = tasks[index+i+1];
        tasks[size-1] = nullptr;
        size--;
    }
}

const char** TodoList::get_pending_tasks(int& count) const {
    // TODO: set count and return task array
    count = size;
    const char** task_array = new const char*[size];
    for(int i=0;i<size;i++) task_array[i] = tasks[i];
    return task_array;
}