#pragma once

#include <string>
#include <iomanip>

using namespace std;

struct Date {
  int year, month, day;

  friend ostream& operator<<(ostream& out, const Date& date) {
	  out << '['
			  << setw(2) << setfill('0')
			  << date.day <<  '-' << setw(2) << setfill('0')
			  << date.month << '-' << setw(4) << setfill('0') << date.year << ']';
	  return out;
  }

  friend bool operator==(const Date& one, const Date& two) {
	  if(one.year != two.year) return false;
	  else if(one.month != two.month) return false;
	  return one.day == two.day;
  }

  friend istream& operator>> (istream& is, Date& dt) {
	  is >> dt.year;
	  is.ignore(1);
      is >> dt.month;
      is.ignore(1);
      is >> dt.day;
      return is;
	}
};

bool operator<(const Date& first, const Date& second) {
	if(first.year != second.year) return first.year < second.year;
	else if(first.month != second.month) return first.month < second.month;
	return first.day < second.day;
}

struct Time {
  int hours, minutes;

  friend ostream& operator<<(ostream& out, const Time& time) {
	  out << '(' << setw(2) << setfill('0') << time.hours
			  << ':' << setw(2) << setfill('0') << time.minutes << ')';
	  return out;
  }

  friend bool operator==(const Time& one, const Time& two) {
	  return ((one.hours == two.hours) && (one.minutes == two.minutes));
  }

  friend istream& operator >> (istream& is, Time& tm) {
      is >> tm.hours;
      is.ignore(1);
      is >> tm.minutes;
      return is;
  }
};

bool operator<(const Time& one, const Time& two) {
	if(one.hours != two.hours) return one.hours < two.hours;
	return one.minutes < two.minutes;
}


struct AirlineTicket {
  string from;
  string to;
  string airline;
  Date departure_date;
  Time departure_time;
  Date arrival_date;
  Time arrival_time;
  int price;
};
