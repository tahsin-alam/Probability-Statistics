//
// Created by tahsi on 11/17/2017.
//
#include <string>
#include <vector>
#include <cmath>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <stdio.h>
#include <math.h>

#ifndef STOCK_PRICE_STOCKPRICE_H
#define STOCK_PRICE_STOCKPRICE_H
class stockprice
        {
                public:
                static constexpr double interest_rate = 0.005;
                static  constexpr double init_capital = 1000;
                static constexpr double stock_price = 100;
                static   constexpr double stock_owned = 0;

                 static  double money_owned;
                 static double Stock_price;
                 static double num_of_stocks;

                 static int months;

                static  int N; // total number number of simulations
                static std::vector<double> total_simulations;


                static void savings();
                static void stock_game ();

                // number of simulation generator.
                static double simulation_generator(double buy_price, double sell_price);

                //performs N simulations and stores the data in total_simulations array
                static void generate_N_Simulations(double buy_price, double sell_price, int simulations);

                //returns the mean of the given array
                static double sample_mean(std::vector<double> &arr, int simulations);
                // computes variance
                static double sample_variance(std::vector<double> &arr, int simulations);

                static void new_SimulationsArray();
                //computes success rate.
                static double success_rate(std::vector<double> &arr, double len, double oppsite);
                static void main(std::vector<std::wstring> &args);//main function.


        };



#endif //STOCK_PRICE_STOCKPRICE_H
