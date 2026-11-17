#include <iostream>
#include <vector>

using namespace std;

// Base class
class MediaDevice {
public:
    virtual void play() const {
        cout << "[MediaDevice] Playing generic media stream." << endl;
    }

    virtual void stop() const {
        cout << "[MediaDevice] Stopping playback." << endl;
    }

    virtual ~MediaDevice() {} // Virtual destructor for safe polymorphic destruction
};

// Derived class 1: AudioPlayer
class AudioPlayer : public MediaDevice {
public:
    void play() const override {
        cout << "[AudioPlayer] Playing high-resolution MP3/FLAC audio track." << endl;
    }

    void stop() const override {
        cout << "[AudioPlayer] Pausing and stopping audio track." << endl;
    }
};

// Derived class 2: VideoPlayer
class VideoPlayer : public MediaDevice {
public:
    void play() const override {
        cout << "[VideoPlayer] Rendering 4K HDR video stream." << endl;
    }

    void stop() const override {
        cout << "[VideoPlayer] Stopping video stream and clearing frame buffer." << endl;
    }
};

int main() {
    cout << "============================================================" << endl;
    cout << " EXPERIMENT 15: RUNTIME POLYMORPHISM VIA VIRTUAL FUNCTIONS  " << endl;
    cout << "============================================================" << endl;

    // Demonstrating runtime dynamic dispatch using Base class pointers
    MediaDevice* device = nullptr;

    AudioPlayer myAudio;
    VideoPlayer myVideo;

    cout << "\n1. Base pointer pointing to AudioPlayer object:" << endl;
    device = &myAudio;
    device->play(); // Calls AudioPlayer::play() at runtime via vtable
    device->stop();

    cout << "\n2. Base pointer pointing to VideoPlayer object:" << endl;
    device = &myVideo;
    device->play(); // Calls VideoPlayer::play() at runtime via vtable
    device->stop();

    cout << "\n3. Array/Vector of Base Pointers (Uniform Polymorphic Handling):" << endl;
    vector<MediaDevice*> playlist = { &myAudio, &myVideo };
    for (auto dev : playlist) {
        dev->play();
    }

    return 0;
}
