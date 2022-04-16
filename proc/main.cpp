#include <iostream>
#include <string>

extern "C" {
#include "a1_connect.h"
}

#include "a2_connect.h"
#include "b1_select.h"
#include "b2_select.h"
#include "b3_select.h"
#include "b4_select_cursor.h"
#include "c1_dml.h"
#include "c2_dml.h"
#include "c3_dml.h"

int main() {
	std::string confirm;
	std::cout << "[A1] C connect [N]? ";
	std::getline(std::cin, confirm);

	if (!confirm.empty()) {
		connect_c();
	}

	std::cout << "[A2] C++ connect [N]? ";
	std::getline(std::cin, confirm);

	if (!confirm.empty()) {
		connect();
	}

	std::cout << "[B1] Select location [N / id (es: 1000)]? ";
	std::getline(std::cin, confirm);

	if (!confirm.empty()) {
		select_a_location(std::stoi(confirm));
	}

	std::cout << "[B2] Select locations from [N / id (es: 1000)]? ";
	std::getline(std::cin, confirm);

	if (!confirm.empty()) {
		select_locations_from(std::stoi(confirm));
	}

	std::cout << "[B3] Select locations (null) from [N / id (es: 1000)]? ";
	std::getline(std::cin, confirm);

	if (!confirm.empty()) {
		select_locations_null_from(std::stoi(confirm));
	}

	std::cout << "[B4] Select locations by cursor [N]? ";
	std::getline(std::cin, confirm);

	if (!confirm.empty()) {
		select_locations();
	}

	std::cout << "[C1] Insert country (then rollback) [N]? ";
	std::getline(std::cin, confirm);

	if (!confirm.empty()) {
		insert_country();
	}

	std::cout << "[C2] Update country (then rollback) [N]? ";
	std::getline(std::cin, confirm);

	if (!confirm.empty()) {
		update_country();
	}

	std::cout << "[C3] Delete country (then rollback) [N]? ";
	std::getline(std::cin, confirm);

	if (!confirm.empty()) {
		delete_country();
	}
}
