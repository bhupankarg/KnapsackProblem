/*Knapsack problem*/
#include <iostream>
using namespace std;

class Object {
public:
	int profit;
	int weight;
	void setProfitAndWeight(int profit, int weight) {
		this->profit = profit;
		this->weight = weight;
	}
};

class Knapsack {
public:
	void sortProfitByWeight(Object objList[], int totalObjects) {
		for(int i = 0; i < totalObjects; i++) {
			for(int j = 0; j < totalObjects-1-i; j++) {
				double profitByWeight1 = objList[j].profit / objList[j].weight;
				double profitByWeight2 = objList[j+1].profit / objList[j+1].weight;
				if(profitByWeight2 > profitByWeight1) {
					Object temp = objList[j];
					objList[j] = objList[j+1];
					objList[j+1] = temp;
				}
			}
		}
	}

	double getMaxProfit(Object objList[], int capacity) {
		double maxProfit = 0.0;
		for(int i = 0; capacity != 0; i++) {
			if(objList[i].weight <= capacity) {
				maxProfit += objList[i].profit;
				capacity -= objList[i].weight;
			} else {
				maxProfit += (double)(capacity * objList[i].profit) / objList[i].weight;
				capacity -= capacity;
			}
		}
		return maxProfit;
	}
};

int main() {
	int capacity = 15, totalObjects = 7;
	Object* objList = new Object[totalObjects];
	Knapsack* knapsack = new Knapsack;
	objList[0].setProfitAndWeight(10, 2);
	objList[1].setProfitAndWeight(5, 3);
	objList[2].setProfitAndWeight(15, 5);
	objList[3].setProfitAndWeight(7, 7);
	objList[4].setProfitAndWeight(6, 1);
	objList[5].setProfitAndWeight(18, 4);
	objList[6].setProfitAndWeight(3, 1);
	knapsack->sortProfitByWeight(objList, totalObjects);
	cout << knapsack->getMaxProfit(objList, capacity);
	return 0;
}