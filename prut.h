#pragma once

// Disable prutprint
#define prutprintf(fmt, ...)

// Short version "file:line: message"
// #define prutprintf(fmt, ...) printf("\x1b[37m%s:%d:\x1b[0m " fmt "\n", __FILE_NAME__, __LINE__, __VA_ARGS__)

// Long version "function (file:line): message"
// #define prutprintf(fmt, ...) printf("\x1b[37m%s (%s:%d):\x1b[0m " fmt "\n", __PRETTY_FUNCTION__, __FILE_NAME__, __LINE__, __VA_ARGS__)

#define prutprint(s) prutprintf("%s", s)

