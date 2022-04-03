#include <iostream>
#include <string>
using namespace std;

enum genre { Drama = 1, Thriller, Action, Horror };

struct movie {
	string name;
	string director;
	string genre;
	int rating;
	int prise;
};

string genreMovi() {

	int key;
	string s = "";
	cout << "Drama - 1, Thriller - 2, Action - 3, Horror -4" << endl;
	cout << "Enter genere movie: ";
	cin >> key;
	switch (key)
	{
	case Drama: s = "Drama";
		break;
	case Thriller: s = "Thriller";
		break;
	case Action: s = "Action";
		break;
	case Horror: s = "Horror";
		break;
	}
	return s;
}

movie createMovie() {
	movie temp;
	cout << "-------------------" << endl;
	cout << "Enter name movie: ";
	getline(cin, temp.name);
	cout << "Enter director movie: ";
	getline(cin, temp.director);
	temp.genre = genreMovi();	
	cout << "Enter rating movie: ";
	cin >> temp.rating;
	cout << "Enter prise movie: ";
	cin >> temp.prise;
	cout << "-------------------" << endl;
	return temp;
}

void printMovie(movie m) {
	cout << endl;
	cout << "Name - " << m.name << endl;
	cout << "Director - " << m.director << endl;
	cout << "Genre - " << m.genre << endl;
	cout << "Rating - " << m.rating << endl;
	cout << "Prise - " << m.prise << endl;
	
}

movie* createCollectionMovie(movie* mov, int& size) {
	mov = new movie[size];
	for (int i = 0; i < size; i++) {
		mov[i] = createMovie();
	}
	return mov;
}

void printColection(movie* films, int size) {
	for (int i = 0; i < size; i++) {
		printMovie(films[i]);
		
	}
}

movie* addCollection(movie* films, int& size) {
	movie* temp = new movie[size + 1];
	for (int i = 0; i < size; i++) {
		temp[i] = films[i];
	}
	
	temp[size] = createMovie();
	delete[]films;
	size++;
	return temp;

}

movie* findGenre(movie* mov, int size, string gen) {
	movie* temp = nullptr;
	int cont = 0;
	for (int i = 0; i < size; i++) {
		if (mov[i].genre == gen) {
			cont++;
		}
	}

	temp = new movie[cont];

	for (int i = 0; i < cont; i++) {
		for (int j = i; j < size; j++) {
			if (mov[i].genre == gen) {
				temp[i] = mov[j];
			}
		}
	}

	return temp;

}

int main() {


	/*Создать структуру ВИДЕОМАГАЗИН со следующими 
	полями:
	■ Название фильма;
	■ Режиссер;
	■ Жанр;
	■ Рейтинг популярности;
	■ Цена диска.
	Реализовать следующие возможности:
	■ Поиск по названию;
	■ Поиск по жанру;
	■ Поиск по режиссеру;
	■ Самый популярный фильм в жанре;
	■ Показ всех записей и добавление.*/

	movie* films = nullptr;
	movie* find = nullptr;
	int size;
	cout << "Enter number movie: ";
	cin >> size;
	films = createCollectionMovie(films, size);
	printColection(films, size);

	string gen = genreMovi();

	find = findGenre(films, size, gen);
	

	delete[]films;
	delete[]find;
}