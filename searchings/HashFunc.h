#ifndef HASHFUNC_H
#define HASHFUNC_H
#include <string>

template <class T> struct hash;
template <> struct hash<const char *> {
    unsigned int operator()(const char *str) const {
        unsigned int h = 0;
        while (*str) {
            h = 31 * h + (*str++);
        }
        return h;
    }
};

template <> struct hash<char *> {
    unsigned int operator()(char *str) const {
        hash<const char *> func;
        return func(str);
    }
};

template <> struct hash<std::string> {
    unsigned int operator()(const std::string &str) const {
        hash<const char *> func;
        return func(str.c_str());
    }
};

#endif  // HASHFUNC_H
