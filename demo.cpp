#include "pch.h"
#include "demo.h"

MusicPlayer::MusicPlayer()
{
    _volume = volume::low;
}

MusicPlayer::~MusicPlayer()
{

}

void MusicPlayer::LoadPlayList(const string& playlist)
{
    _playlist = playlist;
    _files.clear();

    ifstream file(_playlist);
    string song;
    while( getline(file, song) )
    {
        _files.push_back(song);
    }
}

void MusicPlayer::SetVolume(volume volume)
{
    _volume = volume;
    cout << "Setting volume to " << ToString(volume) << endl;
}

void MusicPlayer::Play()
{
    for(string song: _files)
    {
        PrivateAPI::Play(song);
    }
}

string MusicPlayer::ToString(volume volume)
{
    string ret;
    switch (volume)
    {
    case volume::low:
        ret = "low";
        break;
    
    case volume::medium:
        ret = "medium";
        break;

    case volume::high:
        ret = "high";
        break;

    case volume::concert:
        ret = "concert";
        break;
    }

    return ret;
}
