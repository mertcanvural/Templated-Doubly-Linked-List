#include <iostream> 
using namespace std;

#include "zany.h"
#include "Pen.h"
#include "ZLL.h"

template <typename T>
void reportZany(const T &param) {
	cout << param << " is ";
	if (!isZany(param)) cout << "not ";
	cout << "zany" << endl;
}

int main() {
    int one = 1;
	int two = 2;
	string one_str = "one";
	string two_str = "Two";
	reportZany(one);
	reportZany(two);
	reportZany(one_str);
	reportZany(two_str);
	Pen one_pen("p1", "black");
	Pen two_pen("p2", "blue");
	reportZany(one_pen);
	reportZany(two_pen);

	ZLL<int> zll1;
	ZLL<string> zll2;
	ZLL<Pen> zll3;
	ZLL<Pen> zll4;
	ZLL<Pen> zll5;

	zll1.back(1);
	zll2.back("two");
	zll3.back(one_pen);
	zll3.back(two_pen);

	zll4.back(one_pen);
	zll3.show();
	zll4.show();
	zll3.join(zll4);
	zll3.show();
	zll4.show();
	zll3.join(zll5);
	zll3.empty();
	zll3.show();
	
}
