#pragma once

#include "ofMain.h"

#include "RBM.h"

class testApp: public ofBaseApp {

    deque<ofImage *> images;

    // MNIST dataset info
    ifstream data_file;
    int magic_number;
    int number_of_images;
    int n_rows;
    int n_cols;

    RBM *rbm;

    bool readBatch(int n);

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
};
