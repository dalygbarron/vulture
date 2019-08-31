#include "src/util.h"

int util_whitespace(char c) {
    return c == ' ' || c == '\n' || c == '\t';
}

int util_min(int a, int b) {
    return (a < b) ? a : b;
}

int util_max(int a, int b) {
    return (a > b) ? a : b;
}

struct Rect util_inner(struct Rect rect) {
    rect.pos.x++;
    rect.pos.y++;
    rect.size.x -= 2;
    rect.size.y -= 2;
    return rect;
}

struct Vector util_vAdd(struct Vector a, struct Vector b) {
    a.x += b.x;
    a.y += b.y;
    return a;
}

struct Vector util_vSub(struct Vector a, struct Vector b) {
    a.x -= b.x;
    a.y -= b.y;
    return a;
}

struct Vector util_vMult(struct Vector a, struct Vector b) {
    a.x *= b.x;
    a.y *= b.y;
    return a;
}

struct Vector util_vDiv(struct Vector a, struct Vector b) {
    a.x /= b.x;
    a.y /= b.y;
    return a;
}

struct Vector util_vMod(struct Vector a, struct Vector b) {
    a.x %= b.x;
    a.y %= b.y;
    return a;
}

struct Colour util_cAdd(struct Colour a, struct Colour b) {
    a.red += b.red;
    a.green += b.green;
    a.blue += b.blue;
    return a;
}

struct Colour util_cSub(struct Colour a, struct Colour b) {
    a.red -= b.red;
    a.green -= b.green;
    a.blue -= b.blue;
    return a;
}

struct Colour util_cMult(struct Colour a, struct Colour b) {
    a.red = (a.red * b.red) / 255;
    a.green = (a.green * b.green) / 255;
    a.blue = (a.blue * b.blue) / 255;
    return a;
}

struct Colour util_cFMult(struct Colour a, float b) {
    a.red = (float)a.red / 255.0 * b * 255;
    a.green = (float)a.green / 255.0 * b * 255;
    a.blue = (float)a.blue / 255.0 * b * 255;
    return a;
}

struct Colour util_cFDiv(struct Colour a, float b) {
    a.red = (float)a.red / 255.0 / b * 255;
    a.green = (float)a.green / 255.0 / b * 255;
    a.blue = (float)a.blue / 255.0 / b * 255;
    return a;
}
