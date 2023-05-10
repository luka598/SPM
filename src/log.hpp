#include <sstream>
#include <iostream>
#include <stdexcept>

namespace SPM::Log{
    enum LogLevel{
        INFO,
        WARN,
        ERROR,
    };

    class Logger {
        public:
           template <typename T>
                friend Logger & operator<<(Logger &l, T &t){
                    l.message << t;
                    return l;
                }

            friend Logger & operator<<(Logger &l, LogLevel ll){
                std::stringstream out;
                out << "[" << __func__ << "@" << __FILE__ << ":" << __LINE__ << "] ";
                switch (ll){
                    case LogLevel::INFO:
                        out << "INFO";
                        break;
                    case LogLevel::WARN:
                        out << "WARNING";
                        break;
                    case LogLevel::ERROR:
                        out << "ERROR";
                        break;
                }
                out << ": " << l.message.str();
                l.message.clear();
                if (ll == LogLevel::ERROR) throw std::runtime_error(out.str());
                return l;
            }

        private:
            std::stringstream message;
    };
}
