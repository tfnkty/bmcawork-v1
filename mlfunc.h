#ifndef MLFUNC_H
#define MLFUNC_H

#include <mlpack.hpp>
#include <iostream>
#include <vector>

/*#define std::vector<std::vector<double>> rddatanew = {
    {5.6817, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0},   // 3H
    {49.47, 100, 0, 0, 0, 0, 0, 0, 0, 0, 1},    // 14C
    {555.1, 99.867, 1368.625, 99.994, 2754.008, 99.867, 472.2023, 99.9, 0, 0, 2}, // 24Na
    {48.758, 100, 0, 0, 0, 0, 0, 0, 0, 0, 3},   // 35S
    {95.77, 99.88, 1173.228, 99.85, 1332.492, 99.9826, 6.93, 18.3947, 0, 0, 4}, // 60Co
    {17.4394, 100, 0, 0, 0, 0, 0, 0, 0, 0, 5},  // 63Ni
    {251.59, 99.563, 290.34, 78.5, 151.195, 75.2, 304.87, 14, 0, 0, 6}, // G 85Kr
    {203.2, 93.81, 259.5, 85.61, 22.163, 55.1289, 21.99, 29.2459, 23.173, 24.7917, 7}, // G 109Cd
    {174.32, 94.7, 661.657, 85.1, 0, 0, 0, 0, 0, 0, 8}, // G 137Cs
    {61.777, 99.99, 0, 0, 0, 0, 0, 0, 0, 0, 9},  // B 147Pm
    {160.32, 41.42, 208.01, 47.98, 0, 0, 0, 0, 0, 0, 10}, // B 192Ir
    {244.05, 97.08, 0, 0, 0, 0, 0, 0, 0, 0, 11}, // B 204Tl
    {5304.33, 100, 0, 0, 0, 0, 0, 0, 0, 0, 12}, // A 210Po
    {4784.34, 94.07, 4845.3, 56.2, 4901, 10.2, 14.92, 80, 16.072, 27, 13}, // X 229Th
    {4620.5, 23.4, 4687, 76.3, 0, 0, 0, 0, 0, 0, 14}, // A 230Th
    {4364.6, 18.94, 4395.7, 57.79, 185.713, 57.2, 15.784, 27.7, 0, 0, 15}, // G (?) 235U
    {5456.3, 28.98, 5499.03, 70.91, 0, 0, 0, 0, 0, 0, 16}, // A 238Pu
    {5442.8, 13.1, 5485.56, 84.8, 59.5409, 35.9, 17.136, 36.64, 0, 0, 17}, // G 241Am
    {5762.64, 23.1, 5804.77, 76.9, 0, 0, 0, 0, 0, 0, 18}, // A 244Cm
    {6075.64, 14.81, 6118.1, 81.49, 0, 0, 0, 0, 0, 0, 19}  // A 252Cf
};*/

void MaterialID(unsigned int *Spectrum)
{
    std::cout << "...Looking for peaks..." << std::endl;
    std::cout << "...Looking for peaks..." << std::endl;
    std::cout << "...Looking for peaks..." << std::endl;
//  std::vector<double> y(341);
//    for (int i = 0; i <= 340; ++i) {
//        y[i] = 100 - i + (1.0 / 10) * i * i - (1.0 / 500) * i * i * i +
//               (1.0 / 100000) * i * i * i * i - (1.0 / 68500000) * i * i * i * i * i;
//    }

    std::vector<double> m(340, 0);
    for (int i = 0; i < 340; ++i) {
        m[i] = (int) Spectrum[i + 1] - (int) Spectrum[i];
    }

    std::vector<double> a(339, 0);
    for (int i = 0; i < 339; ++i) {
        a[i] = m[i + 1] - m[i];

    }

    int tol = 4;
    int cnt = 0;
    int pkc = 0;
    int peaks[2][10];
    std::cout << "Here" << std::endl;
    for (int i = 0; i < 339; ++i) {
        if (m[i + 1] < 0 && m[i] > 0) {
            for (int j = -tol; j <= tol; ++j) {
                if (a[i + j] < 0) {
                    cnt++;
                }
            }
        }
        if (cnt == 2 * tol - 1) {
            if ((int) Spectrum[i] > 1000)
                std::cout << i << ", " << (int) Spectrum[i] << std::endl;
            if (pkc < 10) {
                peaks[0][pkc] = i;
                peaks[1][pkc] = (int) Spectrum[i];
                pkc++;
            }
        }
        cnt = 0;
    }
}

void IDAlgorithm() {
    std::vector<double> testdat = {172.82, 98.1, 659.102, 83.9, 162.23, 42.41, 207.74, 47.51, 0, 0}; // 137Cs, 192Ir
    double dif = std::numeric_limits<double>::max();
    double per = 0;
    double tempdif = 0;
    std::vector<int> loc = {0, 0};
    std::vector<double> results(testdat.size() / 2, 0); // Assuming rddatanew has the same number of columns as testdat
    std::vector<std::vector<double>> rddatanew = {
        {5.6817, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0},   // 3H
        {49.47, 100, 0, 0, 0, 0, 0, 0, 0, 0, 1},    // 14C
        {555.1, 99.867, 1368.625, 99.994, 2754.008, 99.867, 472.2023, 99.9, 0, 0, 2}, // 24Na
        {48.758, 100, 0, 0, 0, 0, 0, 0, 0, 0, 3},   // 35S
        {95.77, 99.88, 1173.228, 99.85, 1332.492, 99.9826, 6.93, 18.3947, 0, 0, 4}, // 60Co
        {17.4394, 100, 0, 0, 0, 0, 0, 0, 0, 0, 5},  // 63Ni
        {251.59, 99.563, 290.34, 78.5, 151.195, 75.2, 304.87, 14, 0, 0, 6}, // G 85Kr
        {203.2, 93.81, 259.5, 85.61, 22.163, 55.1289, 21.99, 29.2459, 23.173, 24.7917, 7}, // G 109Cd
        {174.32, 94.7, 661.657, 85.1, 0, 0, 0, 0, 0, 0, 8}, // G 137Cs
        {61.777, 99.99, 0, 0, 0, 0, 0, 0, 0, 0, 9},  // B 147Pm
        {160.32, 41.42, 208.01, 47.98, 0, 0, 0, 0, 0, 0, 10}, // B 192Ir
        {244.05, 97.08, 0, 0, 0, 0, 0, 0, 0, 0, 11}, // B 204Tl
        {5304.33, 100, 0, 0, 0, 0, 0, 0, 0, 0, 12}, // A 210Po
        {4784.34, 94.07, 4845.3, 56.2, 4901, 10.2, 14.92, 80, 16.072, 27, 13}, // X 229Th
        {4620.5, 23.4, 4687, 76.3, 0, 0, 0, 0, 0, 0, 14}, // A 230Th
        {4364.6, 18.94, 4395.7, 57.79, 185.713, 57.2, 15.784, 27.7, 0, 0, 15}, // G (?) 235U
        {5456.3, 28.98, 5499.03, 70.91, 0, 0, 0, 0, 0, 0, 16}, // A 238Pu
        {5442.8, 13.1, 5485.56, 84.8, 59.5409, 35.9, 17.136, 36.64, 0, 0, 17}, // G 241Am
        {5762.64, 23.1, 5804.77, 76.9, 0, 0, 0, 0, 0, 0, 18}, // A 244Cm
        {6075.64, 14.81, 6118.1, 81.49, 0, 0, 0, 0, 0, 0, 19}  // A 252Cf
    };
    // Placeholder for rddatanew, replace with actual data
    // std::vector<std::vector<double>> rddatanew; // Initialize with actual data

    for (size_t i = 0; i < testdat.size(); i += 2) {
        for (size_t j = 0; j < rddatanew.size(); j++) {
            for (size_t k = 0; k < 9; k += 2) {
                tempdif = rddatanew[j][k] - testdat[i];
                if (std::abs(tempdif) < std::abs(dif)) {
                    dif = tempdif;
                    per = rddatanew[j][k + 1];
                    loc = {static_cast<int>(j), static_cast<int>(k)};
                }
            }
        }
        // Output loc
        std::cout << "loc: [" << loc[0] << ", " << loc[1] << "]" << std::endl;
        dif = std::numeric_limits<double>::max();
        per = 0;
        tempdif = 0;
        loc = {0, 0};
    }
}

void MLDecisionTree()
{
    mlpack::DecisionTree tree;
    mlpack::data::Load("DT.bin", "tree", tree, true);
    arma::mat spX = { {174, 0, 661, 0, 0, 0, 0, 0, 0, 0} };
    size_t outputsp;
    arma::vec probssp;
    tree.Classify(spX, outputsp, probssp);
    std::cout << "Single Point ID: " << outputsp << std::endl;
}

void MLRandomForest()
{
    mlpack::RandomForest rf;
    mlpack::data::Load("RF.bin", "rf", rf, true);
    arma::mat spX = { {174, 94.7, 661, 85.1, 0, 0, 0, 0, 0, 0} };
    size_t outputsp;
    arma::vec probssp;
    rf.Classify(spX, outputsp, probssp);
    std::cout << "Single Point ID: " << outputsp << std::endl;
}

void MLHoeffdingTree()
{
    mlpack::HoeffdingTree ht;
    mlpack::data::Load("HT.bin", "ht", ht, true);
    arma::mat spX = { {174, 94.7, 661, 85.1, 0, 0, 0, 0, 0, 0} };
    size_t outputsp;
    double probssp;
    ht.Classify(spX, outputsp, probssp);
    std::cout << "Single Point ID: " << outputsp << std::endl;
}

#endif // MLFUNC_H
