#include <iostream>

#include "Pen.h"

Pen::Pen() {
    name = "";
    color = "";
}

Pen::Pen(const std::string &n, const std::string &c) {
	name = n;
	color = c;
}

bool Pen::operator==(const Pen &other) const {
	return ((name == other.name) &&
		(color == other.color));
}

bool isZany(const Pen &t) {
	return (t.color == "black");
}

std::ostream &operator<<(std::ostream &out, const Pen &c) {
	out << c.name << " [" << c.color << "]";
	return out;
}