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
	//������
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
	//������
	void setBookName(string& other) {
		if (other.empty()) {
			cout << "�������� ������! �������� ����� �� ����� ���� ������." << endl;
		}
		else {
			bookName = other;
		}
	}

	void setBookAuthor(string& other) {
		if (other.empty()) {
			cout << "�������� ������! ��� ������ �� ����� ���� ������." << endl;
		}
		else {
			bookAuthor = other;
		}
	}

	void setPages(int& other) {
		if (other < 0) {
			cout << "�������� ������! ��������� ������� �� ����� ���� �������������." << endl;
		}
		else {
			pages = other;
		}

	}

	void setGenres(string& other) {
		if (other.empty()) {
			cout << "�������� ������! ���� ����� �� ����� ���� ������." << endl;
		}
		else {
			genres.push_back(other);
		}

	}

	void addGenres(string& genre) {
		if (genre.empty()) {
			cout << "�������� ������! ���� ����� �� ����� ���� ������." << endl;
		}
		else {
			genres.push_back(genre);
		}
	}

	void markAsRead(string& answ) {
		isRead = answ == "y";
		if (isRead) {
			cout << "���������! ����� < '" << getBookName() << "' > �������� �����������." << endl;
		}
		else {
			cout << "���������! ����� < '" << getBookName() << "' > �������� �������������." << endl;
		}
	}

	void addComment(string& newComment) {
		if (newComment.empty()) {
			cout << "�������� ������! ����������� � ����� �� ����� ���� ������." << endl;
		}
		else {
			comments.push_back(newComment);
		}

	}

	void inputGenres() {
		string genre;
		char answer;

		do {
			cout << "������� ���� (��� 'q' ��� ������): ";
			getline(cin, genre);

			if (genre == "q") {
				break;
			}

			addGenres(genre);
			cout << "�������� ��� ���� ����? (y/n): "; cin >> answer;
			cin.ignore();
		} while (answer == 'y');
	}

	void inputComments() {
		string comment;
		char answer;

		do {
			cout << "������� ����������� � ��������� ������ ����� (��� 'q' ��� ������): ";
			getline(cin, comment);

			if (comment == "q") {
				break;
			}

			addComment(comment);
			cout << "�������� ��� ���� �����������? (y/n): "; cin >> answer;
			cin.ignore();
		} while (answer == 'y');
	}


	void showBookInfo() {
		cout << endl;
		cout << "�������� �����: " << getBookName() << endl;
		cout << "����� �����: " << getBookAuthor() << endl;
		cout << "���������� ������� �����: " << getPages() << endl;
		cout << "����� �����: ";
		if (!genres.empty()) {
			for (auto genre : genres) {
				cout << genre << " ";
			}
		}
		else {
			cout << "������ � ����� ��� ���." << endl;
		}

		cout << "����� ���������: " << (isRead ? "��" : "���") << endl;
		cout << "���������� � �����: ";
		if (!comments.empty()) {
			for (auto com : comments) {
				cout << com << " ";
			}
		}
		else {
			cout << "���������� � ����� ��� ���." << endl;
		}
	}
};

int main() {
	setlocale(0, "ru");
	string title, author;
	int pages;

	cout << "������� �������� �����: ";
	getline(cin, title);

	cout << "������� ������: ";
	getline(cin, author);

	cout << "������� ���������� �������: "; cin >> pages;
	cin.ignore();
	cout << endl;

	Book book1(title, author, pages);

	book1.inputGenres();
	book1.inputComments();
	string answer;

	cout << "����� ���������/�� ���������? (y/n): ";
	getline(cin, answer);
	book1.markAsRead(answer);

	book1.showBookInfo();
}
