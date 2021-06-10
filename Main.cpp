#include <iostream>
#include <cstdlib>
#include <string_view>
#include <algorithm>

namespace my {
	std::string itostr(const int& val_in, const short unsigned& base) {
		std::string_view dictionary{ "0123456789ABCDEF" };
		std::string result;
		std::div_t div;

		result.reserve(30);
		div.quot = val_in;

		do {
			div = std::div(div.quot, base);
			result += dictionary[std::abs(div.rem)];
		} while (div.quot);

		if (val_in < 0)
			result += '-';

		std::reverse(result.begin(), result.end());

		return result;
	}
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) {
	std::cout << my::itostr(10, 10) << '\n';
	std::cout << my::itostr(10, 2) << '\n';
	std::cout << my::itostr(10, 8) << '\n';
	std::cout << my::itostr(10, 16) << '\n';
	std::cout << my::itostr(638, 2) << '\n';
	std::cout << my::itostr(-638, 2) << '\n';
	std::cout << my::itostr(-638, 16) << '\n';
	std::cout << my::itostr(-638, 8) << '\n';
	std::cout << my::itostr(-638, 10) << '\n';
	std::cout << my::itostr(1054, 2) << '\n';
	std::cout << my::itostr(895, 16) << '\n';

	return EXIT_SUCCESS;
}