#include "test_runner.h"
#include <vector>

using namespace std;

// Реализуйте здесь шаблонный класс Table
template <typename T>
class Table {
public:

	Table(size_t _strings, size_t _columns) : columns(_columns), strings(_strings), table(strings, vector<T>(columns)) {}

	pair<size_t, size_t> Size() const {
		return { strings, columns };
	}

	/*  Можно проще, здесь такое лишнее
	 *  Тесты это проходит

	struct Iterator {
		Iterator(vector<T>& string) : str(string) {}
		T& operator[](size_t column) {
			return str[column];
		}
		const T& operator[](size_t column) const {
			return str[column];
		}
		vector<T>& str;
	};

	Iterator operator[](size_t string) {
		return Iterator(table[string]);
	}
	const Iterator operator[](size_t string) const {
		return Iterator(table[string]);
	}
	*/

	vector<T>& operator[](size_t str) {
		return table[str];
	}

	const vector<T>& operator[](size_t str) const {
		return table[str];
	}

	void Resize(size_t new_strings, size_t new_columns) {
		columns = new_columns;
		strings = new_strings;
		table.resize(strings);
		for(auto& string : table) {
			string.resize(columns);
		}
	}

private:
	size_t columns, strings;
	vector<vector<T>> table;
	/*
	 * Table:
	 *
	 * vector<T> { ... }
	 * vector<T> { ... }
	 * .....
	 * .....
	 *
	 */
};

void TestTable() {
  Table<int> t(2, 5);
  ASSERT_EQUAL(t.Size().first, 2u);
  ASSERT_EQUAL(t.Size().second, 5u);
  t[1][2] = 42;
  ASSERT_EQUAL(t[1][2], 42);
  t.Resize(5, 4);
  ASSERT_EQUAL(t.Size().first, 5u);
  ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestTable);
  return 0;
}
