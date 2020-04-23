#include <string>
#include <vector>

using namespace std;

// Реализуйте этот макрос так, чтобы функция main компилировалась
#define UNIQ_ID f(__LINE__)
#define f(x) g(x)
#define g(x) uniq##x


int main() {
  int UNIQ_ID = 0;
  string UNIQ_ID = "hello";
  vector<string> UNIQ_ID = {"hello", "world"};
  vector<int> UNIQ_ID = {1, 2, 3, 4};
}
