#pragma once

#include <map>
#include <string_view>
#include <sstream>
#include <iostream>
#include <fstream>
#include <functional>

using namespace std;

class Logger {
public:
    enum class Levels { INFO, WARNING, ERROR };
    static inline char *LevelsMap[] = {
            "INFO", "WARNING", "ERROR"
    };

    using Contract = function<void(string)>;

    static void Print(Levels level, string message);
    static void PrintMessage(string message);
    static function<void(Logger::Levels, string)> SetPrefix(string prefix);

    static Contract CreateTask(string title, int numberOfTasks);
};