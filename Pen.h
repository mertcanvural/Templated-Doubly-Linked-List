#include <iostream>

class Pen
{
private:
    std::string name = "";
    std::string color = "";

public:
    Pen();
    Pen(const std::string &n, const std::string &c);
    bool operator==(const Pen &other) const;
    friend bool isZany(const Pen &p);
    friend std::ostream &operator<<(std::ostream &out, const Pen &c);
};