#include "Executor.h"
#include <exception>
#include <string>

namespace Executor {
    Result::operator double() const {
        if (!valid)
            throw problem.c_str();
        return value;
    }

    Result::Result(const double value, const bool valid, const std::string problem) 
    :
    value(value),
    valid(valid),
    problem(problem)
    {}

    Result secureRun(const Function &fun, const double x) {
        Result r;
        try {
            r = Result(fun(x), true, "");            
        } catch (const bool &exc) {
            r.valid = exc;
            r.problem = "Boolean of value false thrown";
        } catch (const char *exc) {
            r.problem = exc;
        }
        return r;
    }
}

std::ostream & operator<<(std::ostream &out, const Executor::Result &r) {
    out << "ERROR " << r.problem;
    return out;
}