//
// Created by tahsin on 11/17/2017.
//
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <stdio.h>
#include <math.h>
#include"stockprice.h"


double stockprice::money_owned = 0;
double stockprice::Stock_price = 0;
double stockprice::num_of_stocks = 0;
int stockprice::months=60;
int stockprice::N = 16577;
std::vector<double> stockprice::total_simulations(N);
void stockprice::stock_game() {
    while(months>60){
        int prb=1+rand()%100;// random number generator between 1 to 100.
        std::cout<<"probability:"<<prb<<'\n';
        if(prb<=50){
            Stock_price=Stock_price;
        }
        else if(prb<=75){
            Stock_price=Stock_price*0.95;
        }
        else if(prb<=100){
            Stock_price=Stock_price*1.05;
        }
        std::cout<<"stock price at that probability:"<<stock_price<<'\n';
        // if price drops below 95 convert all capital to stocks.
        if(Stock_price<95 && (init_capital/stock_price) > 1) {
            num_of_stocks = num_of_stocks +floor( init_capital / stock_price);
            money_owned = init_capital - (floor( init_capital / stock_price) * stock_price);
        }
        // if price goes up to 110 buy all of them.
        if(Stock_price>110){
            money_owned=init_capital+(num_of_stocks*stock_price);
            num_of_stocks=0;
        }
        money_owned=init_capital*interest_rate;
        months+=1;
        std::cout << "After month " << months << ", your balance is : $" << init_capital << ", num of stocks : "<<num_of_stocks<<'\n';


    }


}

// monthly savings without buying any stocks. Money saved in account. If we run it we get income of $1348.85 after 60 months.
void stockprice::savings() {
    money_owned = money_owned *(1 + interest_rate);

}

double stockprice::simulation_generator(double buy_price, double sell_price) {
    money_owned=init_capital;
    Stock_price=Stock_price;
    num_of_stocks= stock_owned;

    double cuurent_money = 0;
    if (num_of_stocks == 0)
    {
        // if we dont buy any stocks.
        cuurent_money = money_owned;
    }
    else if (money_owned == 0)
    {
        //means all the money is used to buy stocks
        cuurent_money = num_of_stocks*stock_price;
    }
    return cuurent_money;
}

double stockprice::sample_mean(std::vector<double> &arr, int simulations) {
  double all=0;
    for(int i = 0; i < simulations; i++){
        all+=arr[i];
    }
    return (all/simulations);
}

double stockprice::sample_variance(std::vector<double> &arr, int simulations) {
    double s_mean = sample_mean(arr,simulations);
    double numerator = 0;
    for (int i = 0; i < simulations; i++)
    {
        numerator += std::pow((arr[i] - s_mean),2);
    }

    return (numerator / (simulations - 1));


}

void stockprice::new_SimulationsArray() {
    for (int i = 0; i < N; i++) {
        total_simulations[i] = 0;
    }

}

    double stockprice::success_rate(std::vector<double> &arr, double len, double oppsite) {
    int larger = 0;

    for (int i = 0; i < len; i++)
    {
        if (arr[i] > oppsite)
        {
            larger++;
        }
    }


    double total_number_of_simulations = len;

    double success_rate;
    success_rate = (larger / total_number_of_simulations)*100;
    return success_rate;
}

void stockprice::generate_N_Simulations(double buy_price, double sell_price, int simulations) {
    new_SimulationsArray();
    for (int i = 0; i < simulations; i++)
    {
        total_simulations[i] = simulation_generator(buy_price,sell_price);
    }
}


//main file to generate mean, variance and success rate.
void stockprice::main(std::vector<std::wstring> &args) {

    generate_N_Simulations(95, 110, N);
    std::cout<<"stock bought  at $ 95"<<",Stock sold at $ 110"<<'\n'<< "sample mean:"<<sample_mean(total_simulations,N)<< '\n'<< "sample variance:"<<sample_variance(total_simulations,N)<<'\n';
    std::cout << "success rate:" << success_rate(total_simulations, N, 1348.85);
}










