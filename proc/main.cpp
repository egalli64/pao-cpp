#include <iostream>
#include <string>

extern "C" {
#include "a1_connect.h"
}

#include "a2_connect.h"
#include "b1_select.h"
#include "b2_select.h"
#include "b3_select.h"
#include "c1_dml.h"

int main() {
	std::string confirm;
	std::cout << "C connect [N]? ";
	std::getline(std::cin, confirm);

	if (!confirm.empty()) {
		connect_c();
	}

	std::cout << "C++ connect [N]? ";
	std::getline(std::cin, confirm);

	if (!confirm.empty()) {
		connect();
	}

	std::cout << "Select location [N / id (es: 1000)]? ";
	std::getline(std::cin, confirm);

	if (!confirm.empty()) {
		select_a_location(std::stoi(confirm));
	}

	std::cout << "Select locations from [N / id (es: 1000)]? ";
	std::getline(std::cin, confirm);

	if (!confirm.empty()) {
		select_locations_from(std::stoi(confirm));
	}

	std::cout << "Select locations (null) from [N / id (es: 1000)]? ";
	std::getline(std::cin, confirm);

	if (!confirm.empty()) {
		select_locations_null_from(std::stoi(confirm));
	}

	std::cout << "Insert country (then rollback) [N]? ";
	std::getline(std::cin, confirm);

	if (!confirm.empty()) {
		insert_country();
	}
}
