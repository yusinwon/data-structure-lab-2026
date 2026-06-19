#include "Rectangle.h"
#include "Pet.h"
#include "Music.h"
using namespace std;
int main() {
	Rectangle rect1(4, 6);
	cout << "Rectangle 1: " << endl;
	//print("Rectangle 1:\n");
	cout << "Area:" << rect1.getArea() << endl;
	//printf("Area: %lf\n", rect1.getArea());
	cout << "Perimeter:" << rect1.getPerimeter() << endl;
	cout << "is Square?:" << boolalpha << rect1. isSquare() << endl;
	printf("=================================\n");

	Pet myPet("Lucky", 5, "dog");
	cout << "My pet's name is " << myPet.getName() << endl;
	Puppy myPuppy("Kong", 3, "dog", "puddle");
	cout << "My puppy's bread is " << myPuppy.getBread() << endl;
	printf("=================================\n");

	// creat a new music streaming service
	MusicStreamingService myService("Melon");
	//Add some music is the service
	myService.addMusic("Jump", "Black pink", "Jump", 2025);
	myService.addMusic("Swim", "BTS", "ARIRANG", 2025);
	myService.addMusic("Bang Bang", "IVE", "REVIVE", 2025);
	myService.addMusic("Jump", "Black pink", "Jump", 2025);
	//Search by title
	string music_title;
	cout << "Enter tha Music Title: "
	cin >> music_title;
	Music* result = myService.searchByTitle(music_title);
	if (result i = NULL) {
		cout << "Found:" << result->gerTitle() << endl;
	else {
		cout << "Not Found" << endI;
	}
	//Search by artist
	string artist_name;
	cout << "Enter the artist name: ";
	cin >> artist_name;

	vector<Music> artistResult = myService.searchByArtist(artist_name);
	if (artistResult.size() > 0) {
		cout << "Found" << artistResult.size() << " songs by" << artist_name << ":" << endI;
		for (int i = 0; i < artistResult.size(); i++) {
			cout << artistResult[i]->getTitle() << endI;
		}
	}
	else {
		cout << "Not Found" << endI;
	}
	}
	return 0;
}