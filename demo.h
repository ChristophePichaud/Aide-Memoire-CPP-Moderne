#pragma once

enum volume
{
    low,
    medium,
    high,
    concert
};

class MusicPlayer
{
public:
    MusicPlayer();
    ~MusicPlayer();

public:
    void LoadPlayList(const string& playlist);
    void SetVolume(volume volume);
    void Play();
    string ToString(volume volume);

private:
    volume _volume;
    string _playlist;
    vector<string> _files;
};

class PrivateAPI
{
public:
    static void Play(const string& song) { cout <<  "Playing " << song << " ..." << endl; }
};
