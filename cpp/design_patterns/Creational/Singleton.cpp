// Singleton.cpp
// Real-world example: Logger singleton
// Shows thread-safe Meyers singleton in a simple example (non-threaded demo here).

#include <iostream>
#include <memory>
#include <string>

class Logger {
public:
	static Logger& instance() {
		static Logger inst; // Meyers' singleton, lazy-initialized in a thread-safe way
		return inst;
	}

	void log(const std::string& s) {
		std::cout << "[LOG] " << s << std::endl;
	}

private:
	Logger() { }
	~Logger() = default;
	Logger(const Logger&) = delete;
	Logger& operator=(const Logger&) = delete;
};

int main() {
	Logger::instance().log("Application started");
	Logger::instance().log("Doing work...");
	Logger::instance().log("Application finished");
	return 0;
}

