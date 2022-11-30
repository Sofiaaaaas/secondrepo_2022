#include <iostream>
#include "Movie.h"
#include "Cinema.h"

using namespace std;

int main()
{
	Movie film1(1, "film1", HORROR, 100, 20, 8.7, {"Mon", "Teu", "Wed", "Thu", "Fri", "Sat", "Sun"});
	Movie film2(2, "film2", COMEDY, 90, 25, 7.9, {"Mon", "Wed", "Fri"});
	Movie film3(3, "film3", ACTION, 110, 23, 9, { "Teu", "Thu", "Sat" });
	film3.comment = "The Best film";

	Cinema cinema1("Multiplex", "Lviv", 100, {film1, film2});

	cinema1.add_movie(film3);

	cout << "\nProfit on wednesday: " << cinema1.calculate_profit("Wed") << endl;

	Movie film_find = cinema1.get_movie();

	cout << "\nBest film:" << endl;
	film_find.print();

	cinema1.sort_by_date();
	cout << "\nFilms sorted by release date: " << endl;
	cinema1.print_films();

	return 0;
}