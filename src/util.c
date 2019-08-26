struct Vector vAdd(struct Vector a, struct Vector b) {
    a.x += b.x;
    a.y += b.y;
    return a;
}

struct Vector vSub(struct Vector a, struct Vector b) {
    a.x -= b.x;
    a.y -= b.y;
    return a;
}

struct Vector vMult(struct Vector a, struct Vector b) {
    a.x *= b.x;
    a.y *= b.y;
    return a;
}

struct Vector vDiv(struct Vector a, struct Vector b) {
    a.x /= b.x;
    a.y /= b.y
}

struct Vector vMod(struct Vector a, struct Vector b) {
    a.x %= b.x;
    a.y %= b.y;
}
