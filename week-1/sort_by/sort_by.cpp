#include "airline_ticket.h"
#include "test_runner.h"

#include <algorithm>
#include <numeric>
#include <sstream>
using namespace std;

// Реализуйте этот макрос, а также необходимые операторы для классов Date и Time
#define SORT_BY(field)  \
	([](const AirlineTicket& lh, const AirlineTicket& rh)  \
	{ return (lh.field < rh.field); })

void TestSortBy() {
  vector<AirlineTicket> tixs = {
    {"VKO", "AER", "Utair",     {2018, 2, 28}, {17, 40}, {2018, 2, 28}, {20,  0}, 1200},
    {"AER", "VKO", "Utair",     {2018, 3,  5}, {14, 15}, {2018, 3,  5}, {16, 30}, 1700},
    {"AER", "SVO", "Aeroflot",  {2018, 3,  5}, {18, 30}, {2018, 3,  5}, {20, 30}, 2300},
    {"PMI", "DME", "Iberia",    {2018, 2,  8}, {23, 00}, {2018, 2,  9}, { 3, 30}, 9000},
    {"CDG", "SVO", "AirFrance", {2018, 3,  1}, {13, 00}, {2018, 3,  1}, {17, 30}, 8000},
  };

  sort(begin(tixs), end(tixs), SORT_BY(price));
  ASSERT_EQUAL(tixs.front().price, 1200);
  ASSERT_EQUAL(tixs.back().price, 9000);

  sort(begin(tixs), end(tixs), SORT_BY(from));
  ASSERT_EQUAL(tixs.front().from, "AER");
  ASSERT_EQUAL(tixs.back().from, "VKO");

  sort(begin(tixs), end(tixs), SORT_BY(arrival_date));
  ASSERT_EQUAL(tixs.front().arrival_date, (Date{2018, 2, 9}));
  ASSERT_EQUAL(tixs.back().arrival_date, (Date{2018, 3, 5}));
}

void TestDate() {
	ASSERT_EQUAL((Date{2018, 2, 9} < Date{2020, 1, 3}), true);
	ASSERT_EQUAL((Date{2018, 2, 9} < Date{2018, 3, 3}), true);
	ASSERT_EQUAL((Date{2020, 2, 9} < Date{2020, 2, 10}), true);
	ASSERT_EQUAL((Date{2020, 2, 9} < Date{2020, 1, 3}), false);
	ASSERT_EQUAL((Date{2018, 2, 9} < Date{2018, 2, 9}), false);

	ostringstream ss;
	ss << Date{2018, 2, 9} << " " << Date{18, 12, 12};
	string expected = "[09,02,2018] [12,12,0018]";
	ASSERT_EQUAL(ss.str(), expected);

	ASSERT_EQUAL((Date{2020, 2, 9} == Date{2020, 2, 9}), true);
	ASSERT_EQUAL((Date{2020, 2, 9} == Date{2021, 2, 9}), false);
}

void TestTime() {
	ASSERT_EQUAL((Time{10, 12} < Time{11, 12}), true);
	ASSERT_EQUAL((Time{12, 14} < Time{12, 15}), true);
	ASSERT_EQUAL((Time{9, 2} < Time{11, 12}), true);
	ASSERT_EQUAL((Time{12, 12} < Time{12, 12}), false);
	ASSERT_EQUAL((Time{12, 12} < Time{11, 12}), false);

	ostringstream ss;
	ss << Time{12, 12} << ' ' << Time{1, 1};
	string expected = "(12:12) (01:01)";
	ASSERT_EQUAL(ss.str(), expected);

	ASSERT_EQUAL((Time{9, 2} == Time{9, 2}), true);
	ASSERT_EQUAL((Time{12, 12} == Time{12, 1}), false);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestDate);
  RUN_TEST(tr, TestTime);
  RUN_TEST(tr, TestSortBy);
}

