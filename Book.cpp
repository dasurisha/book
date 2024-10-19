#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book
{
private:
	string bookName;
	string bookAuthor;
	int pages;
	vector<string> genres;
	bool isRead;
	vector<string> comments;
public:
	Book(string& bookName, string& bookAuthor, int pages) : isRead(false)
	{
		setBookName(bookName);
		setBookAuthor(bookAuthor);
		setPages(pages);
	}
	//гетеры
	string getBookName() {
		return bookName;
	}

	string getBookAuthor() {
		return bookAuthor;
	}

	int getPages() {
		return pages;
	}

	vector<string> getGenres() {
		return genres;
	}

	bool isBookRead() {
		return isRead;
	}

	vector<string> getBookComments() {
		return comments;
	}
	//сетеры
	void setBookName(string& other) {
		if (other.empty()) {
			cout << "Внимание ошибка! Название книги не может быть пустым." << endl;
		}
		else {
			bookName = other;
		}
	}

	void setBookAuthor(string& other) {
		if (other.empty()) {
			cout << "Внимание ошибка! Имя автора не может быть пустым." << endl;
		}
		else {
			bookAuthor = other;
		}
	}

	void setPages(int& other) {
		if (other < 0) {
			cout << "Внимание ошибка! Нумерация страниц не может быть отрицательной." << endl;
		}
		else {
			pages = other;
		}

	}

	void setGenres(string& other) {
		if (other.empty()) {
			cout << "Внимание ошибка! Жанр книги не может быть пустым." << endl;
		}
		else {
			genres.push_back(other);
		}

	}

	void addGenres(string& genre) {
		if (genre.empty()) {
			cout << "Внимание ошибка! Жанр книги не может быть пустым." << endl;
		}
		else {
			genres.push_back(genre);
		}
	}

	void markAsRead(string& answ) {
		isRead = answ == "y";
		if (isRead) {
			cout << "Сохранено! Книга < '" << getBookName() << "' > отмечена прочитанной." << endl;
		}
		else {
			cout << "Сохранено! Книга < '" << getBookName() << "' > отмечена непрочитанной." << endl;
		}
	}

	void addComment(string& newComment) {
		if (newComment.empty()) {
			cout << "Внимание ошибка! Комментарий к книге не может быть пустым." << endl;
		}
		else {
			comments.push_back(newComment);
		}

	}

	void inputGenres() {
		string genre;
		char answer;

		do {
			cout << "Введите жанр (или 'q' для выхода): ";
			getline(cin, genre);

			if (genre == "q") {
				break;
			}

			addGenres(genre);
			cout << "Добавить еще один жанр? (y/n): "; cin >> answer;
			cin.ignore();
		} while (answer == 'y');
	}

	void inputComments() {
		string comment;
		char answer;

		do {
			cout << "Введите комментарий о прочтении данной книги (или 'q' для выхода): ";
			getline(cin, comment);

			if (comment == "q") {
				break;
			}

			addComment(comment);
			cout << "Добавить еще один комментарий? (y/n): "; cin >> answer;
			cin.ignore();
		} while (answer == 'y');
	}


	void showBookInfo() {
		cout << endl;
		cout << "Название книги: " << getBookName() << endl;
		cout << "Автор книги: " << getBookAuthor() << endl;
		cout << "Количество страниц книги: " << getPages() << endl;
		cout << "Жанры книги: ";
		if (!genres.empty()) {
			for (auto genre : genres) {
				cout << genre << " ";
			}
		}
		else {
			cout << "Жанров у книги ещё нет." << endl;
		}

		cout << "Книга прочитана: " << (isRead ? "Да" : "Нет") << endl;
		cout << "Коментарии к книге: ";
		if (!comments.empty()) {
			for (auto com : comments) {
				cout << com << " ";
			}
		}
		else {
			cout << "Коментарий к книге ещё нет." << endl;
		}
	}
};

int main() {
	setlocale(0, "ru");
	string title, author;
	int pages;

	cout << "Введите название книги: ";
	getline(cin, title);

	cout << "Введите автора: ";
	getline(cin, author);

	cout << "Введите количество страниц: "; cin >> pages;
	cin.ignore();
	cout << endl;

	Book book1(title, author, pages);

	book1.inputGenres();
	book1.inputComments();
	string answer;

	cout << "Книга прочитана/не прочитана? (y/n): ";
	getline(cin, answer);
	book1.markAsRead(answer);

	book1.showBookInfo();
}
