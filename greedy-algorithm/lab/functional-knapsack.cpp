#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

class KnapsackSolver {
    public:
        vector<int> weights;
        vector<int> values;
        vector<double> ratio;
        vector<double> solution;
        vector<int> original_index;
        int n, W;
        
        void readInput() {
            while(true) {
                cin >> n >> W;
                if(n > 1 && n <= 10 && W >= 1 && W <= 3000) {
                    break;
                }
            }
            
            weights.resize(n);
            values.resize(n);
            ratio.resize(n);
            solution.resize(n, 0.0);
            original_index.resize(n);
            
            for(int i = 0; i < n; i++) {
                cin >> weights[i];
                original_index[i] = i;
            }
            
            for(int i = 0; i < n; i++) {
                cin >> values[i];
            }
        }
        
        void calculateRatios() {
            for(int i = 0; i < n; i++) {
                ratio[i] = static_cast<double>(values[i]) / weights[i];
            }
        }
        
        void sortByRatio() {
            for(int i = 0; i < n - 1; i++) {
                for(int j = 0; j < n - i - 1; j++) {
                    if(ratio[j] < ratio[j + 1]) {
                        swap(ratio[j], ratio[j + 1]);
                        swap(weights[j], weights[j + 1]);
                        swap(values[j], values[j + 1]);
                        swap(original_index[j], original_index[j + 1]);
                    }
                }
            }
        }
        
        double solve() {
            double totalValue = 0.0;
            int currentWeight = 0;
            vector<double> temp_solution(n, 0.0);
            
            for(int i = 0; i < n; i++) {
                if(currentWeight + weights[i] <= W) {
                    temp_solution[i] = 1.0;
                    currentWeight += weights[i];
                    totalValue += values[i];
                } else {
                    double remaining = W - currentWeight;
                    temp_solution[i] = remaining / weights[i];
                    totalValue += values[i] * temp_solution[i];
                    break;
                }
            }
            
            for(int i = 0; i < n; i++) {
                solution[original_index[i]] = temp_solution[i];
            }
            
            return totalValue;
        }
        
        void printSolution(double totalValue) {
            cout << fixed << setprecision(2);
            for(int i = 0; i < n; i++) {
                cout << solution[i] << " ";
            }cout << endl;
            cout << totalValue << endl;
        }
};

int main() {
    KnapsackSolver solver;

    solver.readInput();
    solver.calculateRatios();
    solver.sortByRatio();
    double totalValue = solver.solve();
    solver.printSolution(totalValue);

    return 0;
}