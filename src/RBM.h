/*
 * RBM.h
 *
 *  Created on: Jan 8, 2014
 *      Author: sk
 */

#pragma once

#include "ofMain.h"

double randn(double mu, double sigma);

class RBM {
public:

    RBM();
    ~RBM();

    void init(int image_sqr, int n_hidden_sqr,
            float* data, float *labels, int n_samples, int batch_size);
    void allocate();
    void release();
    void setTrainMode(int train_method, int k);

    void update();
    void updateMiniBatch();
    void updateSimParallel(); // code split into parallelizable pieces

    void makeImages(); // images for visualization

    int image_side; // initially, used only for rectangular images
    int h_image_side; // image used for hidden units visualization

    int n_visible; // number of visible and hidden units
    int n_hidden;

    // training stuff
    //============================================================================
    float *training_data;
    float *labels;
    float *sample_offset;
    uint32_t n_training_samples;
    uint32_t sample_i;
    uint32_t epoch_i;

    // mini-batch training
    uint32_t batch_size;
    uint32_t batch_i;

    // basic learning parameters
    float learning_rate;
    float momentum;
    float weightcost;   // L2 regularization
    bool pcd_on;        // persistent CD
    int k;              // sampling steps number

    // additional options for better features
    bool inhibit_sparsity;
    float sparsity_k;
    float sparsity_target;
    bool inhibit_selectivity;
    float selectivity_k;
    float selectivity_target;

    // activity monitoring
    float *mean_activity; // per-hidden-unit weighted activity
    float q; // total current hidden units activity

    // units from data
    float *v_data;
    float *h_data_prob;
    float *h_data;

    // running sampling
    float *v_prob;
    float *v;
    float *h_prob;
    float *h;

    float *vt;

    float *W;
    float *Wt;
    float *b_inc;
    float *c_inc;
    float *W_inc;

    float *pos_weights; // for gradient approximation
    float *neg_weights;

    //============================================================================

    vector<ofImage *> filters;
    ofImage *v_bias;
    ofImage *h_bias;

    int images_n;
    vector<ofImage *> v_data_images;
    vector<ofImage *> h_data_prob_images;
    vector<ofImage *> h_data_images;
    vector<ofImage *> v_prob_images;
    vector<ofImage *> v_images;

    ofImage *v_data_image;
    ofImage *h_data_prob_image;
    ofImage *h_data_image;

    ofImage *v_prob_image;
    ofImage *v_image;

    ofImage *h_prob_image;
    ofImage *h_image;
};

