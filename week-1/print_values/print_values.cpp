#include "test_runner.h"

#include <ostream>
using namespace std;

#define PRINT_VALUES(out, x, y) { out << (x) << endl; out << (y) << endl; }
// or #define PRINT_VALUES(out, x, y) out << (x) << endl << out << (y) << endl

int main() {
  TestRunner tr;
  tr.RunTest([] {
    ostringstream output;
    int n = 5;
    // при использовании неверного макроса ниже будет ошибка
    if(true) PRINT_VALUES(output, ++n, "red belt")
    else PRINT_VALUES(output, --n, "red belt");
    ASSERT_EQUAL(output.str(), "6\nred belt\n");
  }, "PRINT_VALUES usage example");
}
