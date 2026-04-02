#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Person {
	int id, age;
	string name, hometown;
	friend istream& operator>>(istream& in, Person& p) {
		cout << "Enter person information:" << endl;
		cout << "\t+ Id: ";
		in >> p.id;
		cout << "\t+ Name: ";
		in.ignore();
		getline(in, p.name);
		cout << "\t+ Age: ";
		in >> p.age;
		cout << "\t+ Home town: ";
		in.ignore();
		getline(in, p.hometown);
		return in;
	}
	friend ostream& operator<<(ostream& out, Person p) {
		out << "Person information:" << endl;
		out << "\t+ Id: " << p.id << endl;
		out << "\t+ Name: " << p.name << endl;
		out << "\t+ Age: " << p.age << endl;
		out << "\t+ Home town: " << p.hometown << endl;
	}
};

void show(vector<Person> p) {
	if (p.size() == 0)
		cout << "An empty list" << endl;
	else {
		//for (int i = 0; i < p.size(); i++) {
		for (int i = p.size() - 1; i >= 0; i--) {
			cout << "\t+ Id: " << p[i].id << endl;
			cout << "\t+ Name: " << p[i].name << endl;
			cout << "\t+ Age: " << p[i].age << endl;
			cout << "\t+ Hometown: " << p[i].hometown << endl;
			cout << endl;
		}
	}
}
bool Remove(vector<Person>& p, int id) {
	for (int i = 0; i < p.size(); i++) {
		if (p[i].id == id) {
			p.erase(p.begin() + i);
			return true;
		}
	}
	return false;
}

void Find(vector<Person> p, string name) {
	bool found = false;
	for (int i = p.size() - 1; i >= 0; i--) {
		if (p[i].name == name) {
			found = true;
			cout << "Person information:" << endl;
			cout << "\t+ Id: " << p[i].id << endl;
			cout << "\t+ Name: " << p[i].name << endl;
			cout << "\t+ Age: " << p[i].age << endl;
			cout << "\t+ Home town: " << p[i].hometown << endl;
		}
	}
	if (!found)
		cout << "No person is found with name" << name << endl;
}

void Export(vector<Person> p, string filename) {
	ofstream out(filename);
	if (!out.is.open()) {
		cout << "Can't open file: " << filename << endl;
		return;
	}
	for (int i = 0; i < p.size(); i++) {
		out << p[i].id << endl;
		out << p[i].name << endl;
		out << p[i].age << endl;
		out << p[i].hometown << endl;
	}
	out.close();
	cout << "Export successfully to files: " << filename << endl;
}

void Import(vector<Person>& p, string filename) {
	ifstream in(filename);
	if (!in.is_open()) {
		cout << "Can't open file: " << filename << endl;
		return;
	}
	p.clear();
	while (!in.eof()) {
		Person a;
		a.id = 0;
		in >> a.id;
		in.ignore()
		getline(in, a.name);
		in >> a.age;
		in.ignore();
		getline(in, a.hometown);
		if (a.id == 0)
			break;
		p.push_back(a);
	}
	in.close();
	cout << "Import successfully from file: " << filename << endl;
}

int main() {
	vector<Person> list;
	do {
		system("cls");
		cout << "---- HUMAN RESOURCE MANAGEMENT ----" << endl;
		cout << "1. Show person list" << endl;
		cout << "2. Add a person" << endl;
		cout << "3. Remove a person by id" << endl;
		cout << "4. Find people by name" << endl;
		cout << "5. Export to file" << endl;
		cout << "6. Import from file" << endl;
		cout << "0. Quit" << endl;
		cout << "-----------------------------------" << endl;
		cout << "Your command: " << endl;
		int cmd;
		cin >> cmd;
		switch (cmd) {
		case 1: {
			show(list);
			break;
		}
		case 2: {
			//Person a;
			//cout << "Id: ";
			//cin >> a.id;
			//cout << "Name: ";
			//cin >> a.name;
			//cout << "Age: ";
			//cin >> a.age;
			//cout << "Hometown: ";
			//cin >> a.hometown;
			//list.push_back(a);

			Person a;
			cin >> a;
			list.push_back(a);
			break;
		}
		case 3: {
			int removeID;
			cout << "Enter id to remove: ";
			cin >> removeID;
			bool res = Remove(list, removeID);
			if (res)
				cout << "Remove successfully" << endl;
			else
				cout << "Id not found. Try again" << endl;
			break;
		}
		case 4: {
			string name;
			cout << "Enter name to find: ";
			cin.ignore();
			getline(cin, name);
			Find(list, name);
			break;
		}
		case 5: {
			Export(list, "25TH2.dla");
			break;
		}
		case 6: {
			Import(list, "25TH2.dla");
			break;
		}
		case 0: {
			return 0;
		}
		default: {
			cout << "Your command isn't found. Try again" << endl;
		}
		}
		cout << "Press Enter to continue...";
		cin.ignore();
		cin.get();
	} while (true);
}