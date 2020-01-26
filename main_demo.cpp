#include "pch.h"
#include "demo.h"

int main_books()
{
    MusicPlayer mp; 
    //MusicPlayer mp("Slash.pl"); // it works !
    mp.LoadPlayList("Slash.pl");
    mp.SetVolume(volume::medium);
    mp.Play();
    return 0;
}
