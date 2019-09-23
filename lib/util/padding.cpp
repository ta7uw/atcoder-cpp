// 右詰め
string padding(string s, int width, char fill) {
    ostringstream oss;
    oss << setw(width) << setfill(fill) << s;
    return oss.str();
}


// 左詰め
string padding_left(string s, int width, char fill) {
    ostringstream oss;
    oss << left << setw(width) << setfill(fill) << s;
    return oss.str();
}
