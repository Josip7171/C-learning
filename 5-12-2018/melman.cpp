#include <iostream>
int main (){
	int first_measure_hour = 0, first_measure_minute = 0, number_of_measures = 0;
	int measured_temp = 0, time_counter = 0, max_temp = 0, marker = 0;

	std::cin >> first_measure_hour >> first_measure_minute >> number_of_measures;
	time_counter = first_measure_hour*60 + first_measure_minute;
	for(int i = 0; i < number_of_measures; i++){
		std::cin >> measured_temp;
		time_counter +=30;
		if(measured_temp > max_temp){
			max_temp = measured_temp;
			marker = i;
		}
	}
	int final_time = time_counter - ((number_of_measures - marker-1) * 30);
	//netreba ukupno vrijeme nego ono vrijeme kada je izmjerena najvisa temperatura, prepraviti kod !!!!!
	std::cout << max_temp << std::endl << final_time / 60 << std::endl << final_time% 60;
}