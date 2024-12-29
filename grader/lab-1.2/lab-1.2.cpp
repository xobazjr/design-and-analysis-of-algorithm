#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class my_class{
	public:
    	vector<int> my_vector;

    	void add(int value){
        	my_vector.push_back(value);
    	}

    	int find_max() {
        	int max = 1,count = 1;

        	for (int i = 0; i < my_vector.size() - 1; i++){
            	if (my_vector[i] == my_vector[i + 1]) {
                	++count;
            	} else {
                	if (count > max){
                    	max = count;
                	}
                	count = 1;
            	}
        	}

        	if (count > max){
            	max = count;
        	}

        	return max;
    	}

    	int find_min(int max){
        	int min = max,count = 1;

        	for (int i = 0; i < my_vector.size() - 1; i++){
            	if (my_vector[i] == my_vector[i + 1]){
                	++count;
            	} else {
                	if (count < min){
                    	min = count;
                	}
                	count = 1;
            	}
        	}

        	if (count < min){
            	min = count;
        	}

        	return min;
    	}

    	int freq_diff(){
        	sort(my_vector.begin(), my_vector.end());

        	int max = find_max();
        	int min = find_min(max);

        	return (max - min);
    	}
};
int main() {
    my_class mc;
    int n, value;

    while (true){
        cin>>n;
        if (n > 1 && n < 1000000){
            break;
        }
    }

    for (int i=0;i<n;i++){
        cin>>value;
        mc.add(value);
    }cout<<mc.freq_diff()<<endl;

    return 0;
}

