#include <iostream>
#include <vector>
using namespace std;

class counting_sort{
	public:
		vector <int> my_vector;
		
	void add(int value){
		my_vector.push_back(value);
	}
	
	void print(){
		if(!my_vector.empty()){
			for(int i=0;i<my_vector.size();i++){
				cout<<my_vector[i]<<" ";
			}cout<<endl;
		}
	}
	
	int find_max(){
		if(!my_vector.empty()){
			int max = my_vector[0];
			for(int i=1;i<my_vector.size();i++){
				if(my_vector[i] > max){
					max = my_vector[i];
				}
			}
			return max;
		}
		return -1;	
	}
	
	int find_min(){
		if(!my_vector.empty()){
			int min = my_vector[0];
			for(int i=1;i<my_vector.size();i++){
				if(my_vector[i] < min){
					min = my_vector[i];
				}
			}
			return min;
		}
		return -1;	
	}
	
	void sort(){
		if(!my_vector.empty()){
			int size = find_max() - find_min() + 1;
			int temp[size];
			for(int i=0;i<size;i++){
				temp[i] = 0;
			}
			for(int i=0;i<my_vector.size();i++){
				int size_arr = (my_vector[i] - find_min());
				temp[size_arr] = my_vector[i];
			}
			for(int i=0;i<size;i++){
				if(temp[i] > 0){
					cout<<temp[i]<<" ";
				}
			}cout<<endl;
		}
	}
		
};

int main(){
	counting_sort my_sort;
	
	//add value
	my_sort.add(551);
	my_sort.add(220);
	my_sort.add(551);
	my_sort.add(912);
	my_sort.add(81);
	my_sort.add(32);
	my_sort.add(754);
	my_sort.add(613);
	my_sort.add(109);
	
	//befort-counting-sort
	my_sort.print(); //output: 551 220 551 912 81 32 754 613 109
	
	//after-counting-sort
	my_sort.sort(); //output: 32 81 109 220 551 613 754 912

	return 0;
}
