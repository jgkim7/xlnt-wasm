#include "embind_helper.hpp"

std::string typeOf(emscripten::val value)
{
    return value.typeOf().as<std::string>();
}

void throwError(const std::string& msg)
{
    EM_ASM_({ throw Pointer_stringify($0); }, msg.c_str());
}

void throwTypeError(const std::string& msg)
{
    EM_ASM_({ throw new TypeError(Pointer_stringify($0)); }, msg.c_str());
}