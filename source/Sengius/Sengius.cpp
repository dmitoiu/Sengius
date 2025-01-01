/**
 * --------------------------------------------------------------------------
 *  Copyright [2024] [Darie-Dragos Mitoiu]
 *
 * Licensed under the Sengius License, Version 1.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.dmitoiu.ro/licenses/LICENSE-1.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * --------------------------------------------------------------------------
 */


#include <iostream>
#include <string>
#include <Windows.h>
#include <bitset>


double calculateBloodVolume(double weight)
{
	// Applying High School Biology Class Formula for blood volume
	// The blood is 7% from the total human body weight
	// E.g: in my case I have 70kg so this results in (7.0 / 100.0) * 70 = 4.9 liters of blood
	const double result = (7.0 / 100.0) * weight;
	return result;
}

std::string binary(std::string data)
{
	std::string result;
	for(char c : data)
		result += std::bitset<8>(c).to_string() + " ";
	return result;
}

bool isNumber(std::string data)
{
	try
	{
		size_t pos;
		std::stod(data, &pos);
		return pos == data.length();
	} catch (std::exception &exception)
	{
		return false;
	}
}

std::string command()
{
	std::string data;
	std::cin >> data;
	return data;
}

int main()
{
	double weight = 0;
	std::string data;
	char separator = '-';
	std::cout << "Sengius v1.0.0: Human Body Blood Volume Calculator" << std::endl;
	std::cout << std::string(62, separator) << std::endl;
	std::cout << binary("Sengius") << std::endl;
	while(true)
	{
		std::cout << "Enter the weight of the person in Kilograms (Kg): ";
		data = command();
		if(isNumber(data))
		{
			weight = std::stod(data);
			if (weight <= 0)
			{
				std::cout << "Weight must be a positive value." << std::endl;
				continue;
			}
			double value = calculateBloodVolume(weight);
			std::cout << "The estimated blood volume for a person of the weight of " << weight << " is " << value << " liters." << std::endl;
			break;
		} else
		{
			std::cout << "Invalid input." << std::endl;
		}
	}
	system("pause");
	return 1;
}