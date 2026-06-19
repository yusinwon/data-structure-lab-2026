#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;

//Music class
class Music {
private:
	string title;
	string artist;
	string album;
	int year;

public:
	Music(string title, string artist, string album, int year) {
		this->title = title;
		this->artist = artist;
		this->album = album;
		this->year = year;
	}
	string gerTitle() { return title; }
	string gerArtist() { return artist; }
	string gerAlbum() { return album; }
	int getYear() { return year;  }
};

//Music Streaming Service Class
class MusicStreamingService {
private:
	string serviceName;
	vector<Music> musiclist;

public:
	MusicStreamingService(string name) {
		this->serviceName = name;
	}
	//Add a music to the service
	void addMusic(string title, string artist, string album, int year) {
		Music newMusic(title, artist, album, year);
		musiclist.push_back(newMusic);
		cout << title <<  " by "  << "added to " << serviceName << endl;
	}
	//Search by title
	Music* searchByTitle(string title) {
		for (int i = 0; i < musicListsize(); i++) {
			if (musicList[i].getTitle() == title) {
				return &musicList[i];
			}
		}
		return NULL;
	}
	// search by artist
	vector <Music*>searchByArtist(string artist) {
		vector<Music*> result;
		for (int i = 0; i < Music_ist.size(); i++) {
			// artist의 MusicList에 있는 artist가 같으면 resuit에 추가
			(musicList[i].getArtist() == artist) {
			result.push_back(&musicList[i]);
		}
	}
	return result;
	}
};
